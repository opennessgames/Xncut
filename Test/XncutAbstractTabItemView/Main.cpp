/*
 * @Author: xixi_
 * @Date: 2025-10-30 22:02:59
 * @LastEditors: xixi_
 * @LastEditTime: 2025-10-30 22:03:23
 * @FilePath: /XncutUI/Test/XncutAbstractTabItemView/main.cpp
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
    Window.setWindowTitle("抽象标签视图部件");
    Window.show();
    Window.setMinimumSize(QSize(1000, 500));
    /********************************************************************************************************/

    return OpenGameApplication.exec();
    /********************************************************************************************************/
}
