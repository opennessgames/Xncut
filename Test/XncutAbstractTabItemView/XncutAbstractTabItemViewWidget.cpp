/*
 * @Author: xixi_
 * @Date: 2025-10-30 22:03:58
 * @LastEditors: xixi_
 * @LastEditTime: 2025-10-30 22:47:35
 * @FilePath: /XncutUI/Test/XncutAbstractTabItemView/XncutAbstractTabItemViewWidget.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutAbstractTabItemViewWidget.h"
#include <QGridLayout>
#include <QTabBar>
#include <QToolBar>
#include <QAbstractItemView>
#include <QEvent>

XncutAbstractTabItemViewWidget::XncutAbstractTabItemViewWidget(QAbstractItemView *AbstractItemView, QWidget *Parent)
    : QWidget(Parent)
{
    /* 初始化 */
    /* 主布局 */
    QGridLayout *MainLayout = new QGridLayout();

    /* 左侧区域 */
    /* TabBar */
    M_TabBar = new QTabBar();

    /* 右侧区域 */
    M_ToolBar = new QToolBar();            /* 工具栏 */
    M_AbstractItemView = AbstractItemView; /* Item视图 */
    /********************************************************************************************************/

    /* 设置属性 */
    /* 左侧区域 */
    /* TabBar */
    M_TabBar->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Ignored)); /* 大小策略: 宽固定,高忽略掉 */
    M_TabBar->setExpanding(false);                                                  /* 不扩展 */
    M_TabBar->setShape(QTabBar::RoundedWest);                                       /* 标签在左侧 */
    M_TabBar->installEventFilter(this);

    /* 右侧区域 */
    /* 工具栏 */
    M_ToolBar->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum));
    M_ToolBar->layout()->setSpacing(5);
    /* Item视图 */
    /* 这里可以设置视图属性, 比如在A地方, B地方, 甚至所有地方都开启了交错显示, 那么就可以在这里设置, 一劳永逸! */
    M_AbstractItemView->setAlternatingRowColors(true);
    /********************************************************************************************************/

    /* 设置布局 */
    MainLayout->setContentsMargins(5, 5, 5, 5);
    MainLayout->setSpacing(2);
    MainLayout->addWidget(M_TabBar, 0, 0, 2, 1);
    MainLayout->addWidget(M_ToolBar, 0, 1, 1, 1);
    MainLayout->addWidget(M_AbstractItemView, 1, 1, 1, 1);
    /********************************************************************************************************/

    setLayout(MainLayout);
    /********************************************************************************************************/

    /* 链接信号槽 */
    /* TabBar */
    connect(M_TabBar, &QTabBar::currentChanged, this, &XncutAbstractTabItemViewWidget::TabBarCurrentChange);
    /********************************************************************************************************/
}

XncutAbstractTabItemViewWidget::~XncutAbstractTabItemViewWidget()
{
}

QTabBar *XncutAbstractTabItemViewWidget::GetTabBar()
{
    return M_TabBar;
}

QToolBar *XncutAbstractTabItemViewWidget::GetToolBar()
{
    return M_ToolBar;
}

QAbstractItemView *XncutAbstractTabItemViewWidget::GetView()
{
    return M_AbstractItemView;
}

bool XncutAbstractTabItemViewWidget::eventFilter(QObject *Watched, QEvent *Event)
{
    /* 截掉QTabBar滚轮事件 */
    if ((QTabBar *)Watched && Event->type() == QEvent::Wheel)
    {
        return true;
    }

    /* 继续 */
    return QObject::eventFilter(Watched, Event);
}
