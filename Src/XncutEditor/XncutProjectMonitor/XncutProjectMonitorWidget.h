/*
 * @Author: xixi_
 * @Date: 2025-08-15 01:21:30
 * @LastEditors: xixi_
 * @LastEditTime: 2025-08-15 01:30:25
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
    /**
     * @brief 初始化按钮
     * @param Button 按钮
     * @param ButtonToolTip 按钮ToolTip
     * @param ButtonSize 按钮大小
     * @param ButtonIconSize 按钮图标大小
     * @param ButtonIcon 按钮图标
     * @note 带有安全检查, 如果传入NULL, 将不会进行初始化, 野指针无法保证,因为仅检查是否为空指针
     **/
    void InitButton(QPushButton *Button, QString ButtonToolTip, int ButtonSize, int ButtonIconSize, QIcon ButtonIcon);
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
    /* 主布局 */
    QVBoxLayout *M_MainLayout = NULL;
    /********************************************************************************************************/

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

    /* 监视器底部菜单 */
    QHBoxLayout *M_MonitorMenuLayout = NULL;         /* 水平布局 */
    QPushButton *M_AddDeleteMarkButton = NULL;       /* 添加/删除标点 */
    QPushButton *M_OutInMarkButton = NULL;           /* 标记出/入点 */
    QPushButton *M_GoToInPointButton = NULL;         /* 转到入点 */
    QPushButton *M_PreviousMoveFrameButton = NULL;   /* 前移一帧 */
    QPushButton *M_PausePlayButton = NULL;           /* 暂停/播放 */
    QPushButton *M_BackMoveFrameButton = NULL;       /* 后移一帧 */
    QPushButton *M_GoToOutPointButton = NULL;        /* 转到出点 */
    QPushButton *M_CaptureTheCurrFrameButton = NULL; /* 捕获当前帧 */
    QComboBox *M_AdjustZoomComboBox = NULL;          /* 调节缩放 */
    QComboBox *M_AdjustAspectRatioComboBox = NULL;   /* 调节宽高比 */
    QPushButton *M_FullScreenButton = NULL;          /* 全屏 */
    /********************************************************************************************************/
};

#endif // XNCUT_PROJECT_MONITOR_WIDGET_H
