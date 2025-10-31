/*
 * @Author: xixi_
 * @Date: 2025-10-30 23:26:50
 * @LastEditors: xixi_
 * @LastEditTime: 2025-10-30 23:26:57
 * @FilePath: /XncutUI/Test/XncutTitleBar/XncutTitleBarWidget.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutTitleBarWidget.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QToolBar>

XncutTitleBarWidget::XncutTitleBarWidget(QWidget *Parent)
    : QWidget(Parent)
{
    /* 初始化 */
    /* 主布局 */
    QHBoxLayout *MainLayout = new QHBoxLayout(); /* 水平布局 */
    M_LogoLabel = new QLabel();                  /* LOGO标签 */
    M_MainToolBar = new QToolBar();              /* 工具栏 */
    /********************************************************************************************************/

    /* 设置属性 */
    /* LOGO标签 */
    M_LogoLabel->setFixedSize(110, height());
    M_LogoLabel->setAlignment(Qt::AlignLeft);
    /* 工具栏 */
    M_MainToolBar->setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum));
    M_MainToolBar->layout()->setContentsMargins(0, 0, 0, 0);
    M_MainToolBar->layout()->setSpacing(8);
    /********************************************************************************************************/

    /* 设置布局 */
    /* 主布局 */
    MainLayout->setContentsMargins(0, 0, 0, 0);
    MainLayout->setSpacing(0);
    MainLayout->addWidget(M_LogoLabel);
    MainLayout->addWidget(M_MainToolBar);
    /********************************************************************************************************/

    setLayout(MainLayout);
    /********************************************************************************************************/

    /* 连接信号槽 */
    /********************************************************************************************************/
}

XncutTitleBarWidget::~XncutTitleBarWidget()
{
}

void XncutTitleBarWidget::SetLogoPixmap(QPixmap LogoPixmap)
{
    if (LogoPixmap.isNull())
    {
        M_LogoLabel->setText("XNCUT LOGO");
        return;
    }
    M_LogoLabel->setPixmap(LogoPixmap.scaled(M_LogoLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

QToolBar *XncutTitleBarWidget::GetToolBar()
{
    return M_MainToolBar;
}
