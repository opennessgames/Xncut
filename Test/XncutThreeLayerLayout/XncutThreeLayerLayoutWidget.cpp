/*
 * @Author: xixi_
 * @Date: 2025-10-25 13:21:27
 * @LastEditors: xixi_
 * @LastEditTime: 2025-10-25 13:21:38
 * @FilePath: /XncutUI/Test/XncutThreeLayerLayout/XncutThreeLayerLayoutWidget.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutThreeLayerLayoutWidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QToolBar>

XncutThreeLayerLayoutWidget::XncutThreeLayerLayoutWidget(QWidget *CentralWidget, QWidget *Parent)
    : QWidget(Parent)
{
    /* 初始化 */
    QVBoxLayout *MainLayout = new QVBoxLayout(); /* 主布局 */
    /* 内容部件 */
    M_TopTitleLabel = new QLabel();   /* 顶部标题 */
    M_BottomToolBar = new QToolBar(); /* 底部工具栏 */

    /* 设置属性, 提前设置一些默认属性, 减少一些重复的代码 */
    /* 顶部标题 */
    M_TopTitleLabel->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum)); /* 宽可扩展, 高最小 */
    M_TopTitleLabel->setAutoFillBackground(true);
    M_TopTitleLabel->setPalette(GetTopTitleLabelPalette());
    M_TopTitleLabel->setAlignment(Qt::AlignCenter);
    M_TopTitleLabel->setText("");
    /* 中间部件 */
    CentralWidget->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding)); /* 全部可扩展 */
    /* 底部工具栏 */
    M_BottomToolBar->setMovable(false);
    M_BottomToolBar->setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum)); /* 全部最小 */
    M_BottomToolBar->layout()->setContentsMargins(5, 5, 5, 5);
    /********************************************************************************************************/

    /* 设置布局 */
    MainLayout->setContentsMargins(2, 2, 2, 2);
    MainLayout->setSpacing(2);
    MainLayout->addWidget(M_TopTitleLabel);
    MainLayout->addWidget(CentralWidget); /* 中间部件 */
    MainLayout->addWidget(M_BottomToolBar);
    /********************************************************************************************************/

    setLayout(MainLayout);
    /********************************************************************************************************/
}

XncutThreeLayerLayoutWidget::~XncutThreeLayerLayoutWidget()
{
}

QLabel *XncutThreeLayerLayoutWidget::GetTopTitleLabel()
{
    return M_TopTitleLabel;
}

QToolBar *XncutThreeLayerLayoutWidget::GetBottomToolBar()
{
    return M_BottomToolBar;
}

QPalette XncutThreeLayerLayoutWidget::GetTopTitleLabelPalette()
{
    return QPalette(QColor(0, 0, 0, 255));
}
