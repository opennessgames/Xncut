/*
 * @Author: xixi_
 * @Date: 2025-07-14 16:54:37
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-14 17:04:15
 * @FilePath: /XncutUI/Src/Xncut.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "Xncut.h"
#include <QCloseEvent>

Xncut::Xncut(QWidget *Parent)
    : QMainWindow(Parent)
{
    /* 初始化 */
    /* 主部件 */
    M_CentralStackedWidget = new QStackedWidget(); /* 中心控件 */

    /* 内容部件 */
    M_ClipHallWidget = new XncutClipHallWidget(); /* 剪辑大厅 */
    /********************************************************************************************************/

    /* 设置属性 */
    M_CentralStackedWidget->setContentsMargins(10, 10, 10, 10);
    M_CentralStackedWidget->addWidget(M_ClipHallWidget);
    M_CentralStackedWidget->setCurrentWidget(M_ClipHallWidget); /* 当前为大厅 */
    /********************************************************************************************************/

    /* 设置中心控件 */
    setCentralWidget(M_CentralStackedWidget);
    /********************************************************************************************************/
}

Xncut::~Xncut()
{
    /* 结束 */
    qDebug() << "Exit PUGB:XNCUT...";
}

void Xncut::closeEvent(QCloseEvent *Event)
{
}
