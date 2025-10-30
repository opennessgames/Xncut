/*
 * @Author: xixi_
 * @Date: 2025-10-30 22:03:58
 * @LastEditors: xixi_
 * @LastEditTime: 2025-10-30 22:47:05
 * @FilePath: /XncutUI/Test/XncutAbstractTabItemView/XncutAbstractTabItemViewWidget.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_ABSTRACT_TAB_ITEM_VIEW_WIDGET_H
#define XNCUT_ABSTRACT_TAB_ITEM_VIEW_WIDGET_H

#include <QWidget>

class QGridLayout;
class QTabBar;
class QToolBar;
class QAbstractItemView;

/**
 * @brief 抽象标签视图部件
 * @note 具有QTabBar, QToolBar和QAbstractItemView的混合部件.
 * @note 已截掉QTabBar滚轮事件, 你无须再次使用事件过滤器来实现.
 * @note 我们发现多数类都上述三个部件, 都有组合且都禁止了滚轮事件, 故有此抽象类.
 **/
class XncutAbstractTabItemViewWidget : public QWidget
{
    Q_OBJECT
private:
    /********************************************************************************************************/

public:
    explicit XncutAbstractTabItemViewWidget(QAbstractItemView *AbstractItemView, QWidget *Parent = NULL);
    ~XncutAbstractTabItemViewWidget();
    /********************************************************************************************************/

    /**
     * @brief 获取QTabBar
     * @return QTabBar *
     **/
    QTabBar *GetTabBar();

    /**
     * @brief 获取ToolBar
     * @return QToolBar *
     **/
    QToolBar *GetToolBar();

    /**
     * @brief 获取视图
     * @return QAbstractItemView *
     **/
    QAbstractItemView *GetView();
    /********************************************************************************************************/

    /**
     * @brief TabBar发生内容改变
     * @note 通过QTabBar的改变信号与此函数建立连接实现的
     **/
    virtual void TabBarCurrentChange(int Index) = 0;
    /********************************************************************************************************/

public slots:
    /********************************************************************************************************/

private:
    /********************************************************************************************************/

private slots:
    /********************************************************************************************************/

protected:
    /* 重载事件 */
    /* 任意的QObject和任意事件*/
    bool eventFilter(QObject *Watched, QEvent *Event);
    /********************************************************************************************************/

signals:
    /********************************************************************************************************/

private:
    /* 左侧区域 */
    /* TabBar */
    QTabBar *M_TabBar = NULL;
    /********************************************************************************************************/

    /* 右侧区域 */
    QToolBar *M_ToolBar = NULL;                   /* 工具栏 */
    QAbstractItemView *M_AbstractItemView = NULL; /* Item视图 */
    /********************************************************************************************************/
};

#endif // XNCUT_ABSTRACT_TAB_ITEM_VIEW_WIDGET_H
