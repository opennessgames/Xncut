/*
 * @Author: xixi_
 * @Date: 2025-10-30 22:26:02
 * @LastEditors: xixi_
 * @LastEditTime: 2025-10-30 22:26:11
 * @FilePath: /XncutUI/Test/XncutAbstractTabItemView/XncutMyAssetsWidget.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_MY_ASSETS_WIDGET_H
#define XNCUT_MY_ASSETS_WIDGET_H

#include "XncutAbstractTabItemViewWidget.h"

class QStandardItemModel;
class XncutMyAssetsWidget : public XncutAbstractTabItemViewWidget
{
    Q_OBJECT
private:
    /********************************************************************************************************/

public:
    explicit XncutMyAssetsWidget(QWidget *Parent = NULL);
    ~XncutMyAssetsWidget();
    /********************************************************************************************************/

    /********************************************************************************************************/

public slots:
    /********************************************************************************************************/

private:
    /********************************************************************************************************/

private slots:
    /********************************************************************************************************/

protected:
    /* 事件重载 */
    void TabBarCurrentChange(int Index);
    /********************************************************************************************************/

signals:
    /********************************************************************************************************/

private:
    QStandardItemModel *M_StandardItemModel;
    /********************************************************************************************************/
};

#endif // XNCUT_MY_ASSETS_WIDGET_H
