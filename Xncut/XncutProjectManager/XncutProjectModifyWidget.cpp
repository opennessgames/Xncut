/*
 * @Author: xixi_
 * @Date: 2025-07-06 19:05:20
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-08 23:02:25
 * @FilePath: /Xncut/Xncut/XncutProjectManager/XncutProjectModifyWidget.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutProjectModifyWidget.h"
#include <QEvent>
#include <QMouseEvent>

XncutProjectModifyWidget::XncutProjectModifyWidget(QWidget *Parent)
    : QWidget(Parent)
{
    /* 主布局 */
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
    M_AllProjectListView = new XncutListView();                     /* (全部的)工程视图 */
    M_ProjectCardDelegate = new XncutProjectCardDelegate();         /* 委托 */
    M_AllProjectModel = new QStandardItemModel();                   /*  (全部的)工程视图模型 */
    M_AllProjectSortFilterProxyModel = new QSortFilterProxyModel(); /* (全部的)工程过滤代理模型 */

    /* 所有工程列表右键菜单 */
    M_ProjectListViewContextMenu = new QMenu();
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
    M_DangerZoneWidget->setStyleSheet("background-color:rgba(25,0,0,0.1);color:rgb(255,255,255);");
    M_DangerZoneWidget->setToolTip("对所选的工程进行危险操作");
    M_DangerZoneWidget->setLayout(M_DangerZoneLayout);
    M_DangerZoneWidget->hide();

    /* 底部:工程视图 */
    /* (全部的)工程视图 */
    M_AllProjectListView->installEventFilter(this);
    M_AllProjectListView->SetEmptyPixmap("://Images/Public/XEmpty.png", 600);
    M_AllProjectListView->SetEmptyPixmapVisible(false);
    M_AllProjectListView->setContextMenuPolicy(Qt::CustomContextMenu);
    M_AllProjectListView->setEditTriggers(QAbstractItemView::NoEditTriggers); /* 禁止编辑 */
    M_AllProjectListView->setMovement(QListView::Static);                     /* 禁止拖动 */
    M_AllProjectListView->setViewMode(QListView::IconMode);                   /* 网格模式 */
    M_AllProjectListView->setSelectionMode(QListView::SingleSelection);
    M_AllProjectListView->setIconSize(XncutProjectCardDelegate::GetSizeHint());
    M_AllProjectListView->setModel(M_AllProjectSortFilterProxyModel);
    M_AllProjectListView->setItemDelegate(M_ProjectCardDelegate);
    M_AllProjectSelectionModel = M_AllProjectListView->selectionModel();
    M_AllProjectSortFilterProxyModel->setSourceModel(M_AllProjectModel);

    /* 添加动作 */
    M_ProjectListViewContextMenu->addAction(QIcon("://Images/Public/Sun.png"), "选择此工程",
                                            this, &XncutProjectModifyWidget::AllProjectListViewMenuSelectedActionTriggered);
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

    /* 连接信号槽 */
    /* 全部工程视图 */
    connect(M_AllProjectListView, &QListView::doubleClicked, this, &XncutProjectModifyWidget::AllProjectViewDoubleClicked);
    connect(M_AllProjectListView, &QListView::customContextMenuRequested, this, &XncutProjectModifyWidget::AllProjectListViewCustomContextMenuRequested);
    /* 选择发生改变 */
    connect(M_AllProjectSelectionModel, &QItemSelectionModel::selectionChanged, this, &XncutProjectModifyWidget::AllProjectSelectionModelSelectionChanged);
    /********************************************************************************************************/

    for (int i = 0; i < 10; i++)
    {
        InsertProjectCard(i, QPixmap("/home/yzx/图片/cover.png"), QString("工程 %1").arg(i), "1145-01-14 11:45:14", "1145GiB");
    }
}

XncutProjectModifyWidget::~XncutProjectModifyWidget()
{
    /* 释放 */
    delete M_ProjectCardDelegate;            /* 委托 */
    delete M_AllProjectModel;                /*  (全部的)工程视图模型 */
    delete M_AllProjectSelectionModel;       /* (全部的)工程视图选择模型 */
    delete M_AllProjectSortFilterProxyModel; /* (全部的)工程过滤代理模型 */

    /* 防止野指针 */
    M_ProjectCardDelegate = NULL;
    M_AllProjectModel = NULL;
    M_AllProjectSelectionModel = NULL;
    M_AllProjectSortFilterProxyModel = NULL;
}

void XncutProjectModifyWidget::InsertProjectCard(int Index, QPixmap Cover, QString Name, QString Date, QString ProjectSize)
{
    /* Item */
    QStandardItem *Card = new QStandardItem();

    /* Set arg */
    Card->setIcon(QIcon(Cover.scaled(XncutProjectCardDelegate::GetSizeHint())));
    Card->setText(Name);
    Card->setData(Date, XncutProjectCardDelegate::PRO_CARD_DATA_DATE);
    Card->setData(ProjectSize, XncutProjectCardDelegate::PRO_CARD_DATA_SIZE);

    /* Insert */
    M_AllProjectModel->insertRow(Index, QList<QStandardItem *>() << Card);
}

void XncutProjectModifyWidget::AllProjectListViewCustomContextMenuRequested(const QPoint &Position)
{
    /* 鼠标下的Item */
    QModelIndex ModelIndex = M_AllProjectListView->indexAt(Position);

    /* 有效的项目 */
    if (ModelIndex.isValid())
    {
        M_AllProjectSelectionModel->clearSelection(); /* 确保只有一个被选中 */
        M_AllProjectSelectionModel->select(ModelIndex, QItemSelectionModel::Select);
        M_ProjectListViewContextMenu->exec(QCursor::pos()); /* 弹出菜单 */
    }
}

void XncutProjectModifyWidget::AllProjectViewDoubleClicked(const QModelIndex &Index)
{
    emit HasProjectCardSelection(qvariant_cast<QString>(Index.data(Qt::DisplayRole))); /* 发射双击信号 */
}

void XncutProjectModifyWidget::AllProjectSelectionModelSelectionChanged(const QItemSelection &Selected, const QItemSelection &Deselected)
{
    M_DangerZoneWidget->setVisible(Selected.isEmpty() ? false : true);
}

void XncutProjectModifyWidget::AllProjectListViewMenuSelectedActionTriggered()
{
    emit HasProjectCardSelection(qvariant_cast<QString>(M_AllProjectSelectionModel->currentIndex().data(Qt::DisplayRole)));
}

bool XncutProjectModifyWidget::eventFilter(QObject *Watched, QEvent *Event)
{
    /* 不是有效的 */
    if (!Watched)
    {
        return false;
    }

    /* 是所有工程视图并且事件是缩放事件 */
    if (Watched == M_AllProjectListView && Event->type() == QEvent::Resize)
    {
        M_AllProjectListView->setGridSize(QSize(350, 190));
        return true;
    }
    return QWidget::eventFilter(Watched, Event);
}
