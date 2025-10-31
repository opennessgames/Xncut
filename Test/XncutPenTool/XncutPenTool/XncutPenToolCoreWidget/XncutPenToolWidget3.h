/*
 * @Author: xixi_
 * @Date: 2025-09-27 15:18:51
 * @LastEditors: xixi_
 * @LastEditTime: 2025-10-14 19:19:41
 * @FilePath: /XncutPenTool/XncutPenTool/XncutPenToolCoreWidget/XncutPenToolWidget3.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_PEN_TOOL_WIDGET_3_H
#define XNCUT_PEN_TOOL_WIDGET_3_H

#include <QWidget>

class XncutPenToolWidget3 : public QWidget
{
    Q_OBJECT
private:
    /**
     * @brief 钢笔工具里所有类型
     * @note 我当然知道按照顺序是没有任何问题的, 但是我喜欢这样的枚举值
     **/
    typedef enum
    {
        PEN_TOOL_TYPE_NULL = 3,              /* 未知的类型 */
        PEN_TOOL_TYPE_ANCHOR_POINT = 4,      /* 锚点 */
        PEN_TOOL_TYPE_CONTROL_IN_POINT = 0,  /* 控制入点 */
        PEN_TOOL_TYPE_CONTROL_OUT_POINT = 1, /* 控制出点 */
        PEN_TOOL_TYPE_SEGMENT = 2,           /* 线 */
    } XncutPenToolType;

    /* 一个钢笔点 */
    typedef struct
    {
        QPoint Point;           /* 点 */
        QPoint ControlInPoint;  /* 控制入点 */
        QPoint ControlOutPoint; /* 控制出点 */
        bool IsAltAdjust;       /* 是否通过ALT移动了控制点,如果为true, 两个控制点都退化为普通的锚点 */
        int Index;              /* 索引(保留, 并没有使用) */
    } XncutPenPoint;
    /********************************************************************************************************/

public:
    explicit XncutPenToolWidget3(QWidget *Parent = NULL);
    ~XncutPenToolWidget3();
    /********************************************************************************************************/

    /**
     * @brief 清除所有
     * @note 调用函数时将会清除以下:
     * @note 1. 所有的点
     * @note 2. 选择状态
     * @note 3. 闭合状态
     **/
    void ClearAll();
    /********************************************************************************************************/

    /**
     * @brief 获取所有点的JSON文档
     * @note 保留方法
     **/
    QJsonDocument GetJsonDocument();
    /********************************************************************************************************/

private:
    /* 创建函数 */
    /* 创建钢笔锚点 */
    XncutPenPoint CreatePenAnchorPoint(const QPoint &Point);
    /********************************************************************************************************/

    /* 功能函数 */
    /* 两个点在距离上是否接近(欧几里得距离) */
    bool IsNearPoint(QPoint PointA, QPoint PointB, int Radius = 8);

    /* 获取位置下点的类型 */
    void GetPositionType(QPoint Point);

    /* 获取一个时刻在贝塞尔曲线上的点 */
    QPoint CubicBezierPoint(const QPoint &P0, const QPoint &P1, const QPoint &P2, const QPoint &P3, double t);

    /* 获取某一个点在贝塞尔曲线上的准确位置 */
    bool GetClosestOnCubicBezier(QPoint *DestPoint, const QPoint &P0, const QPoint &P1, const QPoint &P2, const QPoint &P3, const QPoint &P, int Steps = 100);

    /* 插值函数 */
    QPoint Lerp(const QPoint &P1, const QPoint &P2, double t);

    /* 分割一个时刻的贝塞尔曲线 */
    void SplitCubicBezier(const QPoint &P0, const QPoint &P1, const QPoint &P2, const QPoint &P3, double t);
    /********************************************************************************************************/

    /* 绘制函数 */
    /* 绘制三次贝塞尔曲线 */
    void DrawCubicBezier(QPainter *Painter, QPoint StartPoint, QPoint C1, QPoint C2, QPoint EndPoint);

    /* 绘制锚点 */
    void DrawAnchorPoint(QPainter *Painter, XncutPenPoint AnchorPoint, bool Active);

    /* 绘制菱形 */
    void DrawSquare(QPainter *Painter, const QPoint Point, int R, int LineWidth, const QColor FillColor, const QColor EdgeColor);

    /* 绘制控制点 */
    void DrawControlPoint(QPainter *Painter, QPoint ControlPoint, QPoint Point, bool Active);
    /********************************************************************************************************/

private slots:
    /********************************************************************************************************/

protected:
    /* 重载事件 */
    /* 鼠标事件 */
    /* 鼠标按下事件 */
    void mousePressEvent(QMouseEvent *Event) override;

    /* 鼠标释放事件 */
    void mouseReleaseEvent(QMouseEvent *Event) override;

    /* 鼠标双击事件 */
    void mouseDoubleClickEvent(QMouseEvent *Event) override;

    /* 鼠标移动事件 */
    void mouseMoveEvent(QMouseEvent *Event) override;
    /********************************************************************************************************/

    /* 键盘事件 */
    /* 键盘按键按下事件 */
    void keyPressEvent(QKeyEvent *Event) override;

    /* 键盘按键释放事件 */
    void keyReleaseEvent(QKeyEvent *Event) override;
    /********************************************************************************************************/

    /* 绘制事件 */
    void paintEvent(QPaintEvent *Event) override;
    /********************************************************************************************************/

signals:
    /********************************************************************************************************/

private:
    /* 所有的点 */
    QVector<XncutPenPoint> M_AllPoint = {}; /* 点数组 */
    int M_AllPointNumber = -1;              /* 点数量 */
    /********************************************************************************************************/

    /* 点 */
    XncutPenPoint *M_CurrentSelectedPoint = NULL;              /* 当前选中的点 */
    QPoint M_PreviewPoint = QPoint();                          /* 预览点, 会随着鼠标指针而变化 */
    XncutPenToolType M_SelectedPointType = PEN_TOOL_TYPE_NULL; /* 被选择的类型 */
    /********************************************************************************************************/

    /* 辅助插入点 */
    int M_TargetPointIndex = -1;          /* 目标点的下一个索引 */
    QPoint M_CurveTargetPoint = QPoint(); /* 如果鼠标点击到线上, 此点就是记录鼠标附近的点 */
    /********************************************************************************************************/

    /* 标志位 */
    bool M_MouseIsPress = false; /* 鼠标是否被按下 */
    bool M_AltIsPress = false;   /* ALT是否被按下 */
    bool M_IsColse = false;      /* 曲线是否闭合 */
    /********************************************************************************************************/

    /* 样式 */
    /* 锚点样式 */
    int M_AnchorPointRadius = 5;                                /* 锚点半径 */
    int M_AnchorPointCheckThreshold = 6;                        /* 锚点检查阈值(i.e., 锚点半径 + 1) */
    QColor M_AnchorPointEdgetColor = QColor(0, 0, 255, 255);    /* 锚点边缘颜色 */
    QColor M_AnchorPointFillColor = QColor(255, 255, 255, 255); /* 锚点填充颜色 */
    QColor M_AnchorPointActiveColor = QColor(0, 0, 255, 255);   /* 锚点被选中时颜色 */

    /* 曲线样式 */
    int M_CurveWidth = 1;                               /* 曲线宽度 */
    QColor M_CurveColor = QColor(255, 255, 255, 255);   /* 曲线的颜色 */
    QColor M_CurveActiveColor = QColor(0, 0, 255, 255); /* 曲线被选中时颜色 */

    /* 控制点样式 */
    int M_ControlPointRadius = 5;                                /* 控制点半径 */
    int M_ControlPointCheckThreshold = 10;                       /* 控制点检查阈值(是半径的1倍) */
    QColor M_ControlPointEdgetColor = QColor(0, 0, 255, 255);    /* 控制点边缘颜色 */
    QColor M_ControlPointFillColor = QColor(255, 255, 255, 255); /* 控制点填充颜色 */
    QColor M_ControlPointActiveColor = QColor(0, 0, 255, 255);   /* 控制点被选中时颜色 */
    /********************************************************************************************************/
};

#endif // XNCUT_PEN_TOOL_WIDGET_3_H
