/*
 * @Author: xixi_
 * @Date: 2026-02-05 23:45:14
 * @LastEditors: xixi_
 * @LastEditTime: 2026-02-05 23:50:19
 * @FilePath: /Xncut/Xncut/XncutMain.cpp
 * Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
 */

#include <QApplication>
#include "Xncut.h"

int main(int argc, char **argv)
{
    QApplication OpenGameApplication(argc, argv);
    OpenGameApplication.setApplicationName("Xncut");
    OpenGameApplication.setApplicationDisplayName("openGAME熙柠剪辑");
    /********************************************************************************************************/

    Xncut XncutApplication(NULL);
    XncutApplication.setWindowTitle("剪辑大厅");
    XncutApplication.show();
    /********************************************************************************************************/

    return OpenGameApplication.exec();
    /********************************************************************************************************/
}
