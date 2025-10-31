/*
 * @Author: xixi_
 * @Date: 2025-08-10 13:13:45
 * @LastEditors: xixi_
 * @LastEditTime: 2025-08-10 18:08:38
 * @FilePath: /Xncut/Test/XncutPenTool/XncutPenToolWidget.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_PEN_TOOL_WIDGET_H
#define XNCUT_PEN_TOOL_WIDGET_H

#include <QWidget>

class XncutPenToolWidget : public QWidget
{
    Q_OBJECT
private:
    /* 完整的点 */
    typedef struct
    {
        QPoint Point;           /* 点 */
        QPoint ControlInPoint;  /* 控制入点 */
        QPoint ControlOutPoint; /* 控制出点 */
        int Index;              /* 索引 */
    } XncutPenPoint;
    /********************************************************************************************************/

    /* 钢笔工具里所有类型 */
    typedef enum
    {
        PEN_TOOL_TYPE_NULL,
        PEN_TOOL_TYPE_ANCHOR_POINT,      /* 锚点 */
        PEN_TOOL_TYPE_CONTROL_IN_POINT,  /* 控制入点 */
        PEN_TOOL_TYPE_CONTROL_OUT_POINT, /* 控制出点 */
        PEN_TOOL_TYPE_SEGMENT,           /* 线 */
    } XncutPenToolType;

public:
    explicit XncutPenToolWidget(QWidget *Parent = NULL);
    ~XncutPenToolWidget();
    /********************************************************************************************************/

    /********************************************************************************************************/

private:
    /* 两个点在距离上是否接近 */
    bool IsNearPoint(QPoint PointA, QPoint PointB, int Radius = 8);

    /* 获取位置下点的类型 */
    void GetPositionType(QPoint Point);

    QPoint CubicBezierPoint(const QPoint &P0, const QPoint &P1, const QPoint &P2, const QPoint &P3, double t);

    QPoint GetClosestOnCubicBezier(const QPoint &P0, const QPoint &P1, const QPoint &P2, const QPoint &P3, const QPoint &P, int Steps = 100);
    /********************************************************************************************************/

    /* 绘制菱形 */
    void DrawSquare(QPainter *Painter, const QPoint Point, qreal R, int LineWidth, const QColor FillColor, const QColor StrokeColor);

    /* 绘制控制点 */
    void DrawControlPoint(QPainter *Painter, QPoint ControlPoint, QPoint Point, bool Active);
    /********************************************************************************************************/

private slots:
    /********************************************************************************************************/

protected:
    /* 重载事件 */
    /* 鼠标按下事件 */
    void mousePressEvent(QMouseEvent *Event) override;
    /* 鼠标释放事件 */
    void mouseReleaseEvent(QMouseEvent *Event) override;
    /* 鼠标双击事件 */
    void mouseDoubleClickEvent(QMouseEvent *Event) override;
    /* 鼠标移动事件 */
    void mouseMoveEvent(QMouseEvent *Event) override;
    /********************************************************************************************************/

    void keyPressEvent(QKeyEvent *Event) override;

    void keyReleaseEvent(QKeyEvent *Event) override;
    /********************************************************************************************************/

    /* 绘制事件 */
    void paintEvent(QPaintEvent *Event) override;
    /********************************************************************************************************/

signals:
    /********************************************************************************************************/

private:
    /* 所有的点 */
    QVector<XncutPenPoint> M_AllPoint = {};
    /********************************************************************************************************/

    /* 当前点 */
    XncutPenPoint *M_CurrentPoint = NULL;
    QPoint M_PreviewPoint;
    XncutPenToolType M_SelectedPointType = PEN_TOOL_TYPE_NULL; /* 被选择的类型 */

    /* 鼠标是否按下 */
    bool M_MouseIsPress = false;
    bool M_IsDragging = false;
    bool M_IsColse = false;
    bool M_AltIsPress = false;
    /********************************************************************************************************/

    /* 控制点 */
    QColor M_ControlPointEdgetColor = QColor(0, 0, 255, 255);    /* 边缘颜色 */
    QColor M_ControlPointFillColor = QColor(255, 255, 255, 255); /* 填充颜色 */
    QColor M_ControlPointActiveColor = QColor(0, 0, 255, 255);   /* 被选中时颜色 */
    /********************************************************************************************************/
};

#endif // XNCUT_PEN_TOOL_WIDGET_H
