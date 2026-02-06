/*
 * @Author: xixi_
 * @Date: 2026-02-05 23:45:14
 * @LastEditors: xixi_
 * @LastEditTime: 2026-02-06 11:46:55
 * @FilePath: /Xncut/Xncut/XncutMain.cpp
 * Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
 */

#include <QApplication>
#include "Xncut.h"
#include "XncutWelcome/XncutWelcomeScreen.h"
#include "XncutWelcome/XncutBootloader.h"

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
    XncutBootloader Bootloader(&XncutApplication);
    /********************************************************************************************************/

    /* 欢迎界面 */
    WelcomeScreen.setFixedSize(QSize(900, 444));
    WelcomeScreen.setPixmap(QPixmap("://Images/Welcome/StartBg.png").scaled(WelcomeScreen.size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    WelcomeScreen.show();

    /* 优先连接信号槽 */
    OpenGameApplication.connect(&Bootloader, &XncutBootloader::ProgressChanged, &WelcomeScreen, [&WelcomeScreen](QString Msg)
    {
        WelcomeScreen.showMessage(Msg, Qt::AlignBottom | Qt::AlignRight, QColor(77, 38, 137, 255));
    });
    OpenGameApplication.connect(&Bootloader, &XncutBootloader::finished, &XncutApplication, [&OpenGameApplication, &WelcomeScreen, &Bootloader, &XncutApplication]()
    {
        WelcomeScreen.finish(&XncutApplication);
        XncutApplication.setWindowTitle("剪辑大厅");
        OpenGameApplication.restoreOverrideCursor();       /* 光标恢复正常 */
        XncutApplication.show();                           /* 显示主界面 */
        OpenGameApplication.disconnect(&Bootloader, &XncutBootloader::finished, NULL, NULL);
    });
    /********************************************************************************************************/

    /* 开始在后台加载 */
    Bootloader.start();
    /********************************************************************************************************/

    return OpenGameApplication.exec();
    /********************************************************************************************************/
}
