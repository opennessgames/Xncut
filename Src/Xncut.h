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
#include <QStackedWidget>
#include "XncutClipHall/XncutClipHallWidget.h"

class Xncut : public QMainWindow
{
    Q_OBJECT
private:
public:
    Xncut(QWidget *Parent = NULL);
    ~Xncut();

private:
private slots:

protected:
    /* 重载事件 */
    /* 关闭事件 */
    void closeEvent(QCloseEvent *Event) override;
    /********************************************************************************************************/

signals:

private:
    /* 主部件 */
    QStackedWidget *M_CentralStackedWidget = NULL; /* 中心控件 */
    /********************************************************************************************************/

    /* 内容部件 */
    XncutClipHallWidget *M_ClipHallWidget = NULL; /* 剪辑大厅 */
    /********************************************************************************************************/
};

#endif // XNCUT_H
