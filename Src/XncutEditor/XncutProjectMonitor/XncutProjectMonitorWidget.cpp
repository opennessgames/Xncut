/*
 * @Author: xixi_
 * @Date: 2025-08-15 01:21:30
 * @LastEditors: xixi_
 * @LastEditTime: 2025-08-15 01:30:37
 * @FilePath: /XncutUI/Src/XncutEditor/XncutProjectMonitor/XncutProjectMonitorWidget.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutProjectMonitorWidget.h"
#include <QEvent>

XncutProjectMonitorWidget::XncutProjectMonitorWidget(QWidget *Parent)
    : QWidget(Parent)
{
    /* 初始化 */
    /* 主布局 */
    M_MainLayout = new QVBoxLayout();

    /* 标题标签 */
    M_TitleLabel = new QLabel();

    /* 显示 */
    M_VideoWidget = new XncutVideoWidget();

    /* 时长 */
    M_DurationLayout = new QHBoxLayout(); /* 水平布局 */
    M_CurrDurationLabel = new QLabel();   /* 显示当前位置 */
    M_MaxDurationLabel = new QLabel();    /* 显示最大持续时长 */

    /* 监视器底部菜单 */
    M_MonitorMenuLayout = new QHBoxLayout();         /* 监视器菜单水平布局 */
    M_AddDeleteMarkButton = new QPushButton();       /* 添加/删除标点 */
    M_OutInMarkButton = new QPushButton();           /* 标记出/入点 */
    M_GoToInPointButton = new QPushButton();         /* 转到入点 */
    M_PreviousMoveFrameButton = new QPushButton();   /* 前移一帧 */
    M_PausePlayButton = new QPushButton();           /* 暂停/播放 */
    M_BackMoveFrameButton = new QPushButton();       /* 后移一帧 */
    M_GoToOutPointButton = new QPushButton();        /* 转到出点 */
    M_CaptureTheCurrFrameButton = new QPushButton(); /* 捕获当前帧 */
    M_AdjustZoomComboBox = new QComboBox();          /* 调节缩放 */
    M_AdjustAspectRatioComboBox = new QComboBox();   /* 调节宽高比 */
    M_FullScreenButton = new QPushButton();          /* 全屏 */
    /********************************************************************************************************/

    /* 设置属性 */
    /* 标题标签 */
    M_TitleLabel->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed));
    /* M_Title->setStyleSheet("background-color:rgb(79,79,79);"); */
    M_TitleLabel->setStyleSheet(""
                                "background-color:rgb(0,0,0);"
                                "");
    M_TitleLabel->setAlignment(Qt::AlignCenter);
    M_TitleLabel->setText(R"(\     工程监视器     / づ)");

    /* 显示 */
    M_VideoWidget->SetBannersContentFontSize(35);
    M_VideoWidget->SetBanners("加载摄像机数据(1/2)"); /* 横幅文本 */

    /* 时长 */
    /* 显示当前位置 */
    M_CurrDurationLabel->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    M_CurrDurationLabel->setToolTip("播放头位置");
    M_CurrDurationLabel->setFont(QFont("Arial", 13));
    M_CurrDurationLabel->setStyleSheet(""
                                       "color:rgb(236,117,141);" /* 文本颜色 */
                                       "");
    M_CurrDurationLabel->setText("00:00:00.000");
    /* 显示最大持续时长 */
    M_MaxDurationLabel->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    M_MaxDurationLabel->setToolTip("整个工程持续时长");
    M_MaxDurationLabel->setFont(QFont("Arial", 13));
    M_MaxDurationLabel->setText("00:00:00.000");

    /* 监视器底部菜单 */
    InitButton(M_AddDeleteMarkButton, "添加/删除标点", 40, 40, QIcon("://Images/Editor/Monitor/Marker.svg"));
    InitButton(M_OutInMarkButton, "标记出/入点", 40, 40, QIcon("://Images/Editor/Monitor/MarkerInOutPoint.png"));
    InitButton(M_GoToInPointButton, "转到入点", 40, 40, QIcon("://Images/Editor/Monitor/GoInPoint.svg"));
    InitButton(M_PreviousMoveFrameButton, "前移一帧", 40, 40, QIcon("://Images/Editor/Monitor/PrevFrame.svg"));
    InitButton(M_PausePlayButton, "暂停/播放", 40, 40, QIcon("://Images/Editor/Monitor/Pause.svg"));
    InitButton(M_BackMoveFrameButton, "后移一帧", 40, 40, QIcon("://Images/Editor/Monitor/NextFrame.svg"));
    InitButton(M_GoToOutPointButton, "转到出点", 40, 40, QIcon("://Images/Editor/Monitor/GoOutPoint.svg"));
    InitButton(M_CaptureTheCurrFrameButton, "捕获当前帧", 40, 40, QIcon("://Images/Editor/Monitor/Snapshot.svg"));
    /* 调节缩放 */
    M_AdjustZoomComboBox->installEventFilter(this);
    M_AdjustZoomComboBox->setFixedHeight(40);
    M_AdjustZoomComboBox->setToolTip("画面缩放");
    M_AdjustZoomComboBox->addItem("25%");
    M_AdjustZoomComboBox->addItem("50%");
    M_AdjustZoomComboBox->addItem("75%");
    M_AdjustZoomComboBox->addItem("100%");
    M_AdjustZoomComboBox->addItem("150%");
    M_AdjustZoomComboBox->addItem("200%");
    M_AdjustZoomComboBox->addItem("250%");
    M_AdjustZoomComboBox->addItem("300%");
    M_AdjustZoomComboBox->addItem("400%");
    M_AdjustZoomComboBox->setCurrentText("100%");
    /* 调节宽高比 */
    M_AdjustAspectRatioComboBox->installEventFilter(this);
    M_AdjustAspectRatioComboBox->setFixedHeight(40);
    M_AdjustZoomComboBox->setToolTip("调节宽高比");
    M_AdjustAspectRatioComboBox->addItem("16:9");
    M_AdjustAspectRatioComboBox->addItem("9:16");
    M_AdjustAspectRatioComboBox->addItem("4:3");
    M_AdjustAspectRatioComboBox->addItem("1:1");
    M_AdjustAspectRatioComboBox->addItem("3:4");
    M_AdjustAspectRatioComboBox->addItem("21:9");
    M_AdjustAspectRatioComboBox->setCurrentText("16:9");
    /* 全屏 */
    InitButton(M_FullScreenButton, "全屏", 40, 40, QIcon("://Images/Editor/Monitor/FullScreen.png"));
    /********************************************************************************************************/

    /* 设置布局 */
    /* 持续时长布局 */
    M_DurationLayout->setContentsMargins(0, 0, 0, 0);
    M_DurationLayout->setSpacing(0);
    M_DurationLayout->addWidget(M_CurrDurationLabel);
    M_DurationLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Maximum));
    M_DurationLayout->addWidget(M_MaxDurationLabel);

    /* 底部菜单布局 */
    M_MonitorMenuLayout->setContentsMargins(0, 0, 0, 0);
    M_MonitorMenuLayout->setSpacing(3);
    M_MonitorMenuLayout->addWidget(M_AddDeleteMarkButton);
    M_MonitorMenuLayout->addWidget(M_OutInMarkButton);
    M_MonitorMenuLayout->addWidget(M_GoToInPointButton);
    M_MonitorMenuLayout->addWidget(M_PreviousMoveFrameButton);
    M_MonitorMenuLayout->addWidget(M_PausePlayButton);
    M_MonitorMenuLayout->addWidget(M_BackMoveFrameButton);
    M_MonitorMenuLayout->addWidget(M_GoToOutPointButton);
    M_MonitorMenuLayout->addWidget(M_CaptureTheCurrFrameButton);
    M_MonitorMenuLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Maximum));
    M_MonitorMenuLayout->addWidget(M_AdjustZoomComboBox);
    M_MonitorMenuLayout->addWidget(M_AdjustAspectRatioComboBox);
    M_MonitorMenuLayout->addWidget(M_FullScreenButton);

    /* 主布局 */
    M_MainLayout->setContentsMargins(3, 3, 3, 3);
    M_MainLayout->setSpacing(3);
    M_MainLayout->addWidget(M_TitleLabel);
    M_MainLayout->addWidget(M_VideoWidget);
    M_MainLayout->addLayout(M_DurationLayout);
    M_MainLayout->addLayout(M_MonitorMenuLayout);
    /********************************************************************************************************/

    setLayout(M_MainLayout);
    /********************************************************************************************************/
}

XncutProjectMonitorWidget::~XncutProjectMonitorWidget()
{
}

void XncutProjectMonitorWidget::InitButton(QPushButton *Button, QString ButtonToolTip, int ButtonSize, int ButtonIconSize, QIcon ButtonIcon)
{
    /* 判空 */
    if (!Button)
    {
        return;
    }

    /* 设置参数 */
    Button->setToolTip(ButtonToolTip);
    Button->setFixedSize(QSize(ButtonSize, ButtonSize));
    Button->setIconSize(QSize(ButtonIconSize, ButtonIconSize));
    Button->setIcon(ButtonIcon);
}

bool XncutProjectMonitorWidget::eventFilter(QObject *Watched, QEvent *Event)
{
    /* 拦截掉滚轮 */
    if ((Watched == M_AdjustZoomComboBox || Watched == M_AdjustAspectRatioComboBox) && Event->type() == QEvent::Wheel)
    {
        Event->ignore();
        return true;
    }

    /* 继续 */
    return QWidget::eventFilter(Watched, Event);
}

void XncutProjectMonitorWidget::enterEvent(QEnterEvent *Event)
{
    emit HasShowBottonTipsRequest("工程监视器: Ctrl+鼠标滚轮以缩放视图; 双击任意方向蓝牙耳机暂停,单击左耳机上一帧,右耳机下一帧; 通过标题栏菜单\"布局\"选项调节适合编辑抖音短视频的布局");
}
