/*
 * @Author: xixi_
 * @Date: 2025-10-25 13:21:27
 * @LastEditors: xixi_
 * @LastEditTime: 2025-10-25 13:21:35
 * @FilePath: /XncutUI/Test/XncutThreeLayerLayout/XncutThreeLayerLayoutWidget.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_THREE_LAYER_LAYOUT_WIDGET_H
#define XNCUT_THREE_LAYER_LAYOUT_WIDGET_H

#include <QWidget>

class QLabel;
class QToolBar;
class XncutThreeLayerLayoutWidget : public QWidget
{
    Q_OBJECT
private:
    /********************************************************************************************************/

public:
    explicit XncutThreeLayerLayoutWidget(QWidget *CentralWidget, QWidget *Parent = NULL);
    ~XncutThreeLayerLayoutWidget();
    /********************************************************************************************************/

    /**
     * @brief 获取顶部标签
     * @note QLabel *
     **/
    QLabel *GetTopTitleLabel();

    /**
     * @brief 获取底部工具栏
     * @note QToolBar *
     **/
    QToolBar *GetBottomToolBar();
    /********************************************************************************************************/

public slots:
    /********************************************************************************************************/

private:
    /**
     * @brief 获取顶部标题调色板
     * @note 设计这个接口的目的是为了后续的方便
     **/
    QPalette GetTopTitleLabelPalette();
    /********************************************************************************************************/

private slots:
    /********************************************************************************************************/

protected:
    /* 事件重载 */
    /********************************************************************************************************/

signals:
    /********************************************************************************************************/

private:
    /* 内容部件 */
    QLabel *M_TopTitleLabel;          /* 顶部标题 */
    QToolBar *M_BottomToolBar = NULL; /* 底部工具
    /********************************************************************************************************/
};

#endif // XNCUT_THREE_LAYER_LAYOUT_WIDGET_H
