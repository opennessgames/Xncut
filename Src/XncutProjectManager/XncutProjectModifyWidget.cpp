/*
 * @Author: xixi_
 * @Date: 2025-07-14 17:49:07
 * @LastEditors: xixi_
 * @LastEditTime: 2026-02-04 03:21:53
 * @FilePath: /XncutUI/Src/XncutProjectManager/XncutProjectModifyWidget.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutProjectModifyWidget.h"
#include <QGridLayout>
#include <QToolBar>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include "../XncutPublicWidget/XncutListView.h"

XncutProjectModifyWidget::XncutProjectModifyWidget(QWidget *Parent)
    : QWidget(Parent)
{                                                /* 主布局 */
    QGridLayout *MainLayout = new QGridLayout(); /* 网格布局 */

    /* 顶部: 搜索与管理 */
    M_SearchToolBar = new QToolBar();
    /* 搜索 */
    M_SearchProjectLineEdit = new QLineEdit();       /* 搜索工程行编辑框 */
    M_SearchProjectButton = new QPushButton();       /* 搜索工程 */
    M_ClearSearchButton = new QPushButton();         /* 清除搜索 */
    M_SortOrderComboBox = new QComboBox();           /* 排序方式 */
    M_SortByComboBox = new QComboBox();              /* 排序依据 */
    M_ImportProjectButton = new QPushButton("导入"); /* 导入工程按钮 */

    /* 管理:危险地带 */
    M_DangerZoneToolBar = new QToolBar();              /* 危险操作部件 */
    M_DeleteProjectButton = new QPushButton("删除");   /* 删除工程按钮 */
    M_CloneProjectButton = new QPushButton("克隆");    /* 克隆工程按钮 */
    M_RenameProjectButton = new QPushButton("重命名"); /* 重命名工程按钮 */
    M_PackProjectButton = new QPushButton("打包");     /* 打包工程按钮 */

    /* 底部:工程视图 */
    M_AllProjectListView = new XncutListView(); /* (全部的)工程视图 */
    /********************************************************************************************************/

    QSizePolicy MinAndExpSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);

    /* 顶部: 搜索与管理 */
    M_SearchToolBar->addWidget(M_SearchProjectLineEdit);
    M_SearchToolBar->addWidget(M_SearchProjectButton);
    M_SearchToolBar->addWidget(M_ClearSearchButton);
    M_SearchToolBar->addWidget(M_SortOrderComboBox);
    M_SearchToolBar->addWidget(M_SortByComboBox);
    M_SearchToolBar->addWidget(M_ImportProjectButton);
    M_SearchToolBar->addWidget(M_DangerZoneToolBar);

    /* 搜索工程行编辑框 */
    M_SearchProjectLineEdit->setSizePolicy(QSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum));
    M_SearchProjectLineEdit->setPlaceholderText("键入关键词以搜索所有工程...");
    M_SearchProjectLineEdit->setClearButtonEnabled(true); /* 开启清空按钮 */
    /* 搜索工程 */
    M_SearchProjectButton->setToolTip("搜索工程");
    M_SearchProjectButton->setIconSize(QSize(30, 30));
    M_SearchProjectButton->setIcon(QIcon("://Images/Public/XSearch.png"));
    /* 清除搜索 */
    M_ClearSearchButton->setToolTip("清除搜索");
    M_ClearSearchButton->setIconSize(QSize(30, 30));
    M_ClearSearchButton->setIcon(QIcon("://Images/Public/XClearSearch.png"));
    /* 排序方式 */
    M_SortOrderComboBox->setSizePolicy(MinAndExpSizePolicy);
    M_SortOrderComboBox->setToolTip("排序方式");
    M_SortOrderComboBox->addItem(QIcon("://Images/Public/XOrderAscend.png"), "升序");
    M_SortOrderComboBox->addItem(QIcon("://Images/Public/XOrderDescend.png"), "降序");
    /* 排序依据 */
    M_SortByComboBox->setSizePolicy(MinAndExpSizePolicy);
    M_SortByComboBox->setToolTip("排序依据");
    M_SortByComboBox->addItem("修改时间");
    M_SortByComboBox->addItem("创建时间");
    M_SortByComboBox->addItem("工程名称");
    M_SortByComboBox->addItem("工程大小");

    /* 导入按钮 */
    M_ImportProjectButton->setSizePolicy(MinAndExpSizePolicy);

    /* 管理:危险地带 */
    M_DangerZoneToolBar->setEnabled(false); /* 默认禁用 */
    M_DangerZoneToolBar->layout()->setContentsMargins(0, 0, 0, 0);
    M_DangerZoneToolBar->setSizePolicy(MinAndExpSizePolicy);
    M_DangerZoneToolBar->addWidget(M_DeleteProjectButton);
    M_DangerZoneToolBar->addWidget(M_CloneProjectButton);
    M_DangerZoneToolBar->addWidget(M_RenameProjectButton);
    M_DangerZoneToolBar->addWidget(M_PackProjectButton);

    /* 删除工程按钮 */
    M_DeleteProjectButton->setSizePolicy(MinAndExpSizePolicy);

    /* 克隆工程按钮 */
    M_CloneProjectButton->setSizePolicy(MinAndExpSizePolicy);

    /* 重命名工程按钮 */
    M_RenameProjectButton->setSizePolicy(MinAndExpSizePolicy);

    /* 打包工程按钮 */
    M_PackProjectButton->setSizePolicy(MinAndExpSizePolicy);

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
    /* 主布局 */
    MainLayout->setSpacing(2);
    MainLayout->addWidget(M_SearchToolBar);
    MainLayout->addWidget(M_AllProjectListView);
    /********************************************************************************************************/

    setLayout(MainLayout);
    /********************************************************************************************************/
}

XncutProjectModifyWidget::~XncutProjectModifyWidget()
{
}
