/*
 * @Author: xixi_
 * @Date: 2025-08-15 01:25:54
 * @LastEditors: xixi_
 * @LastEditTime: 2025-08-15 01:26:05
 * @FilePath: /XncutUI/Src/XncutEditor/XncutProjectMonitor/XncutVideoWidget.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutVideoWidget.h"
#include <QPainter>
#include <QPaintEvent>

XncutVideoWidget::XncutVideoWidget(QWidget *Parent)
    : QWidget(Parent)
{
}

XncutVideoWidget::~XncutVideoWidget()
{
}

void XncutVideoWidget::SetBanners(QString Content)
{
    M_BannersContent = Content;
    QSize FontSize = QFontMetrics(M_PainterFont).size(Qt::TextSingleLine, M_BannersContent);
    M_TextWidth = FontSize.width();
    M_TextHeight = FontSize.height();
}

void XncutVideoWidget::SetBannersContentFontSize(int Size)
{
    M_FontSize = Size;
    M_PainterFont.setPointSize(M_FontSize);
}

void XncutVideoWidget::paintEvent(QPaintEvent *Event)
{
    /* 缓存量 */
    QRect Rect = Event->rect(); /* 范围 */
    int Width = Rect.width();   /* 宽度 */
    int Height = Rect.height(); /* 高度 */

    /* 画家 */
    QPainter XncutVideoWidgetPainter(this);

    /* 参数 */
    XncutVideoWidgetPainter.setFont(M_PainterFont);
    XncutVideoWidgetPainter.setPen(Qt::NoPen);
    XncutVideoWidgetPainter.setBrush(QColor(0, 0, 0, 255));

    /* 绘制 */
    XncutVideoWidgetPainter.drawRect(Rect);

    /* 绘制横幅 */
    if (!M_BannersContent.isEmpty())
    {
        /* 局部参数 */
        XncutVideoWidgetPainter.setBrush(QBrush(QColor(255, 0, 0, 110)));
        XncutVideoWidgetPainter.setPen(QPen(QColor(255, 255, 255, 255)));

        /* 绘制 */
        XncutVideoWidgetPainter.drawRect(0, (Height - M_TextHeight) >> 1, Width - 1, M_TextHeight); /* 横幅背景 */
        XncutVideoWidgetPainter.drawText((Width - M_TextWidth) >> 1, (Height + M_FontSize) >> 1, M_BannersContent);
    }
}
