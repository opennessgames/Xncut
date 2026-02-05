/*
 * @Author: xixi_
 * @Date: 2026-02-05 23:45:14
 * @LastEditors: xixi_
 * @LastEditTime: 2026-02-06 00:07:52
 * @FilePath: /Xncut/Xncut/XncutMain.cpp
 * Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
 */

#include <QApplication>
#include "Xncut.h"
#include "XncutWelcome/XncutWelcomeScreen.h"

int main(int argc, char **argv)
{
    QApplication OpenGameApplication(argc, argv);
    /********************************************************************************************************/

    OpenGameApplication.setApplicationName("Xncut");
    OpenGameApplication.setApplicationDisplayName("openGAME熙柠剪辑");
    OpenGameApplication.setOverrideCursor(Qt::WaitCursor); /* 等待光标 */
    /********************************************************************************************************/

    /* 初始化一些物品 */
    XncutWelcomeScreen WelcomeScreen(NULL);
    Xncut XncutApplication(NULL);
    /********************************************************************************************************/

    /* 欢迎界面 */
    WelcomeScreen.setFixedSize(QSize(900, 444));
    WelcomeScreen.setPixmap(QPixmap("://Images/Welcome/StartBg.png").scaled(WelcomeScreen.size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    WelcomeScreen.show();

    /* 主窗口 */
    XncutApplication.setWindowTitle("剪辑大厅");
    WelcomeScreen.finish(&WelcomeScreen);
    OpenGameApplication.restoreOverrideCursor(); /* 光标恢复正常 */
    XncutApplication.show();
    /********************************************************************************************************/

    return OpenGameApplication.exec();
    /********************************************************************************************************/
}
