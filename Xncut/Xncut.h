/*
 * @Author: xixi_
 * @Date: 2025-07-02 12:35:01
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-07 20:05:45
 * @FilePath: /Xncut/Xncut/Xncut.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_H
#define XNCUT_H
/*
    https://dickintheworld.com/tg.php
*/
#include <QMainWindow>
#include <QPropertyAnimation>
#include <QStackedWidget>
#include "XncutClipHall/XncutClipHallWidget.h"
#include "XncutProjectManager/XncutProjectManagerWidget.h"

class Xncut : public QMainWindow
{
    Q_OBJECT

public:
    Xncut(QWidget *Parent = NULL);
    ~Xncut();

private:
    /* [数据持久化] 将数据保存到磁盘 */
    void Sync();
    /********************************************************************************************************/

private slots:
    /* 跳转界面 */
    /* 跳转到大厅 */
    void JmpHall();

    /* 跳转到工程管理 */
    void JmpProjectManager();

    /* 跳转到编辑器 */
    void JmpEditor();
    /********************************************************************************************************/

protected:
    /* 重载事件 */
    /* 关闭事件 */
    void closeEvent(QCloseEvent *Event);
    /********************************************************************************************************/

signals:

private:
    /* 窗口动画 */
    QPropertyAnimation *M_WindowAnimation = NULL;
    /********************************************************************************************************/

    /* 主部件 */
    QStackedWidget *M_CentralStackedWidget = NULL; /* 中心控件 */
    /********************************************************************************************************/

    /* 核心部件 */
    XncutClipHallWidget *M_ClipHallWidget = NULL;             /* 大厅 */
    XncutProjectManagerWidget *M_ProjectManagerWidget = NULL; /* 工程管理器 */
    /********************************************************************************************************/
};

#endif // XNCUT_H
