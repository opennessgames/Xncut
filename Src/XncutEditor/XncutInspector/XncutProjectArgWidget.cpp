/*
 * @Author: xixi_
 * @Date: 2025-08-15 02:38:01
 * @LastEditors: xixi_
 * @LastEditTime: 2025-08-15 02:39:47
 * @FilePath: /XncutUI/Src/XncutEditor/XncutInspector/XncutProjectArgWidget.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutProjectArgWidget.h"
#include <QPainter>

XncutProjectArgWidget::XncutProjectArgWidget(QWidget *Parent)
    : QWidget(Parent)
{
    /* 初始化 */
    /* 主布局 */
    M_MainLayout = new QFormLayout(); /* 表单布局 */

    /* 参数标签 */
    M_ProjectTitle = new QLabel("NULL");       /* 工程标题 */
    M_ProjectDescription = new QLabel("NULL"); /* 描述 */
    M_ProjectPath = new QLabel("NULL");        /* 工程路径 */
    /* 分割线 */
    M_ArgWidgetLine = new QFrame();
    /* 导出参数 */
    M_ColorSpaceLabel = new QLabel("NULL");        /* 视频色彩空间 */
    M_ResolutionLabel = new QLabel("NULL");        /* 视频分辨率 */
    M_FramerateLabel = new QLabel("NULL");         /* 视频帧率 */
    M_VideoFormatLabel = new QLabel("NULL");       /* 视频格式 */
    M_VideoBitsLabel = new QLabel("NULL");         /* 视频位深 */
    M_VideoCodingLabel = new QLabel("NULL");       /* 视频编解码器 */
    M_AudioCodingLabel = new QLabel("NULL");       /* 音频编解码器 */
    M_AudioChannelLabel = new QLabel("NULL");      /* 音频通道数 */
    M_AudioSamplingRateLabel = new QLabel("NULL"); /* 音频采样率 */
    M_AudioBitsLabel = new QLabel("NULL");         /* 音频位深 */
    /********************************************************************************************************/

    /* 设置属性 */
    /* 分割线 */
    M_ArgWidgetLine->setStyleSheet(""
                                   "background-color:rgb(255,255,255);"
                                   "");
    M_ArgWidgetLine->setFrameShape(QFrame::HLine);
    M_ArgWidgetLine->setFrameShadow(QFrame::Sunken);
    /********************************************************************************************************/

    /* 设置布局 */
    M_MainLayout->setContentsMargins(10, 10, 10, 10);
    M_MainLayout->setSpacing(3);
    M_MainLayout->addRow(new QLabel("工程标题: "), M_ProjectTitle);
    M_MainLayout->addRow(new QLabel("工程描述: "), M_ProjectDescription);
    M_MainLayout->addRow(new QLabel("工程路径: "), M_ProjectPath);
    M_MainLayout->insertRow(3, M_ArgWidgetLine);
    M_MainLayout->addRow(new QLabel("视频色彩空间: "), M_ColorSpaceLabel);
    M_MainLayout->addRow(new QLabel("视频分辨率: "), M_ResolutionLabel);
    M_MainLayout->addRow(new QLabel("视频帧率: "), M_FramerateLabel);
    M_MainLayout->addRow(new QLabel("视频格式: "), M_VideoFormatLabel);
    M_MainLayout->addRow(new QLabel("视频位深: "), M_VideoBitsLabel);
    M_MainLayout->addRow(new QLabel("视频编解码器: "), M_VideoCodingLabel);
    M_MainLayout->addRow(new QLabel("音频编解码器: "), M_AudioCodingLabel);
    M_MainLayout->addRow(new QLabel("音频通道数: "), M_AudioChannelLabel);
    M_MainLayout->addRow(new QLabel("音频采样率: "), M_AudioSamplingRateLabel);
    M_MainLayout->addRow(new QLabel("音频位深: "), M_AudioBitsLabel);
    /********************************************************************************************************/

    setLayout(M_MainLayout);
    /********************************************************************************************************/
}

XncutProjectArgWidget::~XncutProjectArgWidget()
{
}

void XncutProjectArgWidget::paintEvent(QPaintEvent *Event)
{
    /* 画家 */
    QPainter XncutProjectArgWidgetPainter(this);

    /* 参数 */
    XncutProjectArgWidgetPainter.setPen(Qt::NoPen);
    XncutProjectArgWidgetPainter.setBrush(QColor(0, 0, 0, 200));

    /* 绘制背景矩形 */
    XncutProjectArgWidgetPainter.drawRect(0, 0, width(), height());
}
