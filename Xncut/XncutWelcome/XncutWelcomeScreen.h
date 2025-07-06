/*
 * @Author: xixi_
 * @Date: 2025-07-05 21:10:44
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-05 21:27:11
 * @FilePath: /Xncut/Xncut/XncutWelcome/XncutWelcomeScreen.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_WELCOME_SCREEN_H
#define XNCUT_WELCOME_SCREEN_H

#include <QSplashScreen>

class XncutWelcomeScreen : public QSplashScreen
{
    Q_OBJECT
public:
    explicit XncutWelcomeScreen(QObject *Parent = NULL);

protected:
    /* 重载事件 */
    /* 鼠标释放事件 */
    void mousePressEvent(QMouseEvent *Event) override;
    /********************************************************************************************************/

signals:
};

#endif // XNCUT_WELCOME_SCREEN_H
