/*
 * @Author: xixi_
 * @Date: 2025-07-14 17:47:35
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-14 17:51:09
 * @FilePath: /XncutUI/Src/XncutProjectManager/XncutProjectModifyWidget.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_PROJECT_MODIFY_WIDGET_H
#define XNCUT_PROJECT_MODIFY_WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include "../XncutPublicWidget/XncutListView.h"

class XncutProjectModifyWidget : public QWidget
{
    Q_OBJECT
private:
public:
    XncutProjectModifyWidget(QWidget *Parent = NULL);
    ~XncutProjectModifyWidget();

private:
private slots:
protected:
signals:
private:
    /* 主布局 */
    QGridLayout *M_MainLayout = NULL; /* 网格布局 */
    /********************************************************************************************************/

    /* 顶部: 搜索与管理 */
    /* 搜索 */
    QLineEdit *M_SearchProjectLineEdit = NULL; /* 搜索工程行编辑框 */
    QPushButton *M_SearchProjectButton = NULL; /* 搜索工程 */
    QPushButton *M_ClearSearchButton = NULL;   /* 清除搜索 */
    QComboBox *M_SortOrderComboBox = NULL;     /* 排序方式 */
    QComboBox *M_SortByComboBox = NULL;        /* 排序依据 */
    QPushButton *M_ImportProjectButton = NULL; /* 导入工程按钮 */
    /* 管理:危险地带 */
    QWidget *M_DangerZoneWidget = NULL;        /* 危险操作部件 */
    QHBoxLayout *M_DangerZoneLayout = NULL;    /* 危险操作水平布局 */
    QPushButton *M_DeleteProjectButton = NULL; /* 删除工程按钮 */
    QPushButton *M_CloneProjectButton = NULL;  /* 克隆工程按钮 */
    QPushButton *M_RenameProjectButton = NULL; /* 重命名工程按钮 */
    QPushButton *M_PackProjectButton = NULL;   /* 打包工程按钮 */
    /********************************************************************************************************/

    /* 底部:工程视图 */
    XncutListView *M_AllProjectListView = NULL; /* (全部的)工程视图 */
    /********************************************************************************************************/
};

#endif // XNCUT_PROJECT_MODIFY_WIDGET_H
