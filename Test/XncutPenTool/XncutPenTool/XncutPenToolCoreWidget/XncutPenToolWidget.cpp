/*
 * @Author: xixi_
 * @Date: 2025-08-10 13:13:45
 * @LastEditors: xixi_
 * @LastEditTime: 2025-08-11 03:41:50
 * @FilePath: /Xncut/Test/XncutPenTool/XncutPenToolWidget.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutPenToolWidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QPainterPath>

XncutPenToolWidget::XncutPenToolWidget(QWidget *Parent)
    : QWidget(Parent)
{
    setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);
}

XncutPenToolWidget::~XncutPenToolWidget()
{
}

bool XncutPenToolWidget::IsNearPoint(QPoint PointA, QPoint PointB, int Radius)
{
    return sqrt(pow(PointA.x() - PointB.x(), 2) + pow(PointA.y() - PointB.y(), 2)) < Radius;
}

void XncutPenToolWidget::GetPositionType(QPoint Point)
{
    for (int i = 0; i < M_AllPoint.count(); i++)
    {
        XncutPenPoint CurrPoint = M_AllPoint.at(i);

        if (IsNearPoint(Point, CurrPoint.Point, 5))
        {
            // qDebug() << "锚点" << i;
            M_SelectedPointType = PEN_TOOL_TYPE_ANCHOR_POINT;
            M_CurrentPoint = &M_AllPoint[i];
            return;
        }
        else if (IsNearPoint(Point, CurrPoint.ControlInPoint, 5))
        {
            // qDebug() << "控制入点";
            M_SelectedPointType = PEN_TOOL_TYPE_CONTROL_IN_POINT;
            M_CurrentPoint = &M_AllPoint[i];
            return;
        }
        else if (IsNearPoint(Point, CurrPoint.ControlOutPoint, 5))
        {
            // qDebug() << "控制出点";
            M_SelectedPointType = PEN_TOOL_TYPE_CONTROL_OUT_POINT;
            M_CurrentPoint = &M_AllPoint[i];
            return;
        }
        // else
        // {
        //     for (int i = 0; i < M_AllPoint.count() - 1; i++)
        //     {
        //         XncutPenPoint Start = M_AllPoint[i];
        //         XncutPenPoint End = M_AllPoint[i + 1];

        //         QPoint P0 = Start.Point;
        //         QPoint P1 = Start.ControlInPoint;
        //         QPoint P2 = End.ControlOutPoint;
        //         QPoint P3 = End.Point;
        //     };
        //     return PEN_TOOL_TYPE_SEGMENT;
        // }
    }
    M_SelectedPointType = PEN_TOOL_TYPE_NULL;
}

QPoint XncutPenToolWidget::CubicBezierPoint(const QPoint &P0, const QPoint &P1, const QPoint &P2, const QPoint &P3, double t)
{
    double u = 1 - t;
    double tt = t * t;
    double uu = u * u;
    double uuu = uu * u;
    double ttt = tt * t;

    QPoint result;
    result.setX(uuu * P0.x() + 3 * uu * t * P1.x() + 3 * u * tt * P2.x() + ttt * P3.x());
    result.setY(uuu * P0.y() + 3 * uu * t * P1.y() + 3 * u * tt * P2.y() + ttt * P3.y());
    return result;
}

QPoint XncutPenToolWidget::GetClosestOnCubicBezier(const QPoint &P0, const QPoint &P1, const QPoint &P2, const QPoint &P3, const QPoint &P, int Steps)
{
    for (register_t i = 0; i <= Steps; i++)
    {
        double t = (double)i / Steps;
        QPoint Target = CubicBezierPoint(P0, P1, P2, P3, t);
        double dX = P.x() - Target.x();
        double dY = P.y() - Target.y();
        double Dist = dX * dX + dY * dY;

        if (Dist < 10)
        {
            return Target;
        }
    }

    return QPoint(-1, -1);
}

void XncutPenToolWidget::DrawSquare(QPainter *Painter, const QPoint Point, qreal R, int LineWidth, const QColor FillColor, const QColor StrokeColor)
{
    Painter->save(); // Save the current painter state

    Painter->setPen(QPen(StrokeColor, LineWidth)); // Set the stroke color and width
    Painter->setBrush(FillColor);                  // Set the fill color

    // Move the origin to the point and rotate by 45 degrees
    Painter->translate(Point);
    Painter->rotate(45);

    // Draw the square
    Painter->drawRect(-R, -R, R * 2, R * 2);            // The square is centered on the origin
    Painter->fillRect(-R, -R, R * 2, R * 2, FillColor); // Fill the square with color

    Painter->restore(); // Restore the original painter state
}

void XncutPenToolWidget::DrawControlPoint(QPainter *Painter, QPoint ControlPoint, QPoint Point, bool Active)
{
    if (ControlPoint == QPointF())
    {
        return;
    }

    Painter->save();

    Painter->setPen(QPen(QColor(255, 255, 255, 255), 1));
    Painter->setRenderHint(QPainter::Antialiasing);

    Painter->drawLine(Point, ControlPoint);

    DrawSquare(Painter, ControlPoint, 3, 3, Active ? M_ControlPointActiveColor : M_ControlPointFillColor, M_ControlPointEdgetColor);

    Painter->restore();
}

void XncutPenToolWidget::mousePressEvent(QMouseEvent *Event)
{
    M_MouseIsPress = true;

    if (M_IsColse)
    {
        GetPositionType(Event->pos());
    }
    else
    {
        XncutPenPoint PenPoint = {
            .Point = Event->pos(),
            .ControlInPoint = Event->pos(),
            .ControlOutPoint = Event->pos(),
        };
        M_AllPoint.append(PenPoint);
        M_CurrentPoint = &M_AllPoint.last();
        M_IsDragging = false;

        if (M_AllPoint.count() > 1)
        {
            M_IsColse = IsNearPoint(Event->pos(), M_AllPoint.at(0).Point, 5);
        }
    }
    update();
}

void XncutPenToolWidget::mouseReleaseEvent(QMouseEvent *Event)
{
    M_MouseIsPress = false;
}

void XncutPenToolWidget::mouseDoubleClickEvent(QMouseEvent *Event)
{
    GetPositionType(Event->pos());

    for (int i = 0; i < M_AllPoint.count(); i++)
    {
        QPoint CurrentPoint = M_AllPoint.at(i).Point;
        if (IsNearPoint(CurrentPoint, Event->pos(), 5))
        {
            M_AllPoint.remove(i);
            M_CurrentPoint = NULL;
            break;
        }
    }
}

void XncutPenToolWidget::mouseMoveEvent(QMouseEvent *Event)
{
    QPoint CurrentPos = Event->pos();
    M_PreviewPoint = CurrentPos;

    if (M_MouseIsPress && !M_IsColse)
    {

        QPoint offset = M_CurrentPoint->Point - CurrentPos;

        M_CurrentPoint->ControlInPoint = CurrentPos;
        M_CurrentPoint->ControlOutPoint = M_CurrentPoint->Point + offset;
        M_IsDragging = true;
    }
    else if (M_MouseIsPress)
    {
        switch (M_SelectedPointType)
        {
        case PEN_TOOL_TYPE_ANCHOR_POINT:
        {
            // qDebug() << "锚点";
            XncutPenPoint Curr = *M_CurrentPoint;
            QPoint off = CurrentPos - Curr.Point;
            M_CurrentPoint->Point = QPoint(CurrentPos);
            M_CurrentPoint->ControlInPoint += off;
            M_CurrentPoint->ControlOutPoint += off;
        }
        break;
        case PEN_TOOL_TYPE_CONTROL_IN_POINT:
        {
            if (M_AltIsPress)
            {
                M_CurrentPoint->ControlInPoint = CurrentPos;
            }
            else
            {
                QPoint Off = M_CurrentPoint->Point - CurrentPos;
                M_CurrentPoint->ControlInPoint = CurrentPos;
                M_CurrentPoint->ControlOutPoint = M_CurrentPoint->Point + Off;
            }
        }
        break;
        case PEN_TOOL_TYPE_CONTROL_OUT_POINT:
        {
            // qDebug() << "控制出点";
            if (M_AltIsPress)
            {
                M_CurrentPoint->ControlOutPoint = CurrentPos;
            }
            else
            {
                QPoint Off = CurrentPos - M_CurrentPoint->Point;
                M_CurrentPoint->ControlOutPoint = CurrentPos;
                M_CurrentPoint->ControlInPoint = M_CurrentPoint->Point - Off;
            }
        }
        break;
        default:
            break;
        }
    }

    update();
}

void XncutPenToolWidget::keyPressEvent(QKeyEvent *Event)
{
    if (Event->key() == Qt::Key_Alt)
    {
        M_AltIsPress = true;
    }
}

void XncutPenToolWidget::keyReleaseEvent(QKeyEvent *Event)
{
    if (Event->key() == Qt::Key_Alt)
    {

        M_AltIsPress = false;
    }
}

void XncutPenToolWidget::paintEvent(QPaintEvent *Event)
{
    if (M_AllPoint.isEmpty())
    {
        return;
    }

    QPainter XncutPenToolWidgetPainter(this);
    QPen Pen(QColor(255, 255, 255, 255));

    Pen.setWidth(5);
    XncutPenToolWidgetPainter.setRenderHint(QPainter::Antialiasing);
    XncutPenToolWidgetPainter.setPen(Pen);

    XncutPenPoint Start;
    XncutPenPoint End;
    QPainterPath PainterPath;

    if (M_AllPoint.count() > 1)
    {
        for (register_t i = 0; i < M_AllPoint.count() - 1; i++)
        {
            Start = M_AllPoint[i];
            End = M_AllPoint[i + 1];

            // if (i == 0)
            // {
            //     PainterPath.moveTo(Start.Point.x(), Start.Point.y());
            // }

            PainterPath.moveTo(Start.Point);
            PainterPath.cubicTo(Start.ControlInPoint, End.ControlOutPoint, End.Point);
            XncutPenToolWidgetPainter.drawPath(PainterPath);
        }
    }

    foreach (XncutPenPoint PenPoint, M_AllPoint)
    {
        XncutPenToolWidgetPainter.drawEllipse(PenPoint.Point, 3, 3);
    }

    if (!M_CurrentPoint)
    {
        return;
    }

    if (M_IsDragging || M_IsColse)
    {
        DrawControlPoint(&XncutPenToolWidgetPainter, M_CurrentPoint->ControlInPoint, M_CurrentPoint->Point, false);
        DrawControlPoint(&XncutPenToolWidgetPainter, M_CurrentPoint->ControlOutPoint, M_CurrentPoint->Point, false);
    }

    if (M_IsColse)
    {
        return;
    }

    if (!M_PreviewPoint.isNull() && !M_MouseIsPress && M_CurrentPoint->Point == M_AllPoint.last().Point)
    {
        // qDebug() << M_PreviewPoint;
        PainterPath.moveTo(M_AllPoint.last().Point);
        PainterPath.cubicTo(M_AllPoint.last().ControlInPoint, M_PreviewPoint, M_PreviewPoint);
        XncutPenToolWidgetPainter.drawPath(PainterPath);
    }
}
