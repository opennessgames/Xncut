/*
 * @Author: xixi_
 * @Date: 2025-08-15 02:38:01
 * @LastEditors: xixi_
 * @LastEditTime: 2025-08-15 02:39:32
 * @FilePath: /XncutUI/Src/XncutEditor/XncutInspector/XncutProjectArgWidget.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_PROJECT_ARG_WIDGET_H
#define XNCUT_PROJECT_ARG_WIDGET_H

#include <QWidget>
#include <QFormLayout>
#include <QLabel>

class XncutProjectArgWidget : public QWidget
{
    Q_OBJECT
private:
    /********************************************************************************************************/

public:
    explicit XncutProjectArgWidget(QWidget *Parent = NULL);
    ~XncutProjectArgWidget();
    /********************************************************************************************************/

    /********************************************************************************************************/

private:
    /********************************************************************************************************/

private slots:
    /********************************************************************************************************/

protected:
    /* 重载事件 */
    /* 绘制事件 */
    void paintEvent(QPaintEvent *Event) override;
    /********************************************************************************************************/

signals:
    /********************************************************************************************************/

private:
    /* 主布局 */
    QFormLayout *M_MainLayout = NULL; /* 表单布局 */
    /********************************************************************************************************/

    /* 参数标签 */
    QLabel *M_ProjectTitle = NULL;       /* 工程标题 */
    QLabel *M_ProjectDescription = NULL; /* 描述 */
    QLabel *M_ProjectPath = NULL;        /* 工程路径 */
    /* 分割线 */
    QFrame *M_ArgWidgetLine = NULL;
    /* 导出参数 */
    QLabel *M_ColorSpaceLabel = NULL;        /* 视频色彩空间 */
    QLabel *M_ResolutionLabel = NULL;        /* 视频分辨率 */
    QLabel *M_FramerateLabel = NULL;         /* 视频帧率 */
    QLabel *M_VideoFormatLabel = NULL;       /* 视频格式 */
    QLabel *M_VideoBitsLabel = NULL;         /* 视频位深 */
    QLabel *M_VideoCodingLabel = NULL;       /* 视频编解码器 */
    QLabel *M_AudioCodingLabel = NULL;       /* 音频编解码器 */
    QLabel *M_AudioChannelLabel = NULL;      /* 音频通道数 */
    QLabel *M_AudioSamplingRateLabel = NULL; /* 音频采样率 */
    QLabel *M_AudioBitsLabel = NULL;         /* 音频位深 */
    /********************************************************************************************************/
};

#endif // XNCUT_PROJECT_ARG_WIDGET_H
