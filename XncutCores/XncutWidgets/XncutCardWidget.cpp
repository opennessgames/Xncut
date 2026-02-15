/*
 * @Author: xixi_
 * @Date: 2025-12-06 20:44:24
 * @LastEditors: xixi_
 * @LastEditTime: 2026-02-15 13:34:53
 * @FilePath: /Xncut/XncutCores/XncutWidgets/XncutCardWidget.cpp
 * Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
 */

#include "XncutCardWidget.h"
#include <QVariantAnimation>
#include <QGraphicsDropShadowEffect>
#include <QPainter>
#include <QPainterPath>
#include <QPushButton>
#include <QMouseEvent>

XncutCardWidget::XncutCardWidget(QString MainText, QString Subtext, QWidget *Parent)
    : QWidget(Parent)
{
    /* 初始化 */
    /* 缩放动画 */
    M_ScaleAnimation = new QVariantAnimation();
    /* 正副文本 */
    M_MainText = MainText;
    M_Subtext = Subtext;
    /* 阴影效果 */
    QGraphicsDropShadowEffect *ShadowEffect = new QGraphicsDropShadowEffect(this);
    /********************************************************************************************************/

    /* 设置属性 */
    /* 缩放动画 */
    M_ScaleAnimation->setDuration(200);
    M_ScaleAnimation->setStartValue(1.0);
    M_ScaleAnimation->setEndValue(1.2);
    M_ScaleAnimation->setEasingCurve(QEasingCurve::OutCubic);
    /* 阴影效果 */
    ShadowEffect->setBlurRadius(15);
    ShadowEffect->setOffset(0, 4);
    ShadowEffect->setColor(QColor(50, 50, 50, 150));
    /********************************************************************************************************/

    setGraphicsEffect(ShadowEffect);
    /********************************************************************************************************/

    /* 连接信号槽 */
    connect(M_ScaleAnimation, &QVariantAnimation::valueChanged, this, &XncutCardWidget::ScaleAnimationValueChanged);
    /********************************************************************************************************/
}

XncutCardWidget::~XncutCardWidget()
{
    delete M_ScaleAnimation;
    M_ScaleAnimation = NULL;
}

void XncutCardWidget::SetImage(const QString &Path)
{
    M_Pixmap = QPixmap(Path);
    update();
}

void XncutCardWidget::ScaleAnimationValueChanged(const QVariant &Value)
{
    M_ScaleFactor = Value.toReal();
    update();
}

void XncutCardWidget::paintEvent(QPaintEvent *Event)
{
    /* 画家 */
    QPainter CardWidgetPainter(this);
    QRectF Rect = rect().adjusted(4, 4, -4, -4);
    QPainterPath ClipPath;

    ClipPath.addRoundedRect(Rect, 8, 8);

    /* 参数 */
    CardWidgetPainter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::LosslessImageRendering);
    CardWidgetPainter.setClipPath(ClipPath);

    /* 缩放绘制图片部分（保持动画效果）*/
    CardWidgetPainter.save();
    QPointF CenterPoint = Rect.center();
    CardWidgetPainter.translate(CenterPoint);
    CardWidgetPainter.scale(M_ScaleFactor, M_ScaleFactor);
    CardWidgetPainter.translate(-CenterPoint);
    if (!M_Pixmap.isNull())
    {
        CardWidgetPainter.drawPixmap(Rect.toRect(), M_Pixmap);
    }
    CardWidgetPainter.restore();

    /* 动态计算遮罩高度（27%控件高）*/
    const double MaskHeightRatio = 0.27;
    const int MaskHeight = (int)(Rect.height() * MaskHeightRatio);
    QRectF MaskRect(Rect.left(), Rect.bottom() - MaskHeight, Rect.width(), MaskHeight);
    /* 渐变 */
    QLinearGradient LinearGradient(MaskRect.topLeft(), MaskRect.bottomLeft());
    LinearGradient.setColorAt(0.0, QColor(0, 0, 0, 30));
    LinearGradient.setColorAt(1.0, QColor(0, 0, 0, 160));
    /* 画家参数 */
    CardWidgetPainter.setPen(Qt::NoPen);
    CardWidgetPainter.setBrush(LinearGradient);
    CardWidgetPainter.drawRect(MaskRect);
    /* 文字绘制 */
    CardWidgetPainter.setPen(Qt::white);
    QFont Font = CardWidgetPainter.font();
    Font.setPointSize(10);
    Font.setBold(true);
    CardWidgetPainter.setFont(Font);
    CardWidgetPainter.drawText(MaskRect.adjusted(8, 4, -8, -MaskHeight >> 1), Qt::AlignLeft | Qt::AlignVCenter, M_MainText);
    CardWidgetPainter.drawText(MaskRect.adjusted(8, (MaskHeight >> 1) - 4, -8, -5), Qt::AlignLeft | Qt::AlignVCenter, M_Subtext);
}

void XncutCardWidget::mousePressEvent(QMouseEvent *Event)
{
    Event->ignore();
}

void XncutCardWidget::mouseReleaseEvent(QMouseEvent *Event)
{
    /* 如果释放的位置不再范围内部 或者 不是鼠标的左键 就不发射信号 */
    if (!rect().contains(Event->position().toPoint(), false) || Event->button() != Qt::LeftButton)
    {
        Event->ignore();
        return;
    }

    /* 发射信号 */
    emit Clicked();
}

void XncutCardWidget::enterEvent(QEnterEvent *Event)
{
    (void)Event;
    M_ScaleAnimation->setDirection(QAbstractAnimation::Forward);
    M_ScaleAnimation->start();
}

void XncutCardWidget::leaveEvent(QEvent *Event)
{
    (void)Event;
    M_ScaleAnimation->setDirection(QAbstractAnimation::Backward);
    M_ScaleAnimation->start();
}