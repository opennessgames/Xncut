/*
 * @Author: xixi_
 * @Date: 2025-07-06 18:25:55
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-06 19:20:25
 * @FilePath: /Xncut/Xncut/XncutProjectManager/XncutProjectManagerWidget.h
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
public:
    explicit XncutProjectManagerWidget(QWidget *Parent = NULL);

private:
private slots:

protected:
signals:

private:
    /* 主布局 */
    QGridLayout *M_MainLayout = NULL; /* 网格布局 */
    /********************************************************************************************************/

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
};

#endif // XNCUT_PROJECT_MANAGER_WIDGET_H
