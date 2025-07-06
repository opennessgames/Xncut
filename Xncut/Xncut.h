/*
 * @Author: xixi_
 * @Date: 2025-07-02 12:35:01
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-02 13:39:04
 * @FilePath: /Xncut/Xncut/Xncut.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_H
#define XNCUT_H

#include <QMainWindow>
#include <QPropertyAnimation>
#include <QStackedWidget>
#include "XncutClipHall/XncutClipHallWidget.h"

class Xncut : public QMainWindow
{
    Q_OBJECT

public:
    Xncut(QWidget *Parent = NULL);
    ~Xncut();

private:
private slots:

protected:
signals:

private:
    /* 窗口动画 */
    QPropertyAnimation *M_WindowAnimation = NULL;
    /********************************************************************************************************/

    /* 主部件 */
    QStackedWidget *M_CentralStackedWidget = NULL; /* 中心控件 */
    /********************************************************************************************************/

    /* 核心部件 */
    /* 大厅 */
    XncutClipHallWidget *M_ClipHallWidget = NULL;
    /********************************************************************************************************/
};

#endif // XNCUT_H
