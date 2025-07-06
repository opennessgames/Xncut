/*
 * @Author: xixi_
 * @Date: 2025-07-02 20:09:07
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-03 23:09:52
 * @FilePath: /Xncut/Xncut/XncutClipHall/XncutRecentProjectCardDelegate.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutRecentProjectCardDelegate.h"
#include <QPainter>

XncutRecentProjectCardDelegate::XncutRecentProjectCardDelegate(QObject *Parent)
    : QStyledItemDelegate(Parent)
{
}

void XncutRecentProjectCardDelegate::paint(QPainter *Painter, const QStyleOptionViewItem &Option, const QModelIndex &Index) const
{
    /* 缓存 */
    /* 区域 */
    QRect Rect = Option.rect; /* 整体区域 */
    /* 序号 */
    QPoint NumberPoint(Rect.x() + 10, Rect.y() + 10); /* 序号位置 */
    QSize NumberSize(60, 60);                         /* 序号背景大小 */
    /* 封面 */
    QSize CoverSize(120, 60); /* 大小 */
    /* 文案 */
    int TextPositionX = NumberPoint.x() + 200;

    /* 设置画家参数 */
    Painter->setBrush(QColor(0, 0, 0, 20));
    Painter->setPen(Option.state & QStyle::State_Selected ? QColor(255, 255, 255, 200) : /* 选择时的颜色 */
                        Qt::NoPen                                                        /* 没有选择时的颜色 */
    );
    /* 绘制矩形 */
    /* 绘制背景矩形 */
    Painter->drawRect(QRect(Rect.x(), Rect.y(), Rect.width() - 1, Rect.height() - 1));
    /* 绘制序号 */
    Painter->setPen(QColor(255, 255, 255, 255));
    Painter->setBrush(QColor(255, 0, 255, 255));
    Painter->drawRect(QRect(NumberPoint, NumberSize));
    Painter->drawText(QRect(NumberPoint, NumberSize), Qt::AlignCenter | Qt::AlignVCenter, QString::number(Index.row()));
    /* 绘制封面 */
    Painter->drawPixmap(QRect(QPoint(NumberPoint.x() + 70, NumberPoint.y()), CoverSize), qvariant_cast<QIcon>(Index.data(Qt::DecorationRole)).pixmap(QSize(CoverSize)));
    /* 绘制工程标题 */
    Painter->drawText(QRect(QPoint(TextPositionX, NumberPoint.y()), QSize(1000, 30)), Qt::AlignTop, qvariant_cast<QString>(Index.data(Qt::DisplayRole)));
    /* 绘制工程描述 */
    Painter->drawText(QRect(QPoint(TextPositionX, NumberPoint.y() + 30), QSize(1000, 30)), Qt::AlignTop, qvariant_cast<QString>(Index.data(PRO_CARD_DATA_DESCRIPTION)));
}

QSize XncutRecentProjectCardDelegate::sizeHint(const QStyleOptionViewItem &Option, const QModelIndex &Index) const
{
    return QSize(Option.rect.width(), 80);
}
