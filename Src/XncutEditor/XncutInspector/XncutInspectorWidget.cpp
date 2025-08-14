/*
 * @Author: xixi_
 * @Date: 2025-08-15 02:37:43
 * @LastEditors: xixi_
 * @LastEditTime: 2025-08-15 02:38:29
 * @FilePath: /XncutUI/Src/XncutEditor/XncutInspector/XncutInspectorWidget.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutInspectorWidget.h"

XncutInspectorWidget::XncutInspectorWidget(QWidget *Parent)
    : QWidget(Parent)
{
    /* 初始化 */
    /* 主布局 */
    M_MainLayout = new QVBoxLayout();

    /* 标题标签 */
    M_TitleLabel = new QLabel();

    /* 滚动容器 */
    M_InspectorScrollArea = new QScrollArea();

    /* 内容 */
    M_ProjectArgWidget = new XncutProjectArgWidget(); /* 工程参数 */
    /********************************************************************************************************/

    /* 设置属性 */
    /* 标题标签 */
    M_TitleLabel->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed));
    /* M_TitleLabel->setStyleSheet("background-color:rgb(79,79,79);"); */
    M_TitleLabel->setStyleSheet(""
                                "background-color:rgb(0,0,0);"
                                "");
    M_TitleLabel->setAlignment(Qt::AlignCenter);
    M_TitleLabel->setText(R"(\     检查器     / づ)");

    /* 滚动容器 */
    M_InspectorScrollArea->setWidget(M_ProjectArgWidget);
    M_InspectorScrollArea->setWidgetResizable(true);
    M_InspectorScrollArea->setFrameShape(QFrame::NoFrame);

    /* 内容 */
    /* 工程参数 */
    // M_ProjectArgWidget;
    /********************************************************************************************************/

    /* 设置布局 */
    M_MainLayout->setContentsMargins(3, 3, 3, 3);
    M_MainLayout->setSpacing(3);
    M_MainLayout->addWidget(M_TitleLabel);
    M_MainLayout->addWidget(M_InspectorScrollArea);
    /********************************************************************************************************/

    setLayout(M_MainLayout);
    /********************************************************************************************************/
}

XncutInspectorWidget::~XncutInspectorWidget()
{
}

void XncutInspectorWidget::enterEvent(QEnterEvent *Event)
{
    emit HasShowBottonTipsRequest("检查器: 单选片段时,检查器会显示剪辑属性; 多选时则不显示任何属性; 未选择片段时,则显示工程的属性");
}