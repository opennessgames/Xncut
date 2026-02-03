/*
 * @Author: xixi_
 * @Date: 2025-07-14 18:18:46
 * @LastEditors: xixi_
 * @LastEditTime: 2026-02-04 02:25:58
 * @FilePath: /XncutUI/Src/XncutEditor/XncutEditorWidget.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_EDITOR_WIDGET_H
#define XNCUT_EDITOR_WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QSplitter>
#include "XncutTitleBar/XncutTitleBarWidget.h"
#include "XncutBins/XncutBinsWidget.h"
#include "XncutProjectMonitor/XncutProjectMonitorWidget.h"
#include "XncutInspector/XncutInspectorWidget.h"

class XncutEditorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit XncutEditorWidget(QWidget *Parent = NULL);

private:
private slots:
    /* [顶部菜单栏] 返回大厅按钮被点击 */
    void ReturnButtonClicked();
    /********************************************************************************************************/

protected:
signals:
    /* 请求跳转到剪辑大厅 */
    void HasJmpClipHallRequest();
    /********************************************************************************************************/

private:
    QSplitter *M_MainSplitter = NULL; /* 主分割线 */
    /********************************************************************************************************/

    /* 标题 */
    XncutTitleBarWidget *M_TitleBarWidget = NULL; /* 标题栏 */
    /********************************************************************************************************/

    /* 内容分裂器 */
    QSplitter *M_TopSplitter = NULL;    /* 顶部(素材 监视器 检查器) 水平 */
    QSplitter *M_BottomSplitter = NULL; /* 底部(工具 时间线 峰值表) 水平 */
    /********************************************************************************************************/

    /* 顶部核心模块 */
    XncutBinsWidget *M_BinsWidget = NULL;                     /* 素材箱 */
    XncutProjectMonitorWidget *M_ProjectMonitorWidget = NULL; /* 监视器 */
    XncutInspectorWidget *M_InspectorWidget = NULL;           /* 检查器 */
    /********************************************************************************************************/

    /********************************************************************************************************/
};

#endif // XNCUT_EDITOR_WIDGET_H
