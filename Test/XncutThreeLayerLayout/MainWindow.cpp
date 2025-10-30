/*
 * @Author: xixi_
 * @Date: 2025-10-25 13:20:25
 * @LastEditors: xixi_
 * @LastEditTime: 2025-10-30 23:08:46
 * @FilePath: /XncutUI/Test/XncutThreeLayerLayout/MainWindow.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "MainWindow.h"
#include "XncutThreeLayerLayoutWidget.h"
#include <QLabel>
#include <QToolBar>
#include <QPushButton>

MainWindow::MainWindow(QWidget *Parent)
    : QMainWindow(Parent)
{
    /* 初始化 */
    /* 部件 */
    XncutThreeLayerLayoutWidget *ThreeLayerLayoutWidget = new XncutThreeLayerLayoutWidget(new QWidget());
    /********************************************************************************************************/

    /* 设置属性 */
    /* 部件 */
    ThreeLayerLayoutWidget->GetTopTitleLabel()->setText("这是一个标题");
    ThreeLayerLayoutWidget->GetBottomToolBar()->addWidget(new QPushButton());
    /********************************************************************************************************/

    /* 设置中心部件 */
    setCentralWidget(ThreeLayerLayoutWidget);
    /********************************************************************************************************/
}

MainWindow::~MainWindow()
{
}
