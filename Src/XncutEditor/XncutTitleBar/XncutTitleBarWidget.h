/*
 * @Author: xixi_
 * @Date: 2025-07-14 18:23:57
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-14 18:26:10
 * @FilePath: /XncutUI/Src/XncutEditor/XncutTitleBar/XncutTitleBarWidget.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_TITLE_BAR_WIDGET_H
#define XNCUT_TITLE_BAR_WIDGET_H

#include <QHBoxLayout>
#include <QLabel>
#include <QMenuBar>
#include <QButtonGroup>
#include <QPushButton>

class XncutTitleBarWidget : public QHBoxLayout
{
    Q_OBJECT
private:
public:
    explicit XncutTitleBarWidget(QWidget *Parent = NULL);
    ~XncutTitleBarWidget();

private:
    /* 初始化按钮 */
    void InitButton(QPushButton *Button, int IconSize, QString StyleSheet, bool IsAddGroup, int Index = -1);
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
    QButtonGroup *M_EditorModleButtonGroup = NULL; /* 按钮组合 */
    /********************************************************************************************************/

public:
    /* 按钮 */
    QPushButton *M_EditorButton = NULL; /* 编辑模式 */
    QPushButton *M_ColorButton = NULL;  /* 颜色模式 */
    QPushButton *M_EffectButton = NULL; /* 效果模式 */
    QPushButton *M_AudioButton = NULL;  /* 音频模式 */
    QFrame *M_Divider = NULL;           /* 分割线 */
    QPushButton *M_ReturnButton = NULL; /* 返回大厅 */
    /********************************************************************************************************/
};

#endif // XNCUT_TITLE_BAR_WIDGET_H
