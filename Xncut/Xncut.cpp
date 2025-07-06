/*
 * @Author: xixi_
 * @Date: 2025-07-02 12:35:08
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-05 22:50:26
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
    /* 大厅 */
    M_ClipHallWidget = new XncutClipHallWidget();
    /********************************************************************************************************/

    /* 设置属性 */
    M_CentralStackedWidget->setContentsMargins(20, 20, 20, 20);
    M_CentralStackedWidget->addWidget(M_ClipHallWidget);
    M_CentralStackedWidget->setCurrentWidget(M_ClipHallWidget);
    /********************************************************************************************************/

    /* 设置中心控件 */
    setCentralWidget(M_CentralStackedWidget);
    /********************************************************************************************************/
}

Xncut::~Xncut()
{
}
