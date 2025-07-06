/*
 * @Author: xixi_
 * @Date: 2025-07-06 18:25:55
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-06 19:20:37
 * @FilePath: /Xncut/Xncut/XncutProjectManager/XncutProjectManagerWidget.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutProjectManagerWidget.h"

XncutProjectManagerWidget::XncutProjectManagerWidget(QWidget *Parent)
    : QWidget(Parent)
{
    /* 初始化 */
    /* 主布局 */
    M_MainLayout = new QGridLayout(); /* 网格布局 */

    /* 标题 */
    M_TitleLabel = new QLabel("工程管理");                /* 标签 */
    M_ReturnClipHallButton = new QPushButton("返回大厅"); /* 返回大厅按钮 */

    /* 内容部件 */
    M_ContentsTabWidget = new QTabWidget();

    /* 内容 */
    M_ProjectModifyWidget = new XncutProjectModifyWidget(); /* 工程管理 */
    M_ProjectCreateWidget = new XncutProjectCreateWidget(); /* 工程创建 */
    /********************************************************************************************************/

    /* 设置属性 */
    /* 标题 */
    /* 标签 */
    M_TitleLabel->setStyleSheet("font-size:45px;");
    /* 返回大厅按钮 */
    M_ReturnClipHallButton->setFixedSize(150, 50);
    M_ReturnClipHallButton->setStyleSheet("font-size:25px;");

    /* 内容部件 */
    M_ContentsTabWidget->setMovable(true);
    M_ContentsTabWidget->addTab(M_ProjectModifyWidget, "工程管理");
    M_ContentsTabWidget->addTab(M_ProjectCreateWidget, "工程创建");
    /********************************************************************************************************/

    /* 设置布局 */
    /* 主布局 */
    M_MainLayout->addWidget(M_TitleLabel, 0, 0, Qt::AlignLeft);
    M_MainLayout->addWidget(M_ReturnClipHallButton, 0, 1, Qt::AlignRight);
    M_MainLayout->addWidget(M_ContentsTabWidget, 1, 0, 1, 2);
    /********************************************************************************************************/

    setLayout(M_MainLayout);
    /********************************************************************************************************/
}
