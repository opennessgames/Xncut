/*
 * @Author: xixi_
 * @Date: 2025-07-14 18:48:54
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-14 18:52:08
 * @FilePath: /XncutUI/Src/XncutEditor/XncutBins/XncutBinsWidget.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutBinsWidget.h"

XncutBinsWidget::XncutBinsWidget(QWidget *Parent)
    : QTabWidget(Parent)
{

    /* 初始化 */
    /* 共享样式 */
    M_ShareCustomTabStyle = new XncutCustomTabStyle();

    /* 内容 */
    M_MaterialFieldWidget = new XncutMaterialFieldWidget(); /* 素材领域 */
    /********************************************************************************************************/

    M_MaterialFieldWidget->GetTabBar()->setStyle(M_ShareCustomTabStyle);
    /********************************************************************************************************/

    /* 添加到标签 */
    addTab(M_MaterialFieldWidget, "素材领域");
    addTab(new QWidget(), "管理源");
    addTab(new QWidget(), "文本");
    addTab(new QWidget(), "字幕");
    addTab(new QWidget(), "音乐");
    addTab(new QWidget(), "效果");
    addTab(new QWidget(), "滤镜");
    addTab(new QWidget(), "调色");
    addTab(new QWidget(), "转场");
    addTab(new QWidget(), "贴纸");
    addTab(new QWidget(), "数字人");
    addTab(new QWidget(), "历史记录");
    addTab(new QWidget(), "一键三连");
    /********************************************************************************************************/
}

XncutBinsWidget::~XncutBinsWidget()
{
    delete M_ShareCustomTabStyle;
    M_ShareCustomTabStyle = NULL;
}
