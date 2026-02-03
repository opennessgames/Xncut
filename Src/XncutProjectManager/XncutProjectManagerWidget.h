/*
 * @Author: xixi_
 * @Date: 2025-07-14 17:40:37
 * @LastEditors: xixi_
 * @LastEditTime: 2026-02-04 02:30:10
 * @FilePath: /XncutUI/Src/XncutProjectManager/XncutProjectManagerWidget.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_PROJECT_MANAGER_WIDGET_H
#define XNCUT_PROJECT_MANAGER_WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QTabWidget>
#include "XncutProjectModifyWidget.h"
#include "XncutProjectCreateWidget.h"

class XncutProjectManagerWidget : public QWidget
{
    Q_OBJECT
private:
public:
    explicit XncutProjectManagerWidget(QWidget *Parent = NULL);

private:
private slots:
    /* 返回大厅按钮被点击 */
    void ReturnClipHallButtonClicked();
    /********************************************************************************************************/

protected:
signals:
    /* 请求跳转到剪辑大厅 */
    void HasJmpClipHallRequest();
    /********************************************************************************************************/

private:
    /* 标题 */
    QLabel *M_TitleLabel = NULL;                /* 标签 */
    QPushButton *M_ReturnClipHallButton = NULL; /* 返回大厅按钮 */
    /********************************************************************************************************/

    /* 内容部件 */
    QTabWidget *M_ContentsTabWidget = NULL;
    /********************************************************************************************************/

    /* 内容 */
    XncutProjectModifyWidget *M_ProjectModifyWidget = NULL; /* 工程管理 */
    XncutProjectCreateWidget *M_ProjectCreateWidget = NULL; /* 工程创建 */
    /********************************************************************************************************/

    /* 底部提示 */
    QLabel *M_BottomLabel = NULL;
    /********************************************************************************************************/
};

#endif // XNCUT_PROJECT_MANAGER_WIDGET_H
