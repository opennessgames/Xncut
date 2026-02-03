/*
 * @Author: xixi_
 * @Date: 2025-07-14 18:48:50
 * @LastEditors: xixi_
 * @LastEditTime: 2026-02-04 02:32:19
 * @FilePath: /XncutUI/Src/XncutEditor/XncutBins/XncutBinsWidget.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_BINS_WIDGET_H
#define XNCUT_BINS_WIDGET_H

#include <QTabWidget>
#include "XncutMaterialField/XncutMaterialFieldWidget.h"
#include "../../XncutPublicStyle/XncutCustomTabStyle.h"

class XncutBinsWidget : public QTabWidget
{
    Q_OBJECT
private:
    /********************************************************************************************************/

public:
    explicit XncutBinsWidget(QWidget *Parent = NULL);
    ~XncutBinsWidget();
    /********************************************************************************************************/

private:
    /********************************************************************************************************/

private slots:
    /********************************************************************************************************/

protected:
    /* 重载事件 */
    /********************************************************************************************************/

signals:
    /********************************************************************************************************/

private:
    /**
     * @brief 共享样式
     * TODO: 单例模式
     **/
    XncutCustomTabStyle *M_ShareCustomTabStyle = NULL;
    /********************************************************************************************************/

    /* 内容 */
    XncutMaterialFieldWidget *M_MaterialFieldWidget = NULL; /* 素材领域 */
    /********************************************************************************************************/
};

#endif // XNCUT_BINS_WIDGET_H
