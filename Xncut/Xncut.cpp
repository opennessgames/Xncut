/*
 * @Author: xixi_
 * @Date: 2025-07-02 12:35:08
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-06 18:47:35
 * @FilePath: /Xncut/Xncut/Xncut.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "Xncut.h"

Xncut::Xncut(QWidget *Parent)
    : QMainWindow(Parent)
{
    /* 初始化 */
    M_CentralStackedWidget = new QStackedWidget();

    /* 核心部件 */
    M_ClipHallWidget = new XncutClipHallWidget();             /* 大厅 */
    M_ProjectManagerWidget = new XncutProjectManagerWidget(); /* 工程管理器 */
    /********************************************************************************************************/

    /* 设置属性 */
    M_CentralStackedWidget->setContentsMargins(20, 20, 20, 20);
    M_CentralStackedWidget->addWidget(M_ClipHallWidget);
    M_CentralStackedWidget->addWidget(M_ProjectManagerWidget);
    M_CentralStackedWidget->setCurrentWidget(M_ProjectManagerWidget);
    /********************************************************************************************************/

    /* 设置中心控件 */
    setCentralWidget(M_CentralStackedWidget);
    /********************************************************************************************************/
}

Xncut::~Xncut()
{
}
