/*
 * @Author: xixi_
 * @Date: 2025-07-02 20:11:09
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-08 19:59:06
 * @FilePath: /Xncut/Xncut/XncutClipHall/XncutRecentProjectCardDelegate.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_RECENT_PROJECT_CARD_DELEGATE_H
#define XNCUT_RECENT_PROJECT_CARD_DELEGATE_H

#include <QStyledItemDelegate>

class XncutRecentProjectCardDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    /* 最近工程卡片数据 */
    typedef enum
    {
        PRO_CARD_DATA_DESCRIPTION = Qt::UserRole + 1, /* 描述 */
        PRO_CARD_DATA_SIZE,                           /* 大小 */
    } ProjectCardData;

    /* 构造 */
    explicit XncutRecentProjectCardDelegate(QObject *Parent = NULL);

private:
private slots:
protected:
    /* 重载事件 */
    /* 绘制 */
    void paint(QPainter *Painter, const QStyleOptionViewItem &Option, const QModelIndex &Index) const override;

    /* 设置大小 */
    QSize sizeHint(const QStyleOptionViewItem &Option, const QModelIndex &Index) const override;
    /********************************************************************************************************/

signals:

private:
};

#endif // XNCUT_RECENT_PROJECT_CARD_DELEGATE_H
