/*
 * @Author: xixi_
 * @Date: 2025-08-15 01:21:30
 * @LastEditors: xixi_
 * @LastEditTime: 2026-02-04 02:17:54
 * @FilePath: /XncutUI/Src/XncutEditor/XncutProjectMonitor/XncutProjectMonitorWidget.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_PROJECT_MONITOR_WIDGET_H
#define XNCUT_PROJECT_MONITOR_WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include "XncutVideoWidget.h"

class QToolBar;
class XncutProjectMonitorWidget : public QWidget
{
    Q_OBJECT
private:
    /********************************************************************************************************/

public:
    explicit XncutProjectMonitorWidget(QWidget *Parent = NULL);
    ~XncutProjectMonitorWidget();
    /********************************************************************************************************/

    /********************************************************************************************************/

private:
    /********************************************************************************************************/

private slots:
    /********************************************************************************************************/

protected:
    /* 重载事件 */
    /* 事件过滤器 */
    bool eventFilter(QObject *Watched, QEvent *Event) override;
    /********************************************************************************************************/

    /* 鼠标指针进入时 */
    void enterEvent(QEnterEvent *Event) override;
    /********************************************************************************************************/

signals:
    /* 请求显示底部提示 */
    void HasShowBottonTipsRequest(QString Tips);
    /********************************************************************************************************/

private:
    /* 标题标签 */
    QLabel *M_TitleLabel = NULL;
    /********************************************************************************************************/

    /* 显示 */
    XncutVideoWidget *M_VideoWidget = NULL;
    /********************************************************************************************************/

    /* 时长 */
    QHBoxLayout *M_DurationLayout = NULL; /* 水平布局 */
    QLabel *M_CurrDurationLabel = NULL;   /* 显示当前位置 */
    QLabel *M_MaxDurationLabel = NULL;    /* 显示最大持续时长 */
    /********************************************************************************************************/

    /* 监视器底部工具栏 */
    QToolBar *M_MonitorToolBar = NULL; 
    // QHBoxLayout *M_MonitorMenuLayout = NULL;         /* 水平布局 */
    // QPushButton *M_AddDeleteMarkButton = NULL;       /* 添加/删除标点 */
    // QPushButton *M_OutInMarkButton = NULL;           /* 标记出/入点 */
    // QPushButton *M_GoToInPointButton = NULL;         /* 转到入点 */
    // QPushButton *M_PreviousMoveFrameButton = NULL;   /* 前移一帧 */
    // QPushButton *M_PausePlayButton = NULL;           /* 暂停/播放 */
    // QPushButton *M_BackMoveFrameButton = NULL;       /* 后移一帧 */
    // QPushButton *M_GoToOutPointButton = NULL;        /* 转到出点 */
    // QPushButton *M_CaptureTheCurrFrameButton = NULL; /* 捕获当前帧 */
    QComboBox *M_AdjustZoomComboBox = NULL;          /* 调节缩放 */
    QComboBox *M_AdjustAspectRatioComboBox = NULL;   /* 调节宽高比 */
    // QPushButton *M_FullScreenButton = NULL;          /* 全屏 */
    /********************************************************************************************************/
};

#endif // XNCUT_PROJECT_MONITOR_WIDGET_H
