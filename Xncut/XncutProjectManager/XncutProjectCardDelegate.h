/*
 * @Author: xixi_
 * @Date: 2025-07-07 10:46:44
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-07 10:47:01
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
    explicit XncutProjectCardDelegate(QObject *Parent = NULL);

signals:
};

#endif // XNCUT_PROJECT_CARD_DELEGATE_H
