/*
 * @Author: xixi_
 * @Date: 2025-07-02 12:35:08
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-06 22:12:45
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
    M_CentralStackedWidget->setContentsMargins(10, 10, 10, 10);
    M_CentralStackedWidget->addWidget(M_ClipHallWidget);
    M_CentralStackedWidget->addWidget(M_ProjectManagerWidget);
    M_CentralStackedWidget->setCurrentWidget(M_ClipHallWidget);
    /********************************************************************************************************/

    /* 设置中心控件 */
    setCentralWidget(M_CentralStackedWidget);
    /********************************************************************************************************/

    /* 连接信号槽 */
    /* 剪辑大厅 */
    connect(M_ClipHallWidget, &XncutClipHallWidget::HasJmpProjectManagerRequest, this, &Xncut::JmpProjectManager);
    connect(M_ClipHallWidget, &XncutClipHallWidget::HasJmpEditorRequest, this, &Xncut::JmpEditor);
    /* 工程管理器 */
    connect(M_ProjectManagerWidget, &XncutProjectManagerWidget::HasJmpClipHallRequest, this, &Xncut::JmpHall);
    /********************************************************************************************************/
}

Xncut::~Xncut()
{
    qDebug() << "Exit PUGB:XNCUT...";
}

void Xncut::JmpHall()
{
    M_CentralStackedWidget->setCurrentWidget(M_ClipHallWidget);
    setWindowTitle("剪辑大厅");
}

void Xncut::JmpProjectManager()
{
    M_CentralStackedWidget->setCurrentWidget(M_ProjectManagerWidget);
    setWindowTitle("工程管理");
}

void Xncut::JmpEditor()
{
}

void Xncut::closeEvent(QCloseEvent *Event)
{
    /* 窗口是否被修改 */
    if (isWindowModified())
    {
    }
}
