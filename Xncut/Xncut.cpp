/*
 * @Author: xixi_
 * @Date: 2023/9/28 12:35:46
 * @LastEditors: xixi_
 * @LastEditTime: 2026-02-19 15:38:03
 * @FilePath: /Xncut/Xncut/Xncut.cpp
 * Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
 */

#include "Xncut.h"
#include <QToolBar>
#include <QLabel>
#include <QLayout>
#include <QStackedWidget>
#include <QStatusBar>

Xncut::Xncut(QWidget *Parent)
    : QMainWindow(Parent)
{
    /* 初始化 */
    /* 主工具栏 */
    QToolBar *MainToolBar = addToolBar("主工具栏");
    M_CurrTitleLabel = new QLabel();
    M_ContainerToolbar = new QToolBar();

    /* 中心堆栈部件 */
    QStackedWidget *M_CentralStackedWidget = new QStackedWidget();

    /* 状态栏 */
    QStatusBar *StatusBar = new QStatusBar();
    /********************************************************************************************************/

    /* 设置属性 */
    /* 主工具栏 */
    MainToolBar->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
    MainToolBar->setMovable(false); /* 固定在窗口上 */
    MainToolBar->addWidget(M_CurrTitleLabel);
    MainToolBar->addWidget(M_ContainerToolbar);
    M_ReturnClipHallAction = MainToolBar->addAction("返回大厅");

    /* 顶部工具栏的标题 */
    QFont CurrTitleLabelFont;
    CurrTitleLabelFont.setPixelSize(25);
    M_CurrTitleLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    M_CurrTitleLabel->setFixedHeight(MainToolBar->height());
    M_CurrTitleLabel->setFont(CurrTitleLabelFont);
    M_CurrTitleLabel->setContentsMargins(15, 0, 0, 0);
    M_CurrTitleLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    M_CurrTitleLabel->setText("剪辑大厅");

    /* 容器工具栏 */
    M_ContainerToolbar->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
    M_ContainerToolbar->layout()->setSpacing(5);

    /* 返回大厅动作 */
    M_ReturnClipHallAction->setIcon(QIcon(":/Images/Public/ReturnHall.png"));
    M_ReturnClipHallAction->setEnabled(false);
    M_ReturnClipHallAction->setStatusTip("返回大厅");

    /* 状态栏 */
    StatusBar->showMessage("作者真名: 姚妤熙", 1700);
    /********************************************************************************************************/

    /* 设置布局 */
    /********************************************************************************************************/

    /* 中心部件 */
    setCentralWidget(M_CentralStackedWidget);
    /* 设置状态栏 */
    setStatusBar(StatusBar);
    /********************************************************************************************************/

    /* 连接信号槽 */
    /********************************************************************************************************/
}

Xncut::~Xncut()
{
}
