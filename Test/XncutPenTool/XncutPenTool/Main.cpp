/*
 * @Author: xixi_
 * @Date: 2025-08-10 13:10:51
 * @LastEditors: xixi_
 * @LastEditTime: 2025-09-18 20:20:24
 * @FilePath: /Xncut/Test/XncutPenTool/XncutPenTool/Main.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication OpenGameApplication(argc, argv);
    OpenGameApplication.setApplicationName("XncutTestCase");
    OpenGameApplication.setApplicationDisplayName("熙柠剪辑测试案例");
    /********************************************************************************************************/

    MainWindow Window;
    Window.setWindowTitle("简易钢笔工具");
    Window.show();
    Window.setMinimumSize(QSize(1000, 500));
    /********************************************************************************************************/

    return OpenGameApplication.exec();
    /********************************************************************************************************/
}
