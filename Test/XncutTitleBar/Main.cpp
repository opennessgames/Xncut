/*
 * @Author: xixi_
 * @Date: 2025-10-30 23:24:44
 * @LastEditors: xixi_
 * @LastEditTime: 2025-10-30 23:25:05
 * @FilePath: /XncutUI/Test/XncutTitleBar/Main.cpp
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
    Window.setWindowTitle("标题栏");
    Window.show();
    Window.setMinimumSize(QSize(1000, 500));
    /********************************************************************************************************/

    return OpenGameApplication.exec();
    /********************************************************************************************************/
}
