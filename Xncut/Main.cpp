/*
 * @Author: xixi_
 * @Date: 2025-07-02 12:34:42
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-07 23:10:30
 * @FilePath: /Xncut/Xncut/Main.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "Xncut.h"
#include <QApplication>
#include "XncutCore/XncutRunTimeContext.h"

int main(int argc, char *argv[])
{
    /* 启动消息 */
    qDebug() << "Starting PUGB:XNCUT...";
    /********************************************************************************************************/

    /* 初始化 */
    QApplication OpenGameApplication(argc, argv);
    XncutRunTimeContext RunTimeContext(getenv("PUBG_XNCUT_WORKING_PATH")); /* 构造上下文 */

    /* 设置属性 */
    OpenGameApplication.setWindowIcon(QIcon("://Images/Public/XPubgXncut.png"));
    OpenGameApplication.setApplicationName("Xncut");
    OpenGameApplication.setApplicationVersion("Beta V0.0.1.2020 64Bit");
    OpenGameApplication.setApplicationDisplayName("熙柠剪辑");
    /********************************************************************************************************/

    /* 初始化主窗口 */
    Xncut XncutApplication;
    XncutApplication.setWindowTitle("剪辑大厅");
    XncutApplication.SyncConfigToUI();
    XncutApplication.show();
    /********************************************************************************************************/

    /* 进入事件循环 */
    return OpenGameApplication.exec();
    /********************************************************************************************************/
}
