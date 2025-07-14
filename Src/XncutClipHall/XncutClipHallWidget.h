/*
 * @Author: xixi_
 * @Date: 2025-07-14 17:24:17
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-14 17:55:00
 * @FilePath: /XncutUI/Src/XncutClipHall/XncutClipHallWidget.h
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
#include <QVBoxLayout>
#include <QLineEdit>
#include <QComboBox>
#include "../XncutPublicWidget/XncutListView.h"

class XncutClipHallWidget : public QWidget
{
    Q_OBJECT
private:
public:
    explicit XncutClipHallWidget(QWidget *Parent = NULL);

private:
    /* 初始化大厅左侧 */
    void InitClipHallLeft();

    /* 初始化大厅左侧 */
    void InitClipHallRight();
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

    /* 工程`选择or管理`器 */
    QPushButton *M_ProjectBgButton = NULL; /* 工程背景图(进入工程管理器) */
    QLabel *M_ProjectTitleLabel = NULL;    /* 工程标题 */
    QPushButton *M_StartButton = NULL;     /* 开始剪辑按钮 */

    /* 灵感 */
    QTextEdit *M_TextEdit = NULL; /* 行文本编辑器 */

    /* 用户信息 */
    XncutUserInfoWidget *M_UserInfoWidget = NULL; /* 信息部件 */
    /********************************************************************************************************/

    /* 大厅右侧 */
    QVBoxLayout *M_RightLayout = NULL; /* 网格布局 */

    /* 最近工程区域 */
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
};

#endif // XNCUT_CLIP_HALL_WIDGET_H
