/*
 * @Author: xixi_
 * @Date: 2025-07-06 19:03:28
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-07 10:55:07
 * @FilePath: /Xncut/Xncut/XncutProjectManager/XncutProjectCreateWidget.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_PROJECT_CREATE_WIDGET_H
#define XNCUT_PROJECT_CREATE_WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QGroupBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include "../XncutPublicWidget/XncutSwitchButton.h"
#include <QPushButton>

class XncutProjectCreateWidget : public QWidget
{
    Q_OBJECT
public:
    explicit XncutProjectCreateWidget(QWidget *Parent = NULL);

private:
private slots:
    /* 高级设置 */
    /* [开关控件] 自动保存开关发生改变 */
    void AutoSaveSwitchButtonCheckedChanged(bool Checked);
    /********************************************************************************************************/

protected:
signals:
private:
    /* 主布局 */
    QGridLayout *M_MainLayout = NULL; /* 网格布局 */
    /********************************************************************************************************/

    /* 基础设置 */
    QGroupBox *M_BaseFormGroupBox = NULL;    /* 基础设置组盒子 */
    QFormLayout *M_BaseFormLayout = NULL;    /* 表单布局 */
    QLineEdit *M_ProjectNameLineEdit = NULL; /* 工程名称行文本编辑器 */
    QLineEdit *M_ProjectPathLineEdit = NULL; /* 工程路径行文本编辑器 */
    QTextEdit *M_DescriptionTextEdit = NULL; /* 工程描述多行编辑器 */
    /********************************************************************************************************/

    /* 工程设置 */
    QGroupBox *M_ProjectConfigFormGroupBox = NULL; /* 工程配置组盒子 */
    QFormLayout *M_ProjectConfigFormLayout = NULL; /* 表单布局 */
    QComboBox *M_ResolutionComboBox = NULL;        /* 分辨率组合框 */
    QComboBox *M_AspectRatioComboBox = NULL;       /* 宽高比组合框 */
    QComboBox *M_VideoBitsComboBox = NULL;         /* 位深度组合框 */
    QComboBox *M_FrameRateComboBox = NULL;         /* 帧率组合框 */
    /********************************************************************************************************/

    /* 高级设置 */
    QGroupBox *M_AdvancedFormGroupBox = NULL;          /* 高级设置组盒子 */
    QFormLayout *M_AdvancedFormLayout = NULL;          /* 表单布局 */
    QLineEdit *M_CachePathLineEdit = NULL;             /* 工程缓存路径行文本编辑器 */
    QComboBox *M_ColorSpaceComboBox = NULL;            /* 色彩空间组合框 */
    XncutSwitchButton *M_ProxyClipSwitchButton = NULL; /* 代理剪辑滑动开关 */
    XncutSwitchButton *M_CopyClipSwitchButton = NULL;  /* 复制剪辑滑动开关 */
    QHBoxLayout *M_AutoSaveLayout = NULL;              /* 自动保存布局 */
    XncutSwitchButton *M_AutoSaveSwitchButton = NULL;  /* 自动保存滑动开关 */
    QLineEdit *M_IntervalLineEdit = NULL;              /* 自动保存秒数行编辑框 */
    /********************************************************************************************************/

    /* 创建工程 */
    QVBoxLayout *M_CreateProjectLayout = NULL; /* 布局 */
    QPushButton *M_CreateProjectButton = NULL; /* 创建工程按钮 */
    /********************************************************************************************************/
};

#endif // XNCUT_PROJECT_CREATE_WIDGET_H
