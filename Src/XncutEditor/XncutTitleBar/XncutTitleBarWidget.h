/*
 * @Author: xixi_
 * @Date: 2025-07-14 18:23:57
 * @LastEditors: xixi_
 * @LastEditTime: 2026-02-04 02:44:56
 * @FilePath: /XncutUI/Src/XncutEditor/XncutTitleBar/XncutTitleBarWidget.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_TITLE_BAR_WIDGET_H
#define XNCUT_TITLE_BAR_WIDGET_H

#include <QToolBar>
#include <QLabel>
#include <QMenuBar>

class XncutTitleBarWidget : public QToolBar
{
    Q_OBJECT
private:
public:
    explicit XncutTitleBarWidget(QWidget *Parent = NULL);
    ~XncutTitleBarWidget();

private:
    /********************************************************************************************************/

private slots:

protected:
signals:

private:
    /* 左侧 */
    /* LOGO */
    QLabel *M_LOGO = NULL; /* LOGO标签 */
    /* 菜单 */
    QMenuBar *M_TitleBarMenu = NULL; /* 标题栏菜单 */
    /* 右侧导航 */
    QActionGroup *M_EditorModleActionGroup = NULL; /* 动作组合 */
    /********************************************************************************************************/

private:
    /* 动作 */
    QAction *M_EditorButton = NULL; /* 编辑模式 */
    QAction *M_ColorButton = NULL;  /* 颜色模式 */
    QAction *M_EffectButton = NULL; /* 效果模式 */
    QAction *M_AudioButton = NULL;  /* 音频模式 */
    QAction *M_ReturnAction = NULL; /* 返回大厅 */
    /********************************************************************************************************/

    friend class XncutEditorWidget;
};

#endif // XNCUT_TITLE_BAR_WIDGET_H
