/*
 * @Author: xixi_
 * @Date: 2025-07-05 21:10:44
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-05 21:29:42
 * @FilePath: /Xncut/Xncut/XncutWelcome/XncutWelcomeScreen.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutWelcomeScreen.h"
#include <QMouseEvent>

XncutWelcomeScreen::XncutWelcomeScreen(QObject *Parent)
{
}

void XncutWelcomeScreen::mousePressEvent(QMouseEvent *Event)
{
    /*
     * 忽略掉
     * 如果不忽略,鼠标点击欢迎屏幕时,将会消失
     */
    Event->ignore();
}
