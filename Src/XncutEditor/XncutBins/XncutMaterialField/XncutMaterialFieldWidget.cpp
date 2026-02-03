/*
 * @Author: xixi_
 * @Date: 2025-07-14 18:51:23
 * @LastEditors: xixi_
 * @LastEditTime: 2026-02-04 02:28:38
 * @FilePath: /XncutUI/Src/XncutEditor/XncutBins/XncutMaterialField/XncutMaterialFieldWidget.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutMaterialFieldWidget.h"

XncutMaterialFieldWidget::XncutMaterialFieldWidget(QWidget *Parent)
    : QWidget(Parent)
{
    /* 初始化 */
    /* 主布局 */
    QGridLayout *MainLayout = new QGridLayout();

    /* 素材类型标签 */
    M_MaterialTypeTabBar = new QTabBar();

    /* 右侧视图 */
    /* 顶部搜索栏 */
    M_SearchLineEdit = new QLineEdit();                                                      /* 行编辑框 */
    M_ClearSearchButton = new QPushButton(QIcon("://Images/Public/XClearSearch.png"), "");   /* 清除搜索按钮 */
    M_ImportMaterialButton = new QPushButton(QIcon("://Images/Public/XImport.png"), "导入"); /* 导入素材按钮 */
    M_ImportTimeComboBox = new QComboBox();                                                  /* 素材排序依据 */
    M_ViewModeComboBox = new QComboBox();                                                    /* 显示模式 */

    /* 视图模型 */
    M_MaterialView = new XncutListView(); /* 素材视图 */
    /********************************************************************************************************/

    /* 设置属性 */
    /* 类型标签 */
    M_MaterialTypeTabBar->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Ignored)); /* 大小策略: 宽固定,高忽略掉 */
    M_MaterialTypeTabBar->setExpanding(false);                                                  /* 不扩展 */
    M_MaterialTypeTabBar->setShape(QTabBar::RoundedWest);                                       /* 标签在左侧 */
    M_MaterialTypeTabBar->addTab("全部");
    M_MaterialTypeTabBar->addTab("视频");
    M_MaterialTypeTabBar->addTab("音频");
    M_MaterialTypeTabBar->addTab("图片");
    M_MaterialTypeTabBar->addTab("字体");
    M_MaterialTypeTabBar->addTab("配置");
    M_MaterialTypeTabBar->addTab("源");

    /* 搜索栏 */
    M_SearchLineEdit->setPlaceholderText("键入关键词以搜索素材...");
    /* 清除搜索按钮 */
    M_ClearSearchButton->setIconSize(QSize(30, 30));
    M_ClearSearchButton->setToolTip("清除搜索");
    /* 导入素材按钮 */
    M_ImportMaterialButton->setIconSize(QSize(30, 30));
    /* 导入时间 */
    M_ImportTimeComboBox->setToolTip("素材排序依据");
    /* 显示模式 */
    M_ViewModeComboBox->setToolTip("视图模式");
    M_ViewModeComboBox->setIconSize(QSize(25, 25));
    M_ViewModeComboBox->addItem(QIcon("://Images/Editor/Bins/MaterialField/GridView.png"), "网格视图");
    M_ViewModeComboBox->addItem(QIcon("://Images/Editor/Bins/MaterialField/ListView.png"), "列表视图");

    /* 视图模型 */
    /* 素材视图 */
    M_MaterialView->SetEmptyPixmap("://Images/Public/XEmpty.png", 350);
    /********************************************************************************************************/

    /* 设置布局 */
    /* 主布局 */
    MainLayout->addWidget(M_MaterialTypeTabBar, 0, 0, 4, 1);
    MainLayout->addWidget(M_SearchLineEdit, 0, 1, 1, 1);
    MainLayout->addWidget(M_ClearSearchButton, 0, 2, 1, 1);
    MainLayout->addWidget(M_ImportTimeComboBox, 0, 3, 1, 1);
    MainLayout->addWidget(M_ViewModeComboBox, 0, 4, 1, 1);
    MainLayout->addWidget(M_MaterialView, 1, 1, 3, 4);
    /********************************************************************************************************/

    setLayout(MainLayout);
    /********************************************************************************************************/
}

QTabBar *XncutMaterialFieldWidget::GetTabBar()
{
    return M_MaterialTypeTabBar;
}
