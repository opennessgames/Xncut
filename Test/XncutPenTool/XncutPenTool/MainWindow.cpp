/*
 * @Author: xixi_
 * @Date: 2025-08-10 13:10:51
 * @LastEditors: xixi_
 * @LastEditTime: 2025-09-30 00:12:24
 * @FilePath: /Xncut/Test/XncutPenTool/XncutPenTool/MainWindow.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "MainWindow.h"
/********************************************************************************************************/

#include <QVBoxLayout>
#include <QTabWidget>
#include "XncutPenToolCoreWidget/XncutPenToolWidget.h"
#include "XncutPenToolCoreWidget/XncutPenToolWidget2.h"
#include "XncutPenToolCoreWidget/XncutPenToolWidget3.h"
#include <QLabel>
/********************************************************************************************************/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /* 初始化 */
    /* 中心部件布局 */
    M_CentralWidget = new QWidget();
    M_MainLayout = new QVBoxLayout();

    /* 内容部件 */
    M_AllPenToolTabWidget = new QTabWidget();     /* 所有版本的钢笔工具 */
    M_PenToolWidget = new XncutPenToolWidget();   /* 第一代钢笔工具 */
    M_PenToolWidget2 = new XncutPenToolWidget2(); /* 第二代钢笔工具 */
    M_PenToolWidget3 = new XncutPenToolWidget3(); /* 第三代钢笔工具 */

    /* 底部提示 */
    M_Tips = new QLabel();
    /********************************************************************************************************/

    /* 内容部件 */
    /* 中心部件 */
    M_CentralWidget->setLayout(M_MainLayout);
    /* 所有版本的钢笔工具 */
    M_AllPenToolTabWidget->addTab(M_PenToolWidget, "钢笔工具·壹");
    M_AllPenToolTabWidget->addTab(M_PenToolWidget2, "钢笔工具·贰");
    M_AllPenToolTabWidget->addTab(M_PenToolWidget3, "钢笔工具·叁");
    /* 底部提示 */
    M_Tips->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed));
    M_Tips->setText("食用指南: 点击空白处添加点, 按住左键并移动以绘制贝塞尔曲线, 双击可以删除点, 通过组合可以获取更多操作");
    /********************************************************************************************************/

    /* 设置布局 */
    M_MainLayout->addWidget(M_AllPenToolTabWidget);
    M_MainLayout->addWidget(M_Tips);
    /********************************************************************************************************/

    /* 设置中心部件 */
    setCentralWidget(M_CentralWidget);
    /********************************************************************************************************/
}

MainWindow::~MainWindow() {}
