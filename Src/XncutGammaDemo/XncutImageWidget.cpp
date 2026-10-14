/*
 * @Author: xixi_
 * @Date: 2026-07-25 22:58:16
 * @LastEditors: xixi_
 * @LastEditTime: 2026-10-04 01:28:22
 * @FilePath: /Xncut/Src/XncutGammaDemo/XncutImageWidget.cpp
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
 */

#include "XncutImageWidget.h"
#include <QPainter>

XncutImageWidget::XncutImageWidget(QWidget *parent)
    : QWidget(parent)
{
}

XncutImageWidget::~XncutImageWidget()
{
}

void XncutImageWidget::setImages(const QImage &img)
{
    m_img = img;
    update();
}

void XncutImageWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if (m_img.isNull())
    {
        QFont f = painter.font();
        f.setPixelSize(17);
        painter.setFont(f);
        painter.drawText(rect(), Qt::AlignCenter, "No file loaded.", NULL);
    }
    else
    {
        painter.drawImage(rect(), m_img);
    }
}
