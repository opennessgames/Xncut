/*
 * @Author: xixi_
 * @Date: 2025-07-02 12:38:58
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-07 19:30:43
 * @FilePath: /Xncut/Xncut/XncutClipHall/XncutClipHallWidget.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_CLIP_HALL_WIDGET_H
#define XNCUT_CLIP_HALL_WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include "XncutUserInfoWidget.h"
#include <QLineEdit>
#include <QComboBox>
#include "../XncutPublicWidget/XncutListView.h"
#include <QStandardItemModel>
#include "XncutRecentProjectCardDelegate.h"
#include <QMenu>
#include <QSortFilterProxyModel>

class XncutClipHallWidget : public QWidget
{
    Q_OBJECT
public:
    /* 搜索依据 */
    typedef enum
    {
        /* 根据名称搜索 */
        NAME = Qt::DisplayRole,
        /* 根据描述搜索 */
        DESCRIPTION = XncutRecentProjectCardDelegate::PRO_CARD_DATA_DESCRIPTION,
    } SearchBy;

    /* 排序依据 */
    typedef enum
    {
        LATEST = 0, /* 最新的 */
        OLDEST,     /* 最旧的 */
        UTMOST,     /* 最大的 */
        LEAST,      /* 最小的 */
    } SortBy;

    /* 大厅构造 */
    explicit XncutClipHallWidget(QWidget *Parent = NULL);

    /* 析构 */
    ~XncutClipHallWidget();

    /* [工程选择器] 获取当前选中的工程名称 */
    QString GetCurrentProject();
    /********************************************************************************************************/

    /* [最近工程列表] 插入最近工程卡片 */
    void InsertRecentProjectCard(int Index, QPixmap Cover, QString Name, QString Description);

    /* [最近工程列表] 移除最近工程卡片 */
    void RrmoveRecentProjectCard(int Index);

    /* [最近工程列表] 获取最近工程列表模型 */
    QStandardItemModel *GetRecentProjectCardModel();
    /********************************************************************************************************/

private:
    /* 初始化大厅左侧 */
    void InitClipHallLeft();

    /* 初始化大厅左侧 */
    void InitClipHallRight();

    /* 初始化最近工程视图的右键菜单 */
    void InitRecentProjectListViewContextMenu();
    /********************************************************************************************************/

    /* 初始化底部菜单按钮 */
    void InitBottomMenuButton(QPushButton *Button, int ButtonIconSize, QIcon ButtonIcon);
    /********************************************************************************************************/

private slots:
    /* 大厅右侧 */
    /* 工程背景被点击 */
    void ProjectBackgroundClicked();

    /* 开始按钮被点击 */
    void StartButtonClicked();
    /********************************************************************************************************/

    /* 最近工程顶部栏 */
    /* [最近工程顶部栏] 搜索行编辑框文本发生改变 */
    void SearchLineEditTextChanged(const QString &CurrText);

    /* [最近工程顶部栏] 清除搜索按钮被点击 */
    void ClearSearchButtonClicked();

    /* [最近工程顶部栏] 清除最近列表按钮被点击 */
    void ClearRecentListButtonClicked();

    /* [最近工程顶部栏] 搜索依据组合框发生改变 */
    void SearchByComboBoxCurrentIndexChanged(int Index);

    /* [最近工程顶部栏] 排序依据组合框发生改变 */
    void SortByComboBoxCurrentIndexChanged(int Index);
    /********************************************************************************************************/

    /* 最近工程列表视图相关 */
    /* [最近工程列表视图] 请求显示右键菜单 */
    void RecentProjectListViewCustomContextMenuRequested(const QPoint &Position);

    /* [最近工程列表视图] 列表项被双击 */
    void RecentProjectListViewDoubleClicked(const QModelIndex &Index);

    /* [最近工程视图模型] 项目发生改变时 */
    void RecentProjectCardModelRowsInserted();
    void RecentProjectCardModelRowsRemoved();

    /* [最近列表视图右键菜单] 选择动作触发 */
    void RecentProjectListViewMenuSelectedActionTriggered();

    /* [最近列表视图右键菜单] 删除动作触发 */
    void RecentProjectListViewMenuDeleteActionTriggered();
    /********************************************************************************************************/

protected:
signals:
    /* 请求跳转到管理器 */
    void HasJmpProjectManagerRequest();

    /* 请求跳转到编辑器 */
    void HasJmpEditorRequest();
    /********************************************************************************************************/

private:
    /* 主布局 */
    QHBoxLayout *M_MainLayout = NULL; /* 水平布局 */
    /********************************************************************************************************/

    /* 大厅左侧 */
    QWidget *M_LeftWidget = NULL;     /* 左侧部件 */
    QVBoxLayout *M_LeftLayout = NULL; /* 垂直布局 */

    /* 工程选择器 */
    QPushButton *M_ProjectBgButton = NULL; /* 工程背景图(进入工程管理器) */
    QLabel *M_ProjectTitleLabel = NULL;    /* 工程标题 */
    QPushButton *M_StartButton = NULL;     /* 开始剪辑按钮 */

    /* 灵感 */
    QTextEdit *M_TextEdit = NULL; /* 行文本编辑器 */

    /* 用户信息 */
    XncutUserInfoWidget *M_UserInfoWidget = NULL; /* 信息部件 */
    /********************************************************************************************************/

    /* 大厅右侧 */
    QVBoxLayout *M_RightLayout = NULL; /* 垂直布局 */

    /* 最近工程 */
    /* 搜索工程 */
    QHBoxLayout *M_SearchLayout = NULL;          /* 水平布局 */
    QLabel *M_TitleTextLabel = NULL;             /* 最近工程(标题)文案 */
    QLineEdit *M_SearchLineEdit = NULL;          /* 行搜索框 */
    QPushButton *M_ClearSearchButton = NULL;     /* 清除搜索 */
    QComboBox *M_SearchByComboBox = NULL;        /* 搜索依据 */
    QComboBox *M_SortByComboBox = NULL;          /* 结果排序方式组合框 */
    QPushButton *M_ClearRecentListButton = NULL; /* 清除最近工程列表 */
    /* 最近工程列表 */
    XncutListView *M_RecentProjectListView = NULL;
    QStandardItemModel *M_RecentProjectCardModel = NULL;
    XncutRecentProjectCardDelegate *M_RecentProjectCardDelegate = NULL;
    QItemSelectionModel *M_RecentProjectCardSelectionModel = NULL;
    QSortFilterProxyModel *M_RecentProjectCardSortFilterProxyModel = NULL;

    /* 底部菜单 */
    QHBoxLayout *M_BottomMenuLayout = NULL;       /* 底部菜单布局 */
    QLabel *M_BottomMenuTipsLabel = NULL;         /* 提示 */
    QPushButton *M_ScreenRecordingButton = NULL;  /* 录屏按钮 */
    QPushButton *M_DataVideoButton = NULL;        /* 数据视频按钮 */
    QPushButton *M_TemplateButton = NULL;         /* 模板按钮 */
    QPushButton *M_CommunityButton = NULL;        /* 社区按钮 */
    QPushButton *M_SetUpButton = NULL;            /* 设置按钮 */
    QPushButton *M_LocalAreaNetCollButton = NULL; /* 局域互协按钮 */
    /********************************************************************************************************/

    /* 最近工程列表右键菜单 */
    QMenu *M_RecentProjectListViewContextMenu = NULL;
    /********************************************************************************************************/
};

#endif // XNCUT_CLIP_HALL_WIDGET_H
