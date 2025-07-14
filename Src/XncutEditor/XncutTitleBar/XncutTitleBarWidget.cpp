/*
 * @Author: xixi_
 * @Date: 2025-07-14 18:24:13
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-14 18:26:06
 * @FilePath: /XncutUI/Src/XncutEditor/XncutTitleBar/XncutTitleBarWidget.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutTitleBarWidget.h"

XncutTitleBarWidget::XncutTitleBarWidget(QWidget *Parent)
    : QHBoxLayout(Parent)
{
    /* 初始化 */
    /* 左侧 */
    /* LOGO */
    M_LOGO = new QLabel(); /* LOGO标签 */
    /* 菜单 */
    M_TitleBarMenu = new QMenuBar(); /* 标题栏菜单 */

    /* 右侧导航 */
    M_EditorModleButtonGroup = new QButtonGroup(); /* 按钮组合 */
    /* 按钮 */
    M_EditorButton = new QPushButton(QIcon("://Images/Editor/TitleBar/Editor.png"), "编辑");         /* 编辑模式 */
    M_ColorButton = new QPushButton(QIcon("://Images/Editor/TitleBar/Colorize.png"), "颜色");        /* 颜色模式 */
    M_EffectButton = new QPushButton(QIcon("://Images/Editor/TitleBar/Effect.png"), "效果");         /* 效果模式 */
    M_AudioButton = new QPushButton(QIcon("://Images/Editor/TitleBar/Audio.png"), "音频");           /* 音频模式 */
    M_Divider = new QFrame();                                                                        /* 分割线 */
    M_ReturnButton = new QPushButton(QIcon("://Images/Editor/TitleBar/ReturnHall.png"), "返回大厅"); /* 返回大厅 */
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

    /* 按钮 */
    InitButton(M_EditorButton, 30, "QPushButton:checked{background-color:rgb(0,0,255);}", true, 0);
    InitButton(M_ColorButton, 30, "QPushButton:checked{background-color:rgb(0,0,255);}", true, 1);
    InitButton(M_EffectButton, 30, "QPushButton:checked{background-color:rgb(0,0,255);}", true, 2);
    InitButton(M_AudioButton, 30, "QPushButton:checked{background-color:rgb(0,0,255);}", true, 3);
    /* 分割线 */
    M_Divider->setFixedWidth(3);
    M_Divider->setStyleSheet("background-color:rgb(255,255,255);");
    M_Divider->setFrameShape(QFrame::VLine);
    M_Divider->setFrameShadow(QFrame::Sunken);
    /* 返回大厅按钮 */
    InitButton(M_ReturnButton, 30, "", false);
    /* 默认编辑模式被选中 */
    M_EditorButton->setChecked(true);
    /********************************************************************************************************/

    /* 布局 */
    setContentsMargins(0, 0, 0, 0); /* 只保留左右两边的间距 */
    setSpacing(5);                  /* 间隔 */
    addWidget(M_LOGO);              /* 将LOGO添加到布局 */
    /* 菜单 */
    addWidget(M_TitleBarMenu); /* 将标题栏菜单添加到布局 */
    /* 弹簧 */
    /* 右侧导航 */
    addWidget(M_EditorButton, 0, Qt::AlignRight);
    addWidget(M_ColorButton, 0, Qt::AlignRight);
    addWidget(M_EffectButton, 0, Qt::AlignRight);
    addWidget(M_AudioButton, 0, Qt::AlignRight);
    addWidget(M_Divider, 0, Qt::AlignRight);
    addWidget(M_ReturnButton, 0, Qt::AlignRight);
    /********************************************************************************************************/
}

XncutTitleBarWidget::~XncutTitleBarWidget()
{
    delete M_EditorModleButtonGroup;
    M_EditorModleButtonGroup = NULL;
}

void XncutTitleBarWidget::InitButton(QPushButton *Button, int IconSize, QString StyleSheet, bool IsAddGroup, int Index)
{
    if (!Button)
    {
        return;
    }
    if (IsAddGroup)
    {
        M_EditorModleButtonGroup->addButton(Button, Index);
        Button->setCheckable(true);
    }

    Button->setFocusPolicy(Qt::NoFocus);
    Button->setStyleSheet(StyleSheet);
    Button->setIconSize(QSize(IconSize, IconSize));
}
