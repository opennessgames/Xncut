/*
 * @Author: xixi_
 * @Date: 2025-07-14 16:54:37
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-14 17:03:58
 * @FilePath: /XncutUI/Src/Xncut.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_H
#define XNCUT_H

#include <QMainWindow>

class Xncut : public QMainWindow
{
    Q_OBJECT

public:
    Xncut(QWidget *Parent = NULL);
    ~Xncut();
};

#endif // XNCUT_H
