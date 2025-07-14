/*
 * @Author: xixi_
 * @Date: 2025-07-14 17:27:53
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-14 17:28:08
 * @FilePath: /XncutUI/Src/XncutWelcome/XncutWelcomeScreen.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_WELCOME_SCREEN_H
#define XNCUT_WELCOME_SCREEN_H

#include <QSplashScreen>

class XncutWelcomeScreen : public QSplashScreen
{
    Q_OBJECT
private:
public:
    explicit XncutWelcomeScreen(QObject *Parent = NULL);

private:
private slots:

protected:
    /* 重载事件 */
    /* 鼠标释放事件 */
    void mousePressEvent(QMouseEvent *Event) override;
    /********************************************************************************************************/

signals:
private:
};

#endif // XNCUT_WELCOME_SCREEN_H
