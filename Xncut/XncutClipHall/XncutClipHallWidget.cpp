/*
 * @Author: xixi_
 * @Date: 2025-04-21 20:10:34
 * @LastEditors: xixi_
 * @LastEditTime: 2026-02-19 16:36:58
 * @FilePath: /Xncut/Xncut/XncutClipHall/XncutClipHallWidget.cpp
 * Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
 */

#include "XncutClipHallWidget.h"
#include <QGridLayout>
#include <XncutCardWidget.h>
#include <QPushButton>
#include "XncutClipHallInfoWidget.h"

XncutClipHallWidget::XncutClipHallWidget(QWidget *Parent)
    : QWidget(Parent)
{
    /* 初始化 */
    QGridLayout *MainLayout = new QGridLayout();

    /* 左侧 */
    M_CurrProjectCardWidget = new XncutCardWidget("当前选择的工程:", "还没工程, 点击封面创建一个吧^_^");
    QPushButton *StartButton = new QPushButton();
    XncutClipHallInfoWidget *InfoWidget = new XncutClipHallInfoWidget();

    /* 右侧 */
    /********************************************************************************************************/

    /* 设置属性 */
    /* 左侧部件 */
    M_CurrProjectCardWidget->setFixedSize(QSize(370, 190));
    M_CurrProjectCardWidget->SetImage("");
    M_CurrProjectCardWidget->setStatusTip("显示已经选择工程的封面和标题, 点击以选择或者创建工程~");

    QFont StartButtonFont;
    StartButtonFont.setPixelSize(38);
    StartButton->setFixedSize(QSize(370, 80));
    StartButton->setIconSize(QSize(80, 80));
    StartButton->setIcon(QIcon(":/Images/ClipHall/StartIcon.png"));
    StartButton->setFont(StartButtonFont);
    StartButton->setText("START!");
    StartButton->setStatusTip("点击开始创作~");

    InfoWidget->setFixedWidth(370);
    InfoWidget->setMinimumHeight(300);
    InfoWidget->setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding));
    /********************************************************************************************************/

    /* 设置布局 */
    MainLayout->addWidget(M_CurrProjectCardWidget, 0, 0, 1, 1);
    MainLayout->addWidget(StartButton, 1, 0, 1, 1);
    MainLayout->addWidget(InfoWidget, 2, 0, 1, 1);
    /********************************************************************************************************/

    setLayout(MainLayout);
    /********************************************************************************************************/

    /* 连接信号槽 */
    /********************************************************************************************************/
}

XncutClipHallWidget::~XncutClipHallWidget()
{
}
