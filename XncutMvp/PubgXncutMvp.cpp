/*
 * @Author: xixi_
 * @Date: 2024-12-14 20:10:02
 * @LastEditors: xixi_
 * @LastEditTime: 2024-12-14 21:43:57
 * @FilePath: /pubg-xncut-mvp/XncutMvp/PubgXncutMvp.cpp
 * Copyright (c) 2020-2024 by xixi_ , All Rights Reserved.
 */
#include "PubgXncutMvp.h"
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QDockWidget>

PubgXncutMvp::PubgXncutMvp(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(850, 555);                          /* 固定窗口大小 */
    setWindowTitle(tr("pubg:xncut mvp"));            /* 设置窗口标题 */
    QDockWidget *XLeftDock = new QDockWidget(this);  /* 左半边区域 */
    QDockWidget *XRightDock = new QDockWidget(this); /* 右半边区域 */
    SetDockPro(XLeftDock, 215, 555, 0, 0);           /* 设置左半边区域参数 */
    SetDockPro(XRightDock, 635, 555, 215, 0);        /* 设置右半边区域参数 */
    QPixmap XLogoPxMap(":/Images/XncutMvp.png");
    QLabel *XLogo = new QLabel(this); /* Logo */
    XLogo->setPixmap(XLogoPxMap.scaled(100, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    XLogo->move(20, 5); /* 改变Logo位置 */
    XLeftDock->setWidget(XLogo);
}

PubgXncutMvp::~PubgXncutMvp() {}

void PubgXncutMvp::SetDockPro(QDockWidget *XDock, int XWidth, int XHeight, int X, int Y)
{
    XDock->show();                        /* 显示 */
    XDock->setFixedSize(XWidth, XHeight); /* 固定大小 */
    XDock->move(X, Y);                    /* 位置 */
}
