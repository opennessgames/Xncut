/*
 * @Author: xixi_
 * @Date: 2025-04-17 16:12:43
 * @LastEditors: xixi_
 * @LastEditTime: 2026-10-14 08:47:23
 * @FilePath: /Xncut/Xncut/XncutWelcome/XncutWelcomeScreen.cpp
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
 */

/* PUBG-XNCUT-0 */
#include "XncutWelcomeScreen.h"
/* QT-1 */
#include <QMouseEvent>
#include <QPainter>

XncutWelcomeScreen::XncutWelcomeScreen(const QPixmap &pixmap)
    : QSplashScreen(pixmap)
{
}

XncutWelcomeScreen::~XncutWelcomeScreen()
{
}

void XncutWelcomeScreen::setProgress(int val)
{
    m_progress = val;
    update();
}

void XncutWelcomeScreen::drawContents(QPainter *painter)
{
    QSplashScreen::drawContents(painter);

    int splashWidth = width();
    int splashHeight = height();

    painter->save();

    /* 绘制进度条背景 */
    int barHeight = 8;
    int barY = splashHeight - barHeight;
    painter->setPen(Qt::NoPen);
    painter->setBrush(QBrush(QColor(0, 0, 0, 150)));
    painter->drawRect(0, barY, splashWidth, barHeight);

    /* 绘制实际进度 */
    int progressWidth = (splashWidth * m_progress) / 100;
    painter->setBrush(QBrush(Qt::green));
    painter->drawRect(0, barY, progressWidth, barHeight);

    painter->restore();
}

void XncutWelcomeScreen::mousePressEvent(QMouseEvent *event)
{
    QPoint mousePos = event->position().toPoint();
    m_pressPos.setX(mousePos.x());
    m_pressPos.setY(mousePos.y());

    /**
     * 忽略掉
     * 如果不忽略, 鼠标点击欢迎屏幕时, 将会消失
     **/
    event->ignore();
}

void XncutWelcomeScreen::mouseMoveEvent(QMouseEvent *event)
{
    /* 移动初始屏幕 */
    move(pos() + (event->pos() - m_pressPos));
}
