/*
 * @Author: xixi_
 * @Date: 2025-07-07 10:46:40
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-08 21:58:04
 * @FilePath: /Xncut/Xncut/XncutProjectManager/XncutProjectCardDelegate.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutProjectCardDelegate.h"
#include <QPainter>

#define CARD_WIDTH 340
#define CARD_HEIGHT 180

XncutProjectCardDelegate::XncutProjectCardDelegate(QObject *Parent)
    : QStyledItemDelegate(Parent)
{
}

const QSize XncutProjectCardDelegate::GetSizeHint()
{
    return QSize(CARD_WIDTH, CARD_HEIGHT);
}

void XncutProjectCardDelegate::paint(QPainter *Painter, const QStyleOptionViewItem &Option, const QModelIndex &Index) const
{
    /* 需要的参数 */
    /* 基础绘制参数 */
    int X = Option.rect.x();
    int Y = Option.rect.y();
    int Width = Option.rect.width();
    int Height = Option.rect.height();

    /* 画家参数 */
    Painter->setBrush(QColor(0, 0, 0));          /* 笔刷颜色 */
    Painter->setPen(QColor(255, 255, 255, 255)); /* 钢笔颜色 */

    /* 绘制 */
    /* 绘制封面图 */
    Painter->drawPixmap(X + ((Width - CARD_WIDTH) >> 1), Y, qvariant_cast<QIcon>(Index.data(Qt::DecorationRole)).pixmap(QSize(CARD_WIDTH, CARD_HEIGHT))); /* 调节X以居中 */
    /* 绘制边框 */
    // Painter->drawLine(QPoint(X, 0), QPoint(X, Height));
    // Painter->drawLine(QPoint(X + Width, 0), QPoint(X + Width, Height));
    /* 绘制日期大小 */
    Painter->drawRect(X, Y, Width, 27);
    Painter->drawText(X + 5, Y + 20,
                      QString("%1 | %2").arg(qvariant_cast<QString>(Index.data(PRO_CARD_DATA_DATE)),
                                             qvariant_cast<QString>(Index.data(PRO_CARD_DATA_SIZE))));
    /* 绘制标题 */
    Painter->drawRect(X, Y + Height - 27, Width, 27);
    Painter->drawText(X + 5, Y + Height - 27, Width - 10, 27, 0,
                      QString("本地工程 | %1").arg(qvariant_cast<QString>(Index.data(Qt::DisplayRole)))); /* 工程标题 */
    /* 是否被选择 */
    if (Option.state.testFlag(QStyle::State_Selected))
    {
        Painter->setPen(Qt::NoPen);
        Painter->setBrush(QColor(255, 0, 0, 50));
        Painter->drawRect(X, Y, Width, Height);
    }
}

QSize XncutProjectCardDelegate::sizeHint(const QStyleOptionViewItem &Option, const QModelIndex &Index) const
{
    return QSize(CARD_WIDTH, CARD_HEIGHT);
}
