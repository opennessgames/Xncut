/*
 * @Author: xixi_
 * @Date: 2025-07-14 16:54:37
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-14 17:04:20
 * @FilePath: /XncutUI/Src/Main.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "Xncut.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    /* 启动消息 */
    qDebug() << "Starting PUGB:XNCUT...";
    /********************************************************************************************************/

    /* 初始化 */
    QApplication OpenGameApplication(argc, argv);
    // XncutWelcomeScreen WelcomeScreen(NULL);

    /* 设置属性 */
    OpenGameApplication.setOverrideCursor(Qt::WaitCursor); /* 等待光标 */
    OpenGameApplication.setWindowIcon(QIcon("://Images/Public/XPubgXncut.png"));
    OpenGameApplication.setApplicationName("XncutUI");
    OpenGameApplication.setApplicationVersion("Beta V0.0.1.2020 64Bit");
    OpenGameApplication.setApplicationDisplayName("熙柠剪辑UI");
    /********************************************************************************************************/

    /* 欢迎屏幕 */
    // WelcomeScreen.setPixmap(QPixmap("://Images/Welcome/XStartBg.png").scaled(900, 444, Qt::KeepAspectRatio));
    // WelcomeScreen.showMessage("加载中,请耐心等待...", Qt::AlignBottom | Qt::AlignRight, QColor(255, 255, 255));
    // WelcomeScreen.show();
    /********************************************************************************************************/

    /* 初始化主窗口 */
    Xncut XncutApplication;
    XncutApplication.setWindowTitle("剪辑大厅");
    // WelcomeScreen.finish(&XncutApplication);
    OpenGameApplication.restoreOverrideCursor(); /* 恢复正常 */
    XncutApplication.show();
    /********************************************************************************************************/

    /* 进入事件循环 */
    return OpenGameApplication.exec();
    /********************************************************************************************************/
}
