/*
 * @Author: xixi_
 * @Date: 2025-08-11 03:42:12
 * @LastEditors: xixi_
 * @LastEditTime: 2025-10-02 11:59:51
 * @FilePath: /Xncut/Test/XncutPenTool/XncutPenTool/XncutPenToolCoreWidget/XncutPenToolWidget2.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutPenToolWidget2.h"
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

XncutPenToolWidget2::XncutPenToolWidget2(QWidget *Parent)
    : QWidget(Parent)
{
    /* 开启一些属性 */
    /* 获取焦点 */
    setFocusPolicy(Qt::StrongFocus);

    /* 开启鼠追(这是必须的) */
    setMouseTracking(true);
}

XncutPenToolWidget2::~XncutPenToolWidget2()
{
}

void XncutPenToolWidget2::ClearAll()
{
    /* 清空所有的点 */
    M_AllPoint.clear();
    M_AllPointNumber = -1;
    /* 清除类型 */
    M_SelectedPointType = PEN_TOOL_TYPE_NULL;
    M_CurrentSelectedPoint = NULL;
    /* 解除闭合 */
    M_IsColse = false;
    /* 更新 */
    update();
}

QJsonDocument XncutPenToolWidget2::GetJsonDocument()
{
    /* 根JSON对象 */
    QJsonObject JsonObject({});

    /* 点JSON数组 */
    QJsonArray JsonArray({});

    /* 逐一追加到列表 */
    for (int i = 0; i < M_AllPointNumber; i++)
    {
        /* 缓存量 */
        XncutPenPoint CurrentPoint = M_AllPoint.at(i);
        QJsonObject PointObject({});

        /* 插入参数 */
        PointObject.insert("XPointX", CurrentPoint.Point.x());
        PointObject.insert("XPointY", CurrentPoint.Point.y());
        PointObject.insert("XInPointX", CurrentPoint.ControlInPoint.x());
        PointObject.insert("XInPointY", CurrentPoint.ControlInPoint.y());
        PointObject.insert("XOutPointX", CurrentPoint.ControlOutPoint.x());
        PointObject.insert("XOutPointY", CurrentPoint.ControlOutPoint.y());
        PointObject.insert("XIsAltAdjust", CurrentPoint.IsAltAdjust);

        /* 追加 */
        JsonArray.append(PointObject);
    }

    /* 插入到文档 */
    JsonObject.insert("XPoints", JsonArray);

    /* 返回 */
    return QJsonDocument(JsonObject);
}

XncutPenToolWidget2::XncutPenPoint XncutPenToolWidget2::CreatePenAnchorPoint(const QPoint &Point)
{
    return (XncutPenPoint){
        .Point = Point,
        .ControlInPoint = Point,
        .ControlOutPoint = Point,
        .IsAltAdjust = false, /* NB!默认是没有通过ALT来移动的 */
    };
}

bool XncutPenToolWidget2::IsNearPoint(QPoint PointA, QPoint PointB, int Radius)
{
    /* 应该避免开平方, 开平方相对来说很消耗资源 */
    int OffestX = PointA.x() - PointB.x();
    int OffestY = PointA.y() - PointB.y();
    return OffestX * OffestX + OffestY * OffestY < Radius * Radius;

    /**
     *  @brief 旧版
     *  return pow(PointA.x() - PointB.x(), 2) + pow(PointA.y() - PointB.y(), 2) < Radius * Radius;
     **/
}

void XncutPenToolWidget2::GetPositionType(QPoint Point)
{
    /**
     *  @brief 检查点
     **/
    for (register_t i = 0; i < M_AllPoint.count(); i++)
    {
        /* 当前的点 */
        XncutPenPoint CurrPoint = M_AllPoint.at(i);

        /* 命中类型 */
        /* 是否为锚点 */
        if (IsNearPoint(Point, CurrPoint.Point, M_AnchorPointCheckThreshold))
        {
            M_SelectedPointType = PEN_TOOL_TYPE_ANCHOR_POINT;
            M_CurrentSelectedPoint = &M_AllPoint[i];
            return;
        }

        /**
         *  不进行控制点检测(可以考虑保留这个特性, 这是个特性)
         *  1. 没有选中任何锚点 (完成)
         *  2. 控制点没有显示出来 (未完成)
         *
         * 阻止条件:
         *  条件1: 没有任何锚点被选中
         *  条件2: 控制点没有显示出来, 考虑保留此特性
         * 这两个条件是或的关系
         **/
        if (!M_CurrentSelectedPoint)
        {
            continue;
        }

        /* 是否为控制入点 */
        if (IsNearPoint(Point, CurrPoint.ControlInPoint, M_ControlPointCheckThreshold))
        {
            M_SelectedPointType = PEN_TOOL_TYPE_CONTROL_IN_POINT;
            M_CurrentSelectedPoint = &M_AllPoint[i];
            return;
        }

        /* 是否为控制出点 */
        if (IsNearPoint(Point, CurrPoint.ControlOutPoint, M_ControlPointCheckThreshold))
        {
            M_SelectedPointType = PEN_TOOL_TYPE_CONTROL_OUT_POINT;
            M_CurrentSelectedPoint = &M_AllPoint[i];
            return;
        }

        /* 检查线段，只在不是最后一个点时检查 */
        if (i < M_AllPoint.count() - 1)
        {
        }
    }

    /**
     * @brief 检查线
     * TODO: 过于冗余的循环, 应该合并
     **/
    for (register_t i = 0; i < M_AllPoint.count() - 1; i++)
    {
        XncutPenPoint Start = M_AllPoint[i];
        XncutPenPoint End = M_AllPoint[i + 1];

        QPoint P0 = Start.Point;
        QPoint P1 = Start.ControlInPoint;
        QPoint P2 = End.ControlOutPoint;
        QPoint P3 = End.Point;

        /* 是否为线, 空点(i.e., 无效的点)时继续 */
        if (!GetClosestOnCubicBezier(&M_CurveTargetPoint, P0, P1, P2, P3, Point))
        {
            continue;
        }

        /* 是线 */
        M_SelectedPointType = PEN_TOOL_TYPE_SEGMENT;
        M_TargetPointIndex = ++i;
        return;
    }

    /* 如果没命中到线上, 也没命中到点上, 需要清除一些状态 */
    M_SelectedPointType = PEN_TOOL_TYPE_NULL;
    M_CurrentSelectedPoint = NULL;
}

QPoint XncutPenToolWidget2::CubicBezierPoint(const QPoint &P0, const QPoint &P1, const QPoint &P2, const QPoint &P3, double t)
{
    /* 缓存量 */
    double u = 1 - t;
    double tt = t * t;
    double uu = u * u;
    double uuu = uu * u;
    double ttt = tt * t;
    double b1 = 3 * uu * t;
    double b2 = 3 * u * tt;

    /* 计算 */
    return QPoint(
        uuu * P0.x() + b1 * P1.x() + b2 * P2.x() + ttt * P3.x(),
        uuu * P0.y() + b1 * P1.y() + b2 * P2.y() + ttt * P3.y());
}

bool XncutPenToolWidget2::GetClosestOnCubicBezier(QPoint *DestPoint, const QPoint &P0, const QPoint &P1, const QPoint &P2, const QPoint &P3, const QPoint &P, int Steps)
{
    for (register_t i = 0; i <= Steps; i++)
    {
        double t = (double)i / Steps;
        QPoint Target = CubicBezierPoint(P0, P1, P2, P3, t);
        if (IsNearPoint(Target, P, 4)) /* 是否在附近 */
        {
            *DestPoint = Target;
            return true;
        }
    }

    /* 空点 */
    *DestPoint = QPoint();
    return false;
}

QPoint XncutPenToolWidget2::Lerp(const QPoint &P1, const QPoint &P2, double t)
{
    return QPoint(
        P1.x() + (P2.x() - P1.x()) * t,
        P1.y() + (P2.y() - P1.y()) * t);
}

void XncutPenToolWidget2::SplitCubicBezier(const QPoint &P0, const QPoint &P1, const QPoint &P2, const QPoint &P3, double t)
{
    /* 第一次线性插值 */
    QPoint a = Lerp(P0, P1, t);
    QPoint b = Lerp(P1, P2, t);
    QPoint c = Lerp(P3, P3, t);

    /* 第二次线性插值 */
    QPoint d = Lerp(a, b, t);
    QPoint e = Lerp(b, c, t);

    /* 第三次线性插值 */
    QPoint f = Lerp(d, e, t);

    qDebug() << P0 << a << d << f;
    qDebug() << f << e << c << P3;
}

void XncutPenToolWidget2::DrawCubicBezier(QPainter *Painter, QPoint StartPoint, QPoint C1, QPoint C2, QPoint EndPoint)
{
    QPainterPath PainterPath;
    PainterPath.moveTo(StartPoint);
    PainterPath.cubicTo(C1, C2, EndPoint);
    Painter->drawPath(PainterPath);
}

void XncutPenToolWidget2::DrawAnchorPoint(QPainter *Painter, XncutPenPoint AnchorPoint, bool Active)
{
    Painter->save(); /* Save the current painter state */

    Painter->setPen(Qt::NoPen);
    Painter->setBrush(QColor(Active ? M_AnchorPointActiveColor : M_AnchorPointFillColor));
    Painter->drawEllipse(AnchorPoint.Point, M_AnchorPointRadius, M_AnchorPointRadius);

    Painter->restore(); /* Restore the original painter state */
}

void XncutPenToolWidget2::DrawSquare(QPainter *Painter, const QPoint Point, int R, int LineWidth, const QColor FillColor, const QColor EdgeColor)
{
    Painter->save(); /* Save the current painter state */

    Painter->setPen(QPen(EdgeColor, LineWidth)); /* Set the stroke color and width */
    Painter->setBrush(FillColor);                /* Set the fill color */

    /* Move the origin to the point and rotate by 45 degrees */
    Painter->translate(Point);
    Painter->rotate(45);

    /* Draw the square */
    Painter->drawRect(-R, -R, R << 1, R << 1);            /* The square is centered on the origin */
    Painter->fillRect(-R, -R, R << 1, R << 1, FillColor); /* Fill the square with color */

    Painter->restore(); /* Restore the original painter state */
}

void XncutPenToolWidget2::DrawControlPoint(QPainter *Painter, QPoint ControlPoint, QPoint Point, bool Active)
{
    Painter->save(); /* Save the current painter state */

    /* 参数 */
    Painter->setPen(QPen(QColor(255, 255, 255, 255), 1));
    Painter->setRenderHint(QPainter::Antialiasing);

    /* 绘制 */
    /* 画线 */
    Painter->drawLine(Point, ControlPoint);
    /* 画菱形 */
    DrawSquare(Painter, ControlPoint, M_ControlPointRadius, M_ControlPointRadius, Active ? M_ControlPointActiveColor : M_ControlPointFillColor, M_ControlPointEdgetColor);

    Painter->restore(); /* Restore the original painter state */
}

/**
 * TODO: 闭合路径优化: 去掉任何操作, 仅修改标志, 绘制时末尾连接开始点(i.e., 容器中索引为0的点)即可
 **/
void XncutPenToolWidget2::mousePressEvent(QMouseEvent *Event)
{
    /* 只有左键处理业务逻辑 */
    if (Event->button() != Qt::LeftButton)
    {
        return;
    }

    /* 缓存 */
    QPoint PressTimePosition = Event->pos(); /* 按下时的位置 */

    /* 是否是闭合的 */
    if (M_IsColse)
    {
        /* 获取命中的类型 */
        GetPositionType(PressTimePosition);
        if (M_SelectedPointType == PEN_TOOL_TYPE_SEGMENT)
        {
            M_AllPoint.insert(M_TargetPointIndex, CreatePenAnchorPoint(M_CurveTargetPoint));
            M_AllPointNumber = M_AllPoint.count();                    /* 数量 */
            M_CurrentSelectedPoint = &M_AllPoint[M_TargetPointIndex]; /* 最好这样 */
        }
    }
    else /* 添加点 */
    {
        M_AllPoint.append(CreatePenAnchorPoint(PressTimePosition)); /* 加入到容器 */
        M_AllPointNumber = M_AllPoint.count();                      /* 数量 */
        M_CurrentSelectedPoint = &M_AllPoint.last();                /* 最好这样 */

        /* 检查是否形成闭合 */
        if (M_AllPointNumber > 1 && IsNearPoint(PressTimePosition, M_AllPoint.first().Point, 5))
        {
            /* 更改标志 */
            M_IsColse = true;

            /* 闭合时修改最后一个点 */
            XncutPenPoint *LastPoint = &M_AllPoint.last();
            const XncutPenPoint &FirstPoint = M_AllPoint.first();
            *LastPoint = FirstPoint;

            /* 解除当前点的指向 */
            M_CurrentSelectedPoint = NULL;
        }

        /* 更新 */
        M_PreviewPoint = PressTimePosition;
    }

    M_MouseIsPress = true; /* 标志 */
    update();              /* 更新 */
}

void XncutPenToolWidget2::mouseReleaseEvent(QMouseEvent *Event)
{
    M_MouseIsPress = false;
}

void XncutPenToolWidget2::mouseDoubleClickEvent(QMouseEvent *Event)
{
    /* 避免在未闭合时删除点 */
    if (!M_IsColse)
    {
        return;
    }

    /* 获取命中类型 */
    GetPositionType(Event->pos());

    /* 不是锚点 */
    if (M_SelectedPointType != PEN_TOOL_TYPE_ANCHOR_POINT)
    {
        return;
    }

    /**
     *  只有是锚点才删除
     *  TODO: 索引优化, 这个难度稍微大一些
     **/
    for (int i = 0; i < M_AllPoint.count(); i++)
    {
        QPoint CurrentPoint = M_AllPoint.at(i).Point;
        if (!IsNearPoint(CurrentPoint, Event->pos(), 5)) /* 未找到点 */
        {
            continue;
        }

        /* 找到了点 */
        M_AllPoint.remove(i);
        M_AllPointNumber -= 1;
        M_CurrentSelectedPoint = NULL;
        update();
        return;
    }
}

/**
 * TODO: 还需优化
 **/
void XncutPenToolWidget2::mouseMoveEvent(QMouseEvent *Event)
{
    /* 判空保护 */
    if (!M_CurrentSelectedPoint)
    {
        return;
    }

    /* 缓存量 */
    QPoint CurrentPos = Event->pos();
    M_PreviewPoint = CurrentPos;

    /**
     *  鼠标是否按下
     *  TODO: 绘制预览线, 但是会产生无用的重绘,仅仅是在闭合路径时关闭鼠追即可 √
     **/
    if (!M_MouseIsPress)
    {
        if (!M_IsColse) /* 避免重复绘制 */
        {
            update();
        }
        return;
    }

    /* 线是否闭合(移动当前两个控制点) */
    if (!M_IsColse)
    {
        /* 偏移 */
        QPoint Offset = M_CurrentSelectedPoint->Point - CurrentPos;

        /* 更新 */
        M_CurrentSelectedPoint->ControlInPoint = CurrentPos;
        M_CurrentSelectedPoint->ControlOutPoint = M_CurrentSelectedPoint->Point + Offset;
        update();
        return;
    }

    /**
     *  分类讨论: 移动点
     *  TODO: 入点和出点可以合并, 再利用布尔的特性, 再二次分类讨论 √
     *  TODO: 需要重复合并代码 √
     **/
    QPoint Offset;
    switch (M_SelectedPointType)
    {
    case PEN_TOOL_TYPE_ANCHOR_POINT: /* 普通锚点 */
    {
        XncutPenPoint Curr = *M_CurrentSelectedPoint;
        Offset = CurrentPos - Curr.Point;
        M_CurrentSelectedPoint->Point = QPoint(CurrentPos);
        M_CurrentSelectedPoint->ControlInPoint += Offset;
        M_CurrentSelectedPoint->ControlOutPoint += Offset;
    }
    break;
    /**
     * ////////////////////////////////////////////////////////////////
     * case PEN_TOOL_TYPE_CONTROL_IN_POINT:
     * case PEN_TOOL_TYPE_CONTROL_OUT_POINT:
     *  业务逻辑;
     *  break;
     * ////////////////////////////////////////////////////////////////
     * vs.
     * ////////////////////////////////////////////////////////////////
     * case PEN_TOOL_TYPE_CONTROL_IN_POINT:
     *  业务逻辑;
     *  break;
     * casr PEN_TOOL_TYPE_CONTROL_OUT_POINT:
     *  业务逻辑;
     *  break;
     * ////////////////////////////////////////////////////////////////
     * 所以, 选择了一个方案, 去掉冗余代码
     **/
    case PEN_TOOL_TYPE_CONTROL_IN_POINT:  /* 控制入点 */
    case PEN_TOOL_TYPE_CONTROL_OUT_POINT: /* 控制出点 */
    {
        /**
         *  二次分类讨论: 根据差值来分配英雄和配角
         *  1 PEN_TOOL_TYPE_CONTROL_IN_POINT
         *  -1 PEN_TOOL_TYPE_CONTROL_OUT_POINT
         **/
        int Dir = (int)(M_SelectedPointType == PEN_TOOL_TYPE_CONTROL_IN_POINT) - (int)(M_SelectedPointType == PEN_TOOL_TYPE_CONTROL_OUT_POINT);

        /* 英雄点 */
        QPoint *HeroControlPoint = (Dir == -1) ? &M_CurrentSelectedPoint->ControlOutPoint : &M_CurrentSelectedPoint->ControlInPoint;

        /* 无论如何, 英雄点是必须要跟随鼠标移动的 */
        *HeroControlPoint = CurrentPos;
        if (M_AltIsPress || M_CurrentSelectedPoint->IsAltAdjust) /* 按下了ALT或者本身就已经通过ALT调整过了 */
        {
            M_CurrentSelectedPoint->IsAltAdjust = true;
            break; /* 这一步就相当于卫语句, 提前跳出并更新, 配角点不会被移动 */
        }
        {
            /* 配角点 */
            QPoint *SupportControlPoint = (Dir == -1) ? &M_CurrentSelectedPoint->ControlInPoint : &M_CurrentSelectedPoint->ControlOutPoint;

            /* 移动配角 */
            Offset = M_CurrentSelectedPoint->Point * Dir - CurrentPos * Dir;
            *SupportControlPoint = M_CurrentSelectedPoint->Point + Offset * Dir;
            break;
        }
    }
    case PEN_TOOL_TYPE_SEGMENT: /* 线 */
        /* 线就忽略掉 */
    default:
        break;
    }

    /* 更新 */
    update();
}

void XncutPenToolWidget2::keyPressEvent(QKeyEvent *Event)
{
    M_AltIsPress = (Event->key() == Qt::Key_Alt);
}

void XncutPenToolWidget2::keyReleaseEvent(QKeyEvent *Event)
{
    switch (Event->key())
    {
    case Qt::Key_Alt:
        M_AltIsPress = false;
        break;
    default:
        /* 忽略掉 */
        Event->ignore();
        break;
    }
}

void XncutPenToolWidget2::paintEvent(QPaintEvent *Event)
{
    /* 提前判空 */
    if (M_AllPointNumber < 0)
    {
        return;
    }

    /* 画家 */
    QPainter XncutPenToolWidgetPainter(this);

    /* 参数 */
    XncutPenToolWidgetPainter.setRenderHint(QPainter::Antialiasing, true);

    /* 绘制 */
    /* 循环合并, 旧版是拆开的 */
    for (register_t i = 0; i < M_AllPointNumber; i++)
    {
        /**
         * @brief 当前遍历到的点 or 在`绘制贝塞尔曲线循环`中的开始点
         * @note 这个点有两个角色
         **/
        XncutPenPoint Point = M_AllPoint.at(i);
        /* 是否被选中 */
        bool Selected = M_CurrentSelectedPoint ? (Point.Point == M_CurrentSelectedPoint->Point) : false;

        /* 绘制贝塞尔曲线 */
        if (i < M_AllPointNumber - 1)
        {
            /* XncutPenPoint Start = CurrentPoint; */
            XncutPenPoint End = M_AllPoint[i + 1];
            DrawCubicBezier(&XncutPenToolWidgetPainter, Point.Point, Point.ControlInPoint, End.ControlOutPoint, End.Point);
        }

        /* 绘制锚点 */
        DrawAnchorPoint(&XncutPenToolWidgetPainter, Point, Selected);

        /* 绘制两个控制点 */
        if (M_CurrentSelectedPoint && (Selected || (i > 1 && M_AllPoint[i - 1].Point == M_CurrentSelectedPoint->Point)))
        {
            DrawControlPoint(&XncutPenToolWidgetPainter, Point.ControlInPoint, Point.Point, Selected && M_SelectedPointType == PEN_TOOL_TYPE_CONTROL_IN_POINT);
            DrawControlPoint(&XncutPenToolWidgetPainter, Point.ControlOutPoint, Point.Point, Selected && M_SelectedPointType == PEN_TOOL_TYPE_CONTROL_OUT_POINT);
        }
    }

    /**
     * @brief 绘制预览线
     * @note 绘制预览线的条件有三个:
     * @param 1. 曲线没有被闭合,
     * @param 2. 有点被选中,
     * @param 3. 当前选中的点是最后一个.
     **/
    if (!M_IsColse && M_CurrentSelectedPoint && M_CurrentSelectedPoint->Point == M_AllPoint.last().Point)
    {
        DrawCubicBezier(&XncutPenToolWidgetPainter, M_AllPoint.last().Point, M_AllPoint.last().ControlInPoint, M_PreviewPoint, M_PreviewPoint);
    }
}
