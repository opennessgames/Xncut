/*
 * @Author: xixi_
 * @Date: 2025-10-30 22:02:59
 * @LastEditors: xixi_
 * @LastEditTime: 2025-10-30 22:24:07
 * @FilePath: /XncutUI/Test/XncutAbstractTabItemView/MainWindow.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "MainWindow.h"
#include "XncutMyAssetsWidget.h"
#include "QListView"

MainWindow::MainWindow(QWidget *Parent)
    : QMainWindow(Parent)
{
    XncutAbstractTabItemViewWidget *ViewWidget = new XncutMyAssetsWidget();
    setCentralWidget(ViewWidget);
}

MainWindow::~MainWindow()
{
}
