/*
 * @Author: xixi_
 * @Date: 2025-07-14 17:27:54
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-14 17:28:17
 * @FilePath: /XncutUI/Src/XncutWelcome/XncutWelcomeScreen.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutWelcomeScreen.h"
#include <QMouseEvent>

XncutWelcomeScreen::XncutWelcomeScreen(QObject *Parent)
{
}

void XncutWelcomeScreen::mousePressEvent(QMouseEvent *Event)
{
    /**
     * 忽略掉
     * 如果不忽略,鼠标点击欢迎屏幕时,将会消失
     **/
    Event->ignore();
}