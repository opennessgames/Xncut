/*
 * @Author: xixi_
 * @Date: 2025-10-30 23:24:44
 * @LastEditors: xixi_
 * @LastEditTime: 2025-10-30 23:31:55
 * @FilePath: /XncutUI/Test/XncutTitleBar/MainWindow.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "MainWindow.h"
#include <QVBoxLayout>
#include "XncutTitleBarWidget.h"
#include <QToolBar>
#include <QMenuBar>
#include <QPushButton>

MainWindow::MainWindow(QWidget *Parent)
    : QMainWindow(Parent)
{
    /* 初始化 */
    /* 中心控件 */
    QWidget *Widget = new QWidget();
    QVBoxLayout *VBoxLayout = new QVBoxLayout(Widget);

    /* 标题栏 */
    XncutTitleBarWidget *TitleBarWidget = new XncutTitleBarWidget();
    /* 菜单栏 */
    QMenuBar *MenuBar = new QMenuBar();
    /********************************************************************************************************/

    /* 设置属性 */
    /* 标题栏 */
    TitleBarWidget->setFixedHeight(30);
    TitleBarWidget->SetLogoPixmap(QPixmap(""));
    TitleBarWidget->GetToolBar()->addWidget(MenuBar);
    /* 通过GetToolBar方法, 如您所见, 这样连接信号槽也很方便 */
    TitleBarWidget->GetToolBar()->addWidget(new QPushButton("最小化窗口"));
    TitleBarWidget->GetToolBar()->addWidget(new QPushButton("最大化窗口"));
    TitleBarWidget->GetToolBar()->addWidget(new QPushButton("关闭窗口"));
    /* 菜单栏 */
    MenuBar->addMenu("测试1");
    /********************************************************************************************************/

    /* 设置布局 */
    VBoxLayout->addWidget(TitleBarWidget);
    VBoxLayout->addWidget(new QWidget());
    /********************************************************************************************************/

    /* 设置中心部件 */
    setCentralWidget(Widget);
    /********************************************************************************************************/
}

MainWindow::~MainWindow()
{
}
