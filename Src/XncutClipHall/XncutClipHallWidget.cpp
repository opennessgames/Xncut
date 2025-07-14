/*
 * @Author: xixi_
 * @Date: 2025-07-14 17:24:39
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-14 17:57:09
 * @FilePath: /XncutUI/Src/XncutClipHall/XncutClipHallWidget.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutClipHallWidget.h"

/* 图标大小 */
#define CLIP_HALL_ICON_SIZE 30

XncutClipHallWidget::XncutClipHallWidget(QWidget *Parent)
    : QWidget(Parent)
{
    /* 日志 */
    qDebug() << "Init Clip hall";
    /********************************************************************************************************/

    /* 初始化 */
    /* 主布局 */
    M_MainLayout = new QHBoxLayout(); /* 网格布局 */

    /* 大厅左侧 */
    InitClipHallLeft();

    /* 大厅右侧 */
    InitClipHallRight();
    /********************************************************************************************************/

    /* 设置属性 */
    /* 大厅左侧 */
    M_LeftWidget->setFixedWidth(370);
    M_LeftWidget->setLayout(M_LeftLayout);
    /* 工程选择器 */
    M_ProjectBgButton->setFixedHeight(190);
    M_ProjectBgButton->setStyleSheet("QPushButton {"
                                     "  border: 0px solid white;"   /* 边框 */
                                     "  background-color: #444444;" /* 背景 */
                                     "  color: white;"              /* 文字颜色 */
                                     "}");
    M_ProjectBgButton->setIconSize(M_ProjectBgButton->size());
    M_ProjectBgButton->setIcon(QIcon("://Images/Public/XDefaultCover.png"));
    M_ProjectTitleLabel->setContentsMargins(2, 2, 2, 2);
    M_ProjectTitleLabel->setFixedSize(M_ProjectBgButton->size());
    M_ProjectTitleLabel->setAlignment(Qt::AlignTop);
    M_ProjectTitleLabel->setText("还没工程, 点击封面创建一个吧^_^");
    M_ProjectTitleLabel->setParent(M_ProjectBgButton);
    /* 开始剪辑按钮 */
    M_StartButton->setFixedHeight(80);
    M_StartButton->setStyleSheet(""
                                 "  font-size:50px;" /* 字体大小 */
                                 "");
    M_StartButton->setIconSize(QSize(70, 70)); /* 图标大小 */
    M_StartButton->setIcon(QIcon("://Images/ClipHall/XStartIcon.png"));
    /* 灵感 */
    M_TextEdit->setUndoRedoEnabled(false); /* 禁掉命令模式 */
    M_TextEdit->setPlaceholderText("这里记录你的灵感~");
    M_TextEdit->setText("所以问题很多时候并不复杂,是你把它想复杂了,是的,因为老一辈在我们小时候总教育我们说要吃得苦中苦,方为人上人时,搞得解决问题要亲自去经历一些困难和复杂的事情一样,但这根本没必要,而当你把问题倒置在你的主观想法之前,摆脱那一些让问题看起来很难的假设,就会发现简单易行的方法层出不穷,就像尝一尝刚买的醋,可以直接喝,但没必要去和面跟包饺子,是的,就像你遇到一些问题,需要专业的知识跟技能,你只要去学习需要的那一部分就行了,没有必要从头开始去学,所以你遇到问题,可能本身并不复杂,只是你脑中把问题复杂化了,所以当你感到无力应对时,你应该停下来多问问自己,也许这事很简单呢");
    /* 用户信息 */
    M_UserInfoWidget->SetUserAvatarSize(80);
    M_UserInfoWidget->SetUserAvatar("://Images/ClipHall/XHeadImg.png");
    M_UserInfoWidget->SetVipLevelIcon(QPixmap("://Images/ClipHall/XVipSix.png").scaled(80, 45, Qt::KeepAspectRatio));

    /* 大厅右侧 */
    /* 搜索最近工程 */
    M_SearchLineEdit->setPlaceholderText("键入关键词以搜索最近工程...");
    /* 清除搜索 */
    M_ClearSearchButton->setToolTip("清除搜索");
    M_ClearSearchButton->setIconSize(QSize(CLIP_HALL_ICON_SIZE, CLIP_HALL_ICON_SIZE));
    M_ClearSearchButton->setIcon(QIcon("://Images/Public/XClearSearch.png"));
    /* 搜索依据 */
    M_SearchByComboBox->setToolTip("搜索依据");
    M_SearchByComboBox->setIconSize(QSize(CLIP_HALL_ICON_SIZE, CLIP_HALL_ICON_SIZE));
    M_SearchByComboBox->addItem("根据名称搜索");
    M_SearchByComboBox->addItem("根据描述搜索");
    M_SearchByComboBox->setCurrentIndex(0); /* 默认是根据名称搜索 */
    /* 结果排序方式组合框 */
    M_SortByComboBox->setToolTip("排序依据");
    M_SortByComboBox->setIconSize(QSize(CLIP_HALL_ICON_SIZE, CLIP_HALL_ICON_SIZE));
    M_SortByComboBox->addItem("最新在前");
    M_SortByComboBox->addItem("最旧在前");
    M_SortByComboBox->addItem("最大在前");
    M_SortByComboBox->addItem("最小在前");
    M_SortByComboBox->setCurrentIndex(0); /* 默认是按照最新在前 */
    /* 清除最近工程列表 */
    M_ClearRecentListButton->setIconSize(QSize(CLIP_HALL_ICON_SIZE, CLIP_HALL_ICON_SIZE));
    M_ClearRecentListButton->setIcon(QIcon("://Images/Public/XClear.png"));
    /* 最近工程列表 */
    M_RecentProjectListView->SetEmptyPixmap("://Images/Public/XEmpty.png", 600);
    M_RecentProjectListView->setContextMenuPolicy(Qt::CustomContextMenu);
    M_RecentProjectListView->SetEmptyPixmapVisible(true);
    M_RecentProjectListView->setWordWrap(true);
    M_RecentProjectListView->setContentsMargins(20, 20, 20, 20);
    M_RecentProjectListView->setAlternatingRowColors(true);  /* 开启颜色交错显示 */
    M_RecentProjectListView->setMovement(QListView::Static); /* 禁止拖动 */
    M_RecentProjectListView->setEditTriggers(QListView::NoEditTriggers);
    M_RecentProjectListView->setSelectionMode(QListView::SingleSelection);
    M_RecentProjectListView->setDragDropMode(QListView::NoDragDrop);
    M_RecentProjectListView->setSpacing(5);
    M_RecentProjectListView->setViewMode(QListView::ListMode);

    /* 底部菜单按钮 */
    InitBottomMenuButton(M_ScreenRecordingButton, CLIP_HALL_ICON_SIZE, QIcon("://Images/ClipHall/BottomMenu/XScreenRecording.png"));
    InitBottomMenuButton(M_DataVideoButton, CLIP_HALL_ICON_SIZE, QIcon("://Images/ClipHall/BottomMenu/XDataVideo.png"));
    InitBottomMenuButton(M_TemplateButton, CLIP_HALL_ICON_SIZE, QIcon("://Images/ClipHall/BottomMenu/XTemplate.png"));
    InitBottomMenuButton(M_CommunityButton, CLIP_HALL_ICON_SIZE, QIcon("://Images/ClipHall/BottomMenu/XCommunity.png"));
    InitBottomMenuButton(M_SetUpButton, CLIP_HALL_ICON_SIZE, QIcon("://Images/ClipHall/BottomMenu/XSetUp.png"));
    InitBottomMenuButton(M_LocalAreaNetCollButton, CLIP_HALL_ICON_SIZE, QIcon("://Images/ClipHall/BottomMenu/XLAN.png"));
    /********************************************************************************************************/

    /* 设置布局 */
    /* 大厅左侧布局 */
    M_LeftLayout->setContentsMargins(0, 0, 0, 0);
    M_LeftLayout->setSpacing(5);
    M_LeftLayout->addWidget(M_ProjectBgButton);
    M_LeftLayout->addWidget(M_StartButton);
    M_LeftLayout->addWidget(M_TextEdit);
    M_LeftLayout->addLayout(M_UserInfoWidget);

    // /* 大厅右侧布局(网格布局) */
    // M_RightLayout->setSpacing(5);
    // M_RightLayout->addWidget(M_TitleTextLabel, 0, 0, Qt::AlignLeft);
    // M_RightLayout->addWidget(M_SearchLineEdit, 0, 1,1,23, Qt::AlignRight);
    // M_RightLayout->addWidget(M_ClearSearchButton, 0, 2, Qt::AlignRight);
    // M_RightLayout->addWidget(M_SearchByComboBox, 0, 3, Qt::AlignRight);
    // M_RightLayout->addWidget(M_SortByComboBox, 0, 4, Qt::AlignRight);
    // M_RightLayout->addWidget(M_ClearRecentListButton, 0, 5, Qt::AlignRight);
    // M_RightLayout->addWidget(M_RecentProjectListView, 1, 0, 1, 7);
    // M_RightLayout->addWidget(M_BottomMenuTipsLabel, 2, 0, Qt::AlignLeft);
    // M_RightLayout->addWidget(M_ScreenRecordingButton, 2, 1, Qt::AlignRight);
    // M_RightLayout->addWidget(M_DataVideoButton, 2, 2, Qt::AlignRight);
    // M_RightLayout->addWidget(M_TemplateButton, 2, 3, Qt::AlignRight);
    // M_RightLayout->addWidget(M_CommunityButton, 2, 4, Qt::AlignRight);
    // M_RightLayout->addWidget(M_SetUpButton, 2, 5, Qt::AlignRight);
    // M_RightLayout->addWidget(M_LocalAreaNetCollButton, 2, 6, Qt::AlignRight);

    /* [大厅右侧:最近工程] 搜索工程布局  */
    M_SearchLayout->setContentsMargins(0, 0, 0, 0);
    M_SearchLayout->setSpacing(5);
    M_SearchLayout->addWidget(M_TitleTextLabel);
    M_SearchLayout->addWidget(M_SearchLineEdit);
    M_SearchLayout->addWidget(M_ClearSearchButton);
    M_SearchLayout->addWidget(M_SearchByComboBox);
    M_SearchLayout->addWidget(M_SortByComboBox);
    M_SearchLayout->addWidget(M_ClearRecentListButton);

    /* 底部菜单布局 */
    M_BottomMenuLayout->setContentsMargins(0, 0, 0, 0);
    M_BottomMenuLayout->setSpacing(5);
    M_BottomMenuLayout->addWidget(M_BottomMenuTipsLabel);
    M_BottomMenuLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Maximum));
    M_BottomMenuLayout->addWidget(M_ScreenRecordingButton);
    M_BottomMenuLayout->addWidget(M_DataVideoButton);
    M_BottomMenuLayout->addWidget(M_TemplateButton);
    M_BottomMenuLayout->addWidget(M_CommunityButton);
    M_BottomMenuLayout->addWidget(M_SetUpButton);
    M_BottomMenuLayout->addWidget(M_LocalAreaNetCollButton);

    /* 大厅右侧布局 */
    M_RightLayout->setContentsMargins(0, 0, 0, 0);
    M_RightLayout->setSpacing(5);
    M_RightLayout->addLayout(M_SearchLayout);
    M_RightLayout->addWidget(M_RecentProjectListView);
    M_RightLayout->addLayout(M_BottomMenuLayout);

    /* 设置布局 */
    M_MainLayout->setContentsMargins(0, 0, 0, 0);
    M_MainLayout->setSpacing(10);
    M_MainLayout->addWidget(M_LeftWidget);
    M_MainLayout->addLayout(M_RightLayout);
    /********************************************************************************************************/

    setLayout(M_MainLayout);
    /********************************************************************************************************/

    /* 连接信号槽 */
    /* 大厅右侧 */
    connect(M_ProjectBgButton, &QPushButton::clicked, this, &XncutClipHallWidget::ProjectBackgroundClicked);
    connect(M_StartButton, &QPushButton::clicked, this, &XncutClipHallWidget::StartButtonClicked);
    /********************************************************************************************************/

    /* 日志 */
    qDebug() << "Init Clip hall finish";
    /********************************************************************************************************/
}

void XncutClipHallWidget::InitClipHallLeft()
{
    /* 大厅左侧 */
    M_LeftWidget = new QWidget();     /* 左侧部件 */
    M_LeftLayout = new QVBoxLayout(); /* 垂直布局 */

    /* 工程`选择or管理`器 */
    M_ProjectBgButton = new QPushButton();    /* 工程背景图(进入工程管理器) */
    M_ProjectTitleLabel = new QLabel();       /* 工程标题 */
    M_StartButton = new QPushButton("START"); /* 开始剪辑按钮 */

    /* 灵感 */
    M_TextEdit = new QTextEdit(); /* 行文本编辑器 */

    /* 用户信息 */
    M_UserInfoWidget = new XncutUserInfoWidget(); /* 信息部件 */
}

void XncutClipHallWidget::InitClipHallRight()
{
    /* 大厅右侧 */
    M_RightLayout = new QVBoxLayout(); /* 网格布局 */

    /* 最近工程区域 */
    /* 搜索工程 */
    M_SearchLayout = new QHBoxLayout();                        /* 水平布局 */
    M_TitleTextLabel = new QLabel("最近工程");                 /* 最近工程(标题)文案 */
    M_SearchLineEdit = new QLineEdit();                        /* 行搜索框 */
    M_ClearSearchButton = new QPushButton();                   /* 清除搜索 */
    M_SearchByComboBox = new QComboBox();                      /* 搜索依据 */
    M_SortByComboBox = new QComboBox();                        /* 结果排序方式组合框 */
    M_ClearRecentListButton = new QPushButton("清除最近列表"); /* 清除最近工程列表 */
    /* 最近工程列表 */
    M_RecentProjectListView = new XncutListView();

    /* 底部菜单 */
    M_BottomMenuLayout = new QHBoxLayout();                                                    /* 底部菜单布局 */
    M_BottomMenuTipsLabel = new QLabel("双击最近工程列表项以快速选择,右击项目以获得更多选项"); /* 提示 */
    M_ScreenRecordingButton = new QPushButton("录屏");                                         /* 录屏按钮 */
    M_DataVideoButton = new QPushButton("数据视频");                                           /* 数据视频按钮 */
    M_TemplateButton = new QPushButton("模板");                                                /* 模板按钮 */
    M_CommunityButton = new QPushButton("社区");                                               /* 社区按钮 */
    M_SetUpButton = new QPushButton("设置");                                                   /* 设置按钮 */
    M_LocalAreaNetCollButton = new QPushButton("局域网互协");                                  /* 局域互协按钮 */
}

void XncutClipHallWidget::InitBottomMenuButton(QPushButton *Button, int ButtonIconSize, QIcon ButtonIcon)
{
    /**
     * 确保按钮是有效的
     * 这个判断有点多余
     **/
    if (!Button)
    {
        return;
    }

    Button->setIconSize(QSize(ButtonIconSize, ButtonIconSize));
    Button->setIcon(ButtonIcon);
}

void XncutClipHallWidget::ProjectBackgroundClicked()
{
    emit HasJmpProjectManagerRequest();
}

void XncutClipHallWidget::StartButtonClicked()
{
    emit HasJmpEditorRequest();
}
