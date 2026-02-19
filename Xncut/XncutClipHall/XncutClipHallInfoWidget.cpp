/*
 * @Author: xixi_
 * @Date: 2025-07-24 18:32:39
 * @LastEditors: xixi_
 * @LastEditTime: 2026-02-19 16:31:19
 * @FilePath: /Xncut/Xncut/XncutClipHall/XncutClipHallInfoWidget.cpp
 * Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
 */

#include "XncutClipHallInfoWidget.h"
#include <QPainter>

XncutClipHallInfoWidget::XncutClipHallInfoWidget(QWidget *Parent)
    : QWidget(Parent)
{
    /* 初始化 */
    /* 背景 */
    M_InfoBgPixmap = QPixmap(":/Images/ClipHall/ClipHallInfoBg.png");
    /********************************************************************************************************/

    /**
     * 保留旧版,啊啊啊啊啊啊啊啊啊!
     * M_TextEdit->setUndoRedoEnabled(false);
     * M_TextEdit->setPlaceholderText("这里记录你的灵感~");
     * M_TextEdit->setText("所以问题很多时候并不复杂,是你把它想复杂了,是的,因为老一辈在我们小时候总教育我们说要吃得苦中苦,方为人上人时,搞得解决问题要亲自去经历一些困难和复杂的事情一样,但这根本没必要,而当你把问题倒置在你的主观想法之前,摆脱那一些让问题看起来很难的假设,就会发现简单易行的方法层出不穷,就像尝一尝刚买的醋,可以直接喝,但没必要去和面跟包饺子,是的,就像你遇到一些问题,需要专业的知识跟技能,你只要去学习需要的那一部分就行了,没有必要从头开始去学,所以你遇到问题,可能本身并不复杂,只是你脑中把问题复杂化了,所以当你感到无力应对时,你应该停下来多问问自己,也许这事很简单呢");
     **/
    /********************************************************************************************************/
}

XncutClipHallInfoWidget::~XncutClipHallInfoWidget()
{
}

void XncutClipHallInfoWidget::paintEvent(QPaintEvent *Event)
{
    /* 画家 */
    QPainter XncutClipHallInfoWidgetPainter(this);
    QFont Font;
    /********************************************************************************************************/

    /* 参数 */
    Font.setPixelSize(35);
    XncutClipHallInfoWidgetPainter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::LosslessImageRendering);
    XncutClipHallInfoWidgetPainter.setPen(QColor(255, 255, 255, 255));
    XncutClipHallInfoWidgetPainter.setFont(Font);
    XncutClipHallInfoWidgetPainter.setBrush(Qt::NoBrush); /* QColor(2, 3, 20, 255) */
    /********************************************************************************************************/

    /* 背景图是空时不绘制 */
    if (M_InfoBgPixmap.isNull())
    {
        return;
    }
    /********************************************************************************************************/

    /* 计算按比例调整后的高度 */
    int InfoBgPixmapHeight = M_InfoBgPixmap.height() * (width() / (double)M_InfoBgPixmap.width());
    /********************************************************************************************************/

    /* 绘制 */
    XncutClipHallInfoWidgetPainter.drawPixmap(QRect(0, 0, width(), InfoBgPixmapHeight), M_InfoBgPixmap);
    XncutClipHallInfoWidgetPainter.fillRect(QRect(0, InfoBgPixmapHeight, width(), height() - InfoBgPixmapHeight), QColor(3, 2, 14, 255));
    /* 绘制内容 */
    XncutClipHallInfoWidgetPainter.drawText(QRect(15, 0, width() - 30, 60), Qt::AlignLeft | Qt::AlignVCenter, "最新资讯");
    /********************************************************************************************************/
}