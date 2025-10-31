/*
 * @Author: xixi_
 * @Date: 2025-10-30 22:26:02
 * @LastEditors: xixi_
 * @LastEditTime: 2025-10-30 23:51:57
 * @FilePath: /XncutUI/Test/XncutAbstractTabItemView/XncutMyAssetsWidget.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutMyAssetsWidget.h"
#include <QTabBar>
#include <QToolBar>
#include <QLineEdit>
#include <QStandardItemModel>
#include <QAbstractItemView>
#include <QListView>
#include <QComboBox>
#include <QLayout>

XncutMyAssetsWidget::XncutMyAssetsWidget(QWidget *Parent)
    : XncutAbstractTabItemViewWidget(new QListView(), Parent)
{
    M_StandardItemModel = new QStandardItemModel();
    /********************************************************************************************************/

    GetTabBar()->addTab("类型1");
    GetTabBar()->addTab("类型2");
    /********************************************************************************************************/

    QLineEdit *LineEdit = new QLineEdit();
    LineEdit->setPlaceholderText("键入任意关键词搜索......");
    LineEdit->setClearButtonEnabled(true);

    QComboBox *ComboBox = new QComboBox();
    ComboBox->addItem("升序");
    ComboBox->addItem("倒序");

    GetToolBar()->layout()->setContentsMargins(0, 0, 0, 0);
    GetToolBar()->addWidget(LineEdit);
    GetToolBar()->addWidget(ComboBox);
    /********************************************************************************************************/

    GetView()->setModel(M_StandardItemModel);
    /********************************************************************************************************/

    for (int i = 0; i < 10; ++i)
    {
        QStandardItem *StandardItem = new QStandardItem();
        StandardItem->setText(QString("测试Item第%1号").arg(i));
        M_StandardItemModel->appendRow(StandardItem);
    }
    /********************************************************************************************************/
}

XncutMyAssetsWidget::~XncutMyAssetsWidget()
{
    delete M_StandardItemModel;
    M_StandardItemModel = NULL;
}

void XncutMyAssetsWidget::TabBarCurrentChange(int Index)
{
    qDebug() << "改变" << Index;
}
