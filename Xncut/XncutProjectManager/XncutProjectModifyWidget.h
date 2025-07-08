/*
 * @Author: xixi_
 * @Date: 2025-07-06 19:05:24
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-08 22:32:20
 * @FilePath: /Xncut/Xncut/XncutProjectManager/XncutProjectModifyWidget.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_PROJECT_MODIFY_WIDGET_H
#define XNCUT_PROJECT_MODIFY_WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include "../XncutPublicWidget/XncutListView.h"
#include "XncutProjectCardDelegate.h"
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <QMenu>

class XncutProjectModifyWidget : public QWidget
{
    Q_OBJECT
public:
    XncutProjectModifyWidget(QWidget *Parent = NULL);
    ~XncutProjectModifyWidget();

    /**
     * 插入工程卡片
     * @param Index 索引
     * @param Cover 封面,强制缩放
     * @param Name 工程名称
     * @param Date 日期,推荐格式, YY-MM-DD HH:MM
     * @param ProjectSize 工程大小, 推荐格式 1145.13GiB
     **/
    void InsertProjectCard(int Index, QPixmap Cover, QString Name, QString Date, QString ProjectSize);

private:
private slots:
    /* 所有工程视图 */
    /* [所有工程视图] 请求显示右键菜单 */
    void AllProjectListViewCustomContextMenuRequested(const QPoint &Position);

    /* [所有工程视图] 工程视图中有Item被双击 */
    void AllProjectViewDoubleClicked(const QModelIndex &Index);

    /* [所有工程选择模型] 选择发生改变 */
    void AllProjectSelectionModelSelectionChanged(const QItemSelection &Selected, const QItemSelection &Deselected);

    /* [所有工程视图右键菜单] 选择工程动作触发 */
    void AllProjectListViewMenuSelectedActionTriggered();
    /********************************************************************************************************/

protected:
    /* 重载事件 */
    /* 事件过滤器 */
    bool
    eventFilter(QObject *Watched, QEvent *Event);
    /********************************************************************************************************/

signals:
    /*
     * 有工程卡片被选择
     * 当工程卡片被双击时,或者通过右键菜单选择,将会发射此信号
     */
    void HasProjectCardSelection(QString ProjectName);
    /********************************************************************************************************/

private:
    /* 主布局 */
    QGridLayout *M_MainLayout = NULL; /* 网格布局 */
    /********************************************************************************************************/

    /* 顶部: 搜索与管理 */
    /* 搜索 */
    QLineEdit *M_SearchProjectLineEdit = NULL; /* 搜索工程行编辑框 */
    QPushButton *M_SearchProjectButton = NULL; /* 搜索工程 */
    QPushButton *M_ClearSearchButton = NULL;   /* 清除搜索 */
    QComboBox *M_SortOrderComboBox = NULL;     /* 排序方式 */
    QComboBox *M_SortByComboBox = NULL;        /* 排序依据 */
    QPushButton *M_ImportProjectButton = NULL; /* 导入工程按钮 */
    /* 管理:危险地带 */
    QWidget *M_DangerZoneWidget = NULL;        /* 危险操作部件 */
    QHBoxLayout *M_DangerZoneLayout = NULL;    /* 危险操作水平布局 */
    QPushButton *M_DeleteProjectButton = NULL; /* 删除工程按钮 */
    QPushButton *M_CloneProjectButton = NULL;  /* 克隆工程按钮 */
    QPushButton *M_RenameProjectButton = NULL; /* 重命名工程按钮 */
    QPushButton *M_PackProjectButton = NULL;   /* 打包工程按钮 */
    /********************************************************************************************************/

    /* 底部:工程视图 */
    XncutListView *M_AllProjectListView = NULL;                     /* (全部的)工程视图 */
    XncutProjectCardDelegate *M_ProjectCardDelegate = NULL;         /* 委托 */
    QStandardItemModel *M_AllProjectModel = NULL;                   /*  (全部的)工程视图模型 */
    QItemSelectionModel *M_AllProjectSelectionModel = NULL;         /* (全部的)工程视图选择模型 */
    QSortFilterProxyModel *M_AllProjectSortFilterProxyModel = NULL; /* (全部的)工程过滤代理模型 */
    /********************************************************************************************************/

    /* 所有工程列表右键菜单 */
    QMenu *M_ProjectListViewContextMenu = NULL;
    /********************************************************************************************************/
};

#endif // XNCUT_PROJECT_MODIFY_WIDGET_H
