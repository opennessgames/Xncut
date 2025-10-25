/*
 * @Author: xixi_
 * @Date: 2025-10-25 13:20:25
 * @LastEditors: xixi_
 * @LastEditTime: 2025-10-25 13:20:38
 * @FilePath: /XncutUI/Test/XncutThreeLayerLayout/MainWindow.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "MainWindow.h"
#include "XncutThreeLayerLayoutWidget.h"
#include <QLabel>
#include <QToolBar>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    XncutThreeLayerLayoutWidget *ThreeLayerLayoutWidget = new XncutThreeLayerLayoutWidget(new QWidget());
    ThreeLayerLayoutWidget->GetTopTitleLabel()->setText("这是一个标题");
    ThreeLayerLayoutWidget->GetBottomToolBar()->addWidget(new QPushButton());
    setCentralWidget(ThreeLayerLayoutWidget);
}

MainWindow::~MainWindow() {}
