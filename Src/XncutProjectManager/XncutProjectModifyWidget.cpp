/*
 * @Author: xixi_
 * @Date: 2025-07-14 17:49:07
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-15 12:37:30
 * @FilePath: /XncutUI/Src/XncutProjectManager/XncutProjectModifyWidget.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutProjectModifyWidget.h"

XncutProjectModifyWidget::XncutProjectModifyWidget(QWidget *Parent)
    : QWidget(Parent)
{                                     /* 主布局 */
    M_MainLayout = new QGridLayout(); /* 网格布局 */

    /* 顶部: 搜索与管理 */
    /* 搜索 */
    M_SearchProjectLineEdit = new QLineEdit();       /* 搜索工程行编辑框 */
    M_SearchProjectButton = new QPushButton();       /* 搜索工程 */
    M_ClearSearchButton = new QPushButton();         /* 清除搜索 */
    M_SortOrderComboBox = new QComboBox();           /* 排序方式 */
    M_SortByComboBox = new QComboBox();              /* 排序依据 */
    M_ImportProjectButton = new QPushButton("导入"); /* 导入工程按钮 */
    /* 管理:危险地带 */
    M_DangerZoneWidget = new QWidget();                /* 危险操作部件 */
    M_DangerZoneLayout = new QHBoxLayout();            /* 危险操作水平布局 */
    M_DeleteProjectButton = new QPushButton("删除");   /* 删除工程按钮 */
    M_CloneProjectButton = new QPushButton("克隆");    /* 克隆工程按钮 */
    M_RenameProjectButton = new QPushButton("重命名"); /* 重命名工程按钮 */
    M_PackProjectButton = new QPushButton("打包");     /* 打包工程按钮 */

    /* 底部:工程视图 */
    M_AllProjectListView = new XncutListView(); /* (全部的)工程视图 */
    /********************************************************************************************************/

    /* 顶部: 搜索与管理 */
    /* 搜索工程行编辑框 */
    M_SearchProjectLineEdit->setPlaceholderText("键入关键词以搜索所有工程...");
    /* 搜索工程 */
    M_SearchProjectButton->setToolTip("搜索工程");
    M_SearchProjectButton->setIconSize(QSize(30, 30));
    M_SearchProjectButton->setIcon(QIcon("://Images/Public/XSearch.png"));
    /* 清除搜索 */
    M_ClearSearchButton->setToolTip("清除搜索");
    M_ClearSearchButton->setIconSize(QSize(30, 30));
    M_ClearSearchButton->setIcon(QIcon("://Images/Public/XClearSearch.png"));
    /* 排序方式 */
    M_SortOrderComboBox->setToolTip("排序方式");
    M_SortOrderComboBox->addItem(QIcon("://Images/Public/XOrderAscend.png"), "升序");
    M_SortOrderComboBox->addItem(QIcon("://Images/Public/XOrderDescend.png"), "降序");
    /* 排序依据 */
    M_SortByComboBox->setToolTip("排序依据");
    M_SortByComboBox->addItem("修改时间");
    M_SortByComboBox->addItem("创建时间");
    M_SortByComboBox->addItem("工程名称");
    M_SortByComboBox->addItem("工程大小");
    /* 管理:危险地带 */
    /* 危险操作部件 */
    M_DangerZoneWidget->setStyleSheet("QWidget:enabled { color: rgba(255, 0, 0, 255); }"  /* 深红色(启用) */
                                      "QWidget:disabled { color: rgba(255, 0, 0, 100); }" /* 浅红色(禁用) */
    );
    M_DangerZoneWidget->setToolTip("对所选的工程进行危险操作");
    M_DangerZoneWidget->setLayout(M_DangerZoneLayout);
    M_DangerZoneWidget->setEnabled(false);

    /* 底部:工程视图 */
    /* (全部的)工程视图 */
    M_AllProjectListView->installEventFilter(this);
    M_AllProjectListView->SetEmptyPixmap("://Images/Public/XEmpty.png", 600);
    M_AllProjectListView->SetEmptyPixmapVisible(true);
    M_AllProjectListView->setContextMenuPolicy(Qt::CustomContextMenu);
    M_AllProjectListView->setEditTriggers(QAbstractItemView::NoEditTriggers); /* 禁止编辑 */
    M_AllProjectListView->setMovement(QListView::Static);                     /* 禁止拖动 */
    M_AllProjectListView->setViewMode(QListView::IconMode);                   /* 网格模式 */
    M_AllProjectListView->setSelectionMode(QListView::SingleSelection);
    /********************************************************************************************************/

    /* 设置布局 */
    /* 危险操作水平布局 */
    M_DangerZoneLayout->setContentsMargins(0, 0, 0, 0);
    M_DangerZoneLayout->setSpacing(4);
    M_DangerZoneLayout->addWidget(M_DeleteProjectButton);
    M_DangerZoneLayout->addWidget(M_CloneProjectButton);
    M_DangerZoneLayout->addWidget(M_RenameProjectButton);
    M_DangerZoneLayout->addWidget(M_PackProjectButton);

    /* 主布局 */
    M_MainLayout->setSpacing(2);
    M_MainLayout->addWidget(new QLabel("搜索工程: "), 0, 0);
    M_MainLayout->addWidget(M_SearchProjectLineEdit, 0, 1);
    M_MainLayout->addWidget(M_SearchProjectButton, 0, 2);
    M_MainLayout->addWidget(M_ClearSearchButton, 0, 3);
    M_MainLayout->addWidget(M_SortOrderComboBox, 0, 4);
    M_MainLayout->addWidget(M_SortByComboBox, 0, 5);
    M_MainLayout->addWidget(M_ImportProjectButton, 0, 6);
    M_MainLayout->addWidget(M_DangerZoneWidget, 0, 7);
    M_MainLayout->addWidget(M_AllProjectListView, 1, 0, 1, 8);
    /********************************************************************************************************/

    setLayout(M_MainLayout);
    /********************************************************************************************************/
}

XncutProjectModifyWidget::~XncutProjectModifyWidget()
{
}
