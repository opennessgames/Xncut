/*
 * @Author: xixi_
 * @Date: 2024-12-14 20:09:49
 * @LastEditors: xixi_
 * @LastEditTime: 2024-12-14 21:44:56
 * @FilePath: /pubg-xncut-mvp/XncutMvp/PubgXncutMvp.h
 * Copyright (c) 2020-2024 by xixi_ , All Rights Reserved.
 */
#ifndef PUBGXNCUTMVP_H
#define PUBGXNCUTMVP_H

#include <QMainWindow>

class PubgXncutMvp : public QMainWindow
{
    Q_OBJECT

public:
    PubgXncutMvp(QWidget *parent = nullptr);
    ~PubgXncutMvp();

    /* 设置QDockWidget基本参数 */
    void SetDockPro(QDockWidget *XDock, int XWidth, int XHeight, int X, int Y);
};
#endif // PUBGXNCUTMVP_H
