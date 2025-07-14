/*
 * @Author: xixi_
 * @Date: 2025-07-14 18:51:09
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-14 18:51:33
 * @FilePath: /XncutUI/Src/XncutEditor/XncutBins/XncutMaterialField/XncutMaterialFieldWidget.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_MATERIAL_FIELD_WIDGET_H
#define XNCUT_MATERIAL_FIELD_WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QTabBar>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include "../../../XncutPublicWidget/XncutListView.h"

class XncutMaterialFieldWidget : public QWidget
{
    Q_OBJECT
private:
public:
    explicit XncutMaterialFieldWidget(QWidget *Parent = NULL);

    /* 获取标签栏 */
    QTabBar *GetTabBar();
    /********************************************************************************************************/

private:
private slots:

protected:
signals:

private:
    /* 主布局 */
    QGridLayout *M_MainLayout = NULL;
    /********************************************************************************************************/

    /* 素材类型标签 */
    QTabBar *M_MaterialTypeTabBar = NULL;
    /********************************************************************************************************/

    /* 右侧视图 */
    /* 顶部搜索栏 */
    QLineEdit *M_SearchLineEdit = NULL;         /* 行编辑框 */
    QPushButton *M_ClearSearchButton = NULL;    /* 清除搜索按钮 */
    QPushButton *M_ImportMaterialButton = NULL; /* 导入素材按钮 */
    QComboBox *M_ImportTimeComboBox = NULL;     /* 素材排序依据 */
    QComboBox *M_ViewModeComboBox = NULL;       /* 显示模式 */
    /********************************************************************************************************/

    /* 视图模型 */
    XncutListView *M_MaterialView = NULL; /* 素材视图 */
    /********************************************************************************************************/
};

#endif // XNCUT_MATERIAL_FIELD_WIDGET_H
