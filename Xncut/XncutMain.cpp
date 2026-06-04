/*
 * @Author: xixi_
 * @Date: 2024-07-09 01:42:04
 * @LastEditors: xixi_
 * @LastEditTime: 2026-06-03 17:50:51
 * @FilePath: /Xncut/Xncut/XncutMain.cpp
 * Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
 */

#include <QApplication>
#include "Xncut.h"

int main(int argc, char **argv, char **envp)
{
    /* 初始化 */
    QApplication OpenGameApplication(argc, argv);
    /********************************************************************************************************/

    /* 设置属性 */
    OpenGameApplication.setApplicationVersion("");
    OpenGameApplication.setWindowIcon(QIcon(":/XncutIcon/PubgXncut128x128.png"));
    OpenGameApplication.setApplicationName("Xncut");
    OpenGameApplication.setApplicationDisplayName("openGAME熙柠剪辑");
    /********************************************************************************************************/

    /* 初始化主窗口 */
    Xncut XncutApplication;
    XncutApplication.setWindowTitle("Clip Lobby");
    XncutApplication.show();
    /********************************************************************************************************/

    /* 进入事件循环 */
    return OpenGameApplication.exec();
    /********************************************************************************************************/
}