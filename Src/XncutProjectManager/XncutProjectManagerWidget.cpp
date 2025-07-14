/*
 * @Author: xixi_
 * @Date: 2025-07-14 17:41:18
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-14 18:16:35
 * @FilePath: /XncutUI/Src/XncutProjectManager/XncutProjectManagerWidget.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutProjectManagerWidget.h"

XncutProjectManagerWidget::XncutProjectManagerWidget(QWidget *Parent)
    : QWidget(Parent)
{
    /* 日志 */
    qDebug() << "Init Project manager";
    /********************************************************************************************************/

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

    /* 底部提示 */
    M_BottomLabel = new QLabel("工程管理: 鼠标单击工程以获取管理选项, 右键获取更多选项; 双击以选择工程, 无效的工程不能被选择");
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
    M_ContentsTabWidget->setCurrentIndex(0);

    /* 内容 */
    /* 底部提示 */
    /* 工程管理 */
    M_ProjectModifyWidget->setProperty("XTips", "工程管理: 鼠标单击工程以获取管理选项, 右键获取更多选项; 双击以选择工程, 无效的工程不能被选择");
    /* 工程创建 */
    M_ProjectCreateWidget->setProperty("XTips", "工程创建: 输入工程名称, 点击创建按钮以创建新工程; 创建前可以设置一些参数");

    /* 底部提示 */
    M_BottomLabel->adjustSize();
    /********************************************************************************************************/

    /* 设置布局 */
    /* 主布局 */
    M_MainLayout->addWidget(M_TitleLabel, 0, 0, Qt::AlignLeft);
    M_MainLayout->addWidget(M_ReturnClipHallButton, 0, 1, Qt::AlignRight);
    M_MainLayout->addWidget(M_ContentsTabWidget, 1, 0, 1, 2);
    M_MainLayout->addWidget(M_BottomLabel, 2, 0, 1, 2);
    /********************************************************************************************************/

    setLayout(M_MainLayout);
    /********************************************************************************************************/

    /* 连接信号槽 */
    /* 返回大厅按钮被点击 */
    connect(M_ReturnClipHallButton, &QPushButton::clicked, this, &XncutProjectManagerWidget::ReturnClipHallButtonClicked);
    /********************************************************************************************************/

    /* 日志 */
    qDebug() << "Init Project manager finish";
    /********************************************************************************************************/
}

void XncutProjectManagerWidget::ReturnClipHallButtonClicked()
{
    emit HasJmpClipHallRequest();
}
