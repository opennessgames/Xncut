/*
 * @Author: xixi_
 * @Date: 2025-08-15 01:21:30
 * @LastEditors: xixi_
 * @LastEditTime: 2026-02-04 02:25:13
 * @FilePath: /XncutUI/Src/XncutEditor/XncutProjectMonitor/XncutProjectMonitorWidget.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutProjectMonitorWidget.h"
#include <QToolBar>
#include <QEvent>

XncutProjectMonitorWidget::XncutProjectMonitorWidget(QWidget *Parent)
    : QWidget(Parent)
{
    /* 初始化 */
    /* 主布局 */
    QVBoxLayout *MainLayout = new QVBoxLayout();

    /* 标题标签 */
    M_TitleLabel = new QLabel();

    /* 显示 */
    M_VideoWidget = new XncutVideoWidget();

    /* 时长 */
    M_DurationLayout = new QHBoxLayout(); /* 水平布局 */
    M_CurrDurationLabel = new QLabel();   /* 显示当前位置 */
    M_MaxDurationLabel = new QLabel();    /* 显示最大持续时长 */

    /* 监视器底部菜单 */
    QWidget *LeftSpacingWidget = new QWidget();  /* 左间隔部件, 无实际意义, 只是起到弹簧的作用 */
    QWidget *RightSpacingWidget = new QWidget(); /* 右间隔部件 */
    QToolBar *M_MonitorToolBar = new QToolBar("监视器工具");

    M_AdjustZoomComboBox = new QComboBox();
    M_AdjustAspectRatioComboBox = new QComboBox();
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
    M_VideoWidget->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum));
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

    /* 监视器底部工具栏 */
    LeftSpacingWidget->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum));
    RightSpacingWidget->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum));
    M_MonitorToolBar->setSizePolicy(QSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed));
    M_MonitorToolBar->setIconSize(QSize(30, 30)); /* 统一改变图标大小 */
    M_MonitorToolBar->addWidget(LeftSpacingWidget);
    M_MonitorToolBar->addAction(QIcon("://Images/Editor/Monitor/Marker.svg"), "添加/删除标点");
    M_MonitorToolBar->addAction(QIcon("://Images/Editor/Monitor/MarkerInOutPoint.png"), "标记出/入点");
    M_MonitorToolBar->addAction(QIcon("://Images/Editor/Monitor/GoInPoint.svg"), "转到入点");
    M_MonitorToolBar->addAction(QIcon("://Images/Editor/Monitor/PrevFrame.svg"), "前移一帧");
    M_MonitorToolBar->addAction(QIcon("://Images/Editor/Monitor/Pause.svg"), "暂停 / 播放");
    M_MonitorToolBar->addAction(QIcon("://Images/Editor/Monitor/NextFrame.svg"), "后移一帧");
    M_MonitorToolBar->addAction(QIcon("://Images/Editor/Monitor/GoOutPoint.svg"), "转到出点");
    M_MonitorToolBar->addAction(QIcon("://Images/Editor/Monitor/Snapshot.svg"), "捕获当前帧");
    M_MonitorToolBar->addAction(QIcon("://Images/Editor/Monitor/FullScreen.png"), "全屏");
    M_MonitorToolBar->addWidget(M_AdjustZoomComboBox);
    M_MonitorToolBar->addWidget(M_AdjustAspectRatioComboBox);
    M_MonitorToolBar->addWidget(RightSpacingWidget);

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
    /********************************************************************************************************/

    /* 设置布局 */
    /* 持续时长布局 */
    M_DurationLayout->setContentsMargins(0, 0, 0, 0);
    M_DurationLayout->setSpacing(0);
    M_DurationLayout->addWidget(M_CurrDurationLabel);
    M_DurationLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Maximum));
    M_DurationLayout->addWidget(M_MaxDurationLabel);

    /* 主布局 */
    MainLayout->setContentsMargins(3, 3, 3, 3);
    MainLayout->setSpacing(3);
    MainLayout->addWidget(M_TitleLabel);
    MainLayout->addWidget(M_VideoWidget);
    MainLayout->addLayout(M_DurationLayout);
    MainLayout->addWidget(M_MonitorToolBar);
    /********************************************************************************************************/

    setLayout(MainLayout);
    /********************************************************************************************************/
}

XncutProjectMonitorWidget::~XncutProjectMonitorWidget()
{
}

bool XncutProjectMonitorWidget::eventFilter(QObject *Watched, QEvent *Event)
{
    // /* 拦截掉滚轮 */
    // if ((Watched == M_AdjustZoomComboBox || Watched == M_AdjustAspectRatioComboBox) && Event->type() == QEvent::Wheel)
    // {
    //     Event->ignore();
    //     return true;
    // }

    /* 继续 */
    return QWidget::eventFilter(Watched, Event);
}

void XncutProjectMonitorWidget::enterEvent(QEnterEvent *Event)
{
    emit HasShowBottonTipsRequest("工程监视器: Ctrl+鼠标滚轮以缩放视图; 双击任意方向蓝牙耳机暂停,单击左耳机上一帧,右耳机下一帧; 通过标题栏菜单\"布局\"选项调节适合编辑抖音短视频的布局");
}
