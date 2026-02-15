/*
 * @Author: xixi_
 * @Date: 2025-04-17 16:12:43
 * @LastEditors: xixi_
 * @LastEditTime: 2026-02-15 13:37:25
 * @FilePath: /Xncut/Xncut/XncutWelcome/XncutWelcomeScreen.cpp
 * Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
 */

#include "XncutWelcomeScreen.h"
#include <QMouseEvent>

XncutWelcomeScreen::XncutWelcomeScreen(QObject *Parent)
{
    setMouseTracking(false);
}

void XncutWelcomeScreen::mousePressEvent(QMouseEvent *Event)
{
    /**
     * 忽略掉
     * 如果不忽略,鼠标点击欢迎屏幕时,将会消失
     **/
    Event->ignore();
}

/* 鼠标移动事件 */
void XncutWelcomeScreen::mouseMoveEvent(QMouseEvent *Event)
{
    Event->ignore();
}