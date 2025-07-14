/*
 * @Author: xixi_
 * @Date: 2025-07-14 17:23:57
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-14 17:30:13
 * @FilePath: /XncutUI/Src/XncutPublicWidget/XncutListView.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutListView.h"
#include <QResizeEvent>

XncutListView::XncutListView(QWidget *Parent)
    : QListView(Parent)
{
    /* 初始化 */
    /* 空空如也标签 */
    M_EmptyLabel = new QLabel();
    /********************************************************************************************************/

    /* 设置属性 */
    /* 空空如也标签 */
    M_EmptyLabel->move(0, 0);
    M_EmptyLabel->setAlignment(Qt::AlignCenter);
    M_EmptyLabel->setParent(this);
    /********************************************************************************************************/
}

void XncutListView::SetEmptyPixmap(QString EmptyImgUrl, int Size)
{
    M_EmptyLabel->resize(QSize(Size, Size));
    M_EmptyLabel->setPixmap(QPixmap(EmptyImgUrl).scaled(Size, Size));
}

void XncutListView::SetEmptyPixmapVisible(bool Visible)
{
    M_EmptyLabel->setVisible(Visible);
}

void XncutListView::resizeEvent(QResizeEvent *Event)
{
    /* 将标签缩放到和视图一样大 */
    M_EmptyLabel->resize(Event->size());

    /* 继续向下传递 */
    QListView::resizeEvent(Event);
}

void XncutListView::mousePressEvent(QMouseEvent *Event)
{
    /* 鼠标下无效的Item */
    if (!indexAt(Event->pos()).isValid())
    {
        clearSelection(); /* 清除全部选择 */
        return;
    }

    /* 继续向下传递 */
    QListView::mousePressEvent(Event);
}
