/*
 * @Author: xixi_
 * @Date: 2024-07-09 01:42:04
 * @LastEditors: xixi_
 * @LastEditTime: 2026-10-12 15:52:06
 * @FilePath: /Xncut/Xncut/XncutHost/XncutMain.cpp
 * Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
 */

#include <QApplication>
#include "Xncut.h"

int main(int argc, char **argv, char **envp)
{
    /* App */
    QApplication openGameApplication(argc, argv);
    openGameApplication.setApplicationVersion(PUBG_XNCUT_VERSION);
    openGameApplication.setApplicationName("PUBGXNCUT");
    openGameApplication.setApplicationDisplayName("熙柠剪辑2022");

    /* Xncut */
    Xncut xncutApplication;
    xncutApplication.show();

    /* Exec */
    return QApplication::exec();
}