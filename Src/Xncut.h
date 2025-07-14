/*
 * @Author: xixi_
 * @Date: 2025-07-14 16:54:37
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-14 17:41:48
 * @FilePath: /XncutUI/Src/Xncut.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_H
#define XNCUT_H

#include <QMainWindow>
#include <QStackedWidget>
#include "XncutClipHall/XncutClipHallWidget.h"
#include "XncutProjectManager/XncutProjectManagerWidget.h"
#include "XncutEditor/XncutEditorWidget.h"

class Xncut : public QMainWindow
{
    Q_OBJECT
private:
public:
    Xncut(QWidget *Parent = NULL);
    ~Xncut();

private:
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
    void closeEvent(QCloseEvent *Event) override;
    /********************************************************************************************************/

signals:

private:
    /* 主部件 */
    QStackedWidget *M_CentralStackedWidget = NULL; /* 中心控件 */
    /********************************************************************************************************/

    /* 内容部件 */
    XncutClipHallWidget *M_ClipHallWidget = NULL;             /* 剪辑大厅 */
    XncutProjectManagerWidget *M_ProjectManagerWidget = NULL; /* 工程管理器 */
        XncutEditorWidget *M_EditorWidget = NULL;                 /* 编辑器 */
    /********************************************************************************************************/
};

#endif // XNCUT_H
