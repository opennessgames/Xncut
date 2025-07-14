/*
 * @Author: xixi_
 * @Date: 2025-07-14 18:18:46
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-14 18:21:49
 * @FilePath: /XncutUI/Src/XncutEditor/XncutEditorWidget.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutEditorWidget.h"

XncutEditorWidget::XncutEditorWidget(QWidget *Parent)
    : QWidget(Parent)
{
    /* 初始化 */
    /* 主布局 */
    M_MainLayout = new QGridLayout();
    M_MainSplitter = new QSplitter(Qt::Vertical);

    /* 标题 */
    M_TitleBarWidget = new XncutTitleBarWidget(); /* 标题栏 */

    /* 内容分裂器 */
    M_TopSplitter = new QSplitter();    /* 顶部(素材 监视器 检查器) 水平 */
    M_BottomSplitter = new QSplitter(); /* 底部(工具 时间线 峰值表) 水平 */

    /* 核心模块 */
    M_BinsWidget = new XncutBinsWidget(); /* 素材箱 */

    /* 底部提示 */
    M_BottomTipsLabel = new QLabel("这是啥?这是啥?这是啥?这是啥?这是啥?这是啥?");
    /********************************************************************************************************/

    /* 设置属性 */
    /* 主分裂器 */
    M_MainSplitter->setChildrenCollapsible(false); /* 如果缩放到最小阻止隐藏 */
    M_MainSplitter->addWidget(M_TopSplitter);
    M_MainSplitter->addWidget(M_BottomSplitter);

    /* 内容分裂器 */
    /* 顶部 */
    M_TopSplitter->setChildrenCollapsible(false);
    M_TopSplitter->addWidget(M_BinsWidget);
    /* 底部 */
    M_BottomSplitter->setChildrenCollapsible(false);

    /* 顶部核心模块 */
    /* 素材箱 */
    M_BinsWidget->setMovable(true);      /* 标签可移动 */
    M_BinsWidget->setMinimumHeight(350); /* 素材箱 */

    /* 底部提示 */
    /********************************************************************************************************/

    /* 设置布局 */
    /* 主布局 */
    M_MainLayout->setContentsMargins(0, 0, 0, 0);
    M_MainLayout->setSpacing(3);
    M_MainLayout->addLayout(M_TitleBarWidget, 0, 0, Qt::AlignTop);
    M_MainLayout->addWidget(M_MainSplitter, 1, 0);
    M_MainLayout->addWidget(M_BottomTipsLabel, 2, 0, Qt::AlignBottom);
    /********************************************************************************************************/

    setLayout(M_MainLayout);
    /********************************************************************************************************/

    /* 连接信号槽 */
    /* 顶部标题栏 */
    connect(M_TitleBarWidget->M_ReturnButton, &QPushButton::clicked, this, &XncutEditorWidget::ReturnButtonClicked);
    /********************************************************************************************************/
}

void XncutEditorWidget::ReturnButtonClicked()
{
    emit HasJmpClipHallRequest();
}
