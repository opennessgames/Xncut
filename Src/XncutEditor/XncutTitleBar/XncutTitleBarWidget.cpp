/*
 * @Author: xixi_
 * @Date: 2025-07-14 18:24:13
 * @LastEditors: xixi_
 * @LastEditTime: 2026-02-04 02:49:18
 * @FilePath: /XncutUI/Src/XncutEditor/XncutTitleBar/XncutTitleBarWidget.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutTitleBarWidget.h"
#include <QActionGroup>

XncutTitleBarWidget::XncutTitleBarWidget(QWidget *Parent)
    : QToolBar(Parent)
{
    /* 初始化 */
    /* 左侧 */
    /* LOGO */
    M_LOGO = new QLabel(); /* LOGO标签 */
    /* 菜单 */
    M_TitleBarMenu = new QMenuBar(); /* 标题栏菜单 */
    /********************************************************************************************************/

    /* 右侧动作 */
    M_EditorModleActionGroup = new QActionGroup(this); /* 按钮组合 */

    /* 添加动作 */
    addWidget(M_LOGO); /* 将LOGO添加到布局 */
    /* 菜单 */
    addWidget(M_TitleBarMenu); /* 将标题栏菜单添加到布局 */
    QAction *M_EditorButton = addAction(QIcon("://Images/Editor/TitleBar/Editor.png"), "编辑");
    M_EditorButton->setCheckable(true);
    M_EditorButton->setActionGroup(M_EditorModleActionGroup);
    QAction *M_ColorButton = addAction(QIcon("://Images/Editor/TitleBar/Colorize.png"), "颜色");
    M_ColorButton->setCheckable(true);
    M_ColorButton->setActionGroup(M_EditorModleActionGroup);
    QAction *M_EffectButton = addAction(QIcon("://Images/Editor/TitleBar/Effect.png"), "效果");
    M_EffectButton->setCheckable(true);
    M_EffectButton->setActionGroup(M_EditorModleActionGroup);
    QAction *M_AudioButton = addAction(QIcon("://Images/Editor/TitleBar/Audio.png"), "音频");
    M_AudioButton->setCheckable(true);
    M_AudioButton->setActionGroup(M_EditorModleActionGroup);
    addSeparator();
    M_ReturnAction = addAction(QIcon("://Images/Editor/TitleBar/ReturnHall.png"), "返回大厅"); /* 返回大厅 */

    /* 默认编辑模式被选中 */
    M_EditorButton->setChecked(true);
    /********************************************************************************************************/

    /* 设置属性 */
    /* LOGO */
    M_LOGO->setFixedSize(125, 35);
    M_LOGO->setPixmap(QPixmap("://Images/Editor/TitleBar/XLinuxTitle.png").scaled(125, 35, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    /* 菜单 */
    M_TitleBarMenu->addMenu("文件(F)");
    M_TitleBarMenu->addMenu("项目(P)");
    M_TitleBarMenu->addMenu("编辑(E)");
    M_TitleBarMenu->addMenu("剪辑(C)");
    M_TitleBarMenu->addMenu("序列(S)");
    M_TitleBarMenu->addMenu("标记(M)");
    M_TitleBarMenu->addMenu("图形(G)");
    M_TitleBarMenu->addMenu("窗口(W)");
    M_TitleBarMenu->addMenu("布局(L)");
    M_TitleBarMenu->addMenu("导出(E)");
    M_TitleBarMenu->addMenu("帮助(H)");
    /********************************************************************************************************/

    /* 图标在文字旁 */
    setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    /********************************************************************************************************/
}

XncutTitleBarWidget::~XncutTitleBarWidget()
{
}
