/*
 * @Author: xixi_
 * @Date: 2025-07-07 10:46:44
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-08 21:23:07
 * @FilePath: /Xncut/Xncut/XncutProjectManager/XncutProjectCardDelegate.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_PROJECT_CARD_DELEGATE_H
#define XNCUT_PROJECT_CARD_DELEGATE_H

#include <QStyledItemDelegate>

class XncutProjectCardDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    /* 工程卡片数据 */
    typedef enum
    {
        PRO_CARD_DATA_SIZE = Qt::UserRole + 1, /* 工程大小 */
        PRO_CARD_DATA_DATE,                    /* 工程日期 */
    } ProjectCardData;

    /* 构造 */
    explicit XncutProjectCardDelegate(QObject *Parent = NULL);

    /* 获取大小 */
    static const QSize GetSizeHint();
    /********************************************************************************************************/

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

#endif // XNCUT_PROJECT_CARD_DELEGATE_H
