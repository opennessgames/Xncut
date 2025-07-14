/*
 * @Author: xixi_
 * @Date: 2025-07-14 17:45:47
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-14 17:50:37
 * @FilePath: /XncutUI/Src/XncutProjectManager/XncutProjectCreateWidget.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutProjectCreateWidget.h"
#include <QLabel>

XncutProjectCreateWidget::XncutProjectCreateWidget(QWidget *Parent)
    : QWidget(Parent)
{
    /* 初始化 */
    /* 主布局 */
    M_MainLayout = new QGridLayout(); /* 网格布局 */

    /* 基础设置 */
    M_BaseFormGroupBox = new QGroupBox();    /* 基础设置组盒子 */
    M_BaseFormLayout = new QFormLayout();    /* 表单布局 */
    M_ProjectNameLineEdit = new QLineEdit(); /* 工程名称行文本编辑器 */
    M_ProjectPathLineEdit = new QLineEdit(); /* 工程路径行文本编辑器 */
    M_DescriptionTextEdit = new QTextEdit(); /* 工程描述多行编辑器 */

    /* 工程配置 */
    M_ProjectConfigFormGroupBox = new QGroupBox(); /* 工程配置组盒子 */
    M_ProjectConfigFormLayout = new QFormLayout(); /* 表单布局 */
    M_ResolutionComboBox = new QComboBox();        /* 分辨率组合框 */
    M_AspectRatioComboBox = new QComboBox();       /* 宽高比组合框 */
    M_VideoBitsComboBox = new QComboBox();         /* 位深度组合框 */
    M_FrameRateComboBox = new QComboBox();         /* 帧率组合框 */

    /* 高级设置 */
    M_AdvancedFormGroupBox = new QGroupBox();          /* 高级设置组盒子 */
    M_AdvancedFormLayout = new QFormLayout();          /* 表单布局 */
    M_CachePathLineEdit = new QLineEdit();             /* 工程缓存路径行文本编辑器 */
    M_ColorSpaceComboBox = new QComboBox();            /* 色彩空间组合框 */
    M_ProxyClipCheckBox = new QCheckBox(); /* 代理剪辑滑动开关 */
    M_CopyClipCheckBox = new QCheckBox();  /* 复制剪辑滑动开关 */
    M_AutoSaveLayout = new QHBoxLayout();              /* 自动保存布局 */
    M_AutoSaveCheckBox= new QCheckBox();  /* 自动保存滑动开关 */
    M_IntervalLineEdit = new QLineEdit();              /* 自动保存秒数行编辑框 */

    /* 创建工程 */
    M_CreateProjectLayout = new QVBoxLayout();
    M_CreateProjectButton = new QPushButton("创建工程"); /* 创建工程按钮 */
    /********************************************************************************************************/

    /* 设置属性 */
    /* 基础设置 */
    /* 基础设置组盒子 */
    M_BaseFormGroupBox->setTitle("基础");
    /* 工程名称行文本编辑器 */
    M_ProjectNameLineEdit->setPlaceholderText("键入工程名称");
    /* 工程路径行文本编辑器 */
    M_ProjectPathLineEdit->setEnabled(false);
    M_ProjectPathLineEdit->setToolTip("工程路径: 不可编辑");
    M_ProjectPathLineEdit->setPlaceholderText("工程路径根据工程名称自动调整");
    /* 工程描述多行编辑器 */
    M_DescriptionTextEdit->setPlaceholderText("键入描述");

    /* 工程配置 */
    /* 工程配置组盒子 */
    M_ProjectConfigFormGroupBox->setTitle("工程配置");
    /* 工程缓存路径行文本行编辑器 */
    M_CachePathLineEdit->setEnabled(false);
    M_CachePathLineEdit->setToolTip("工程缓存路径: 不可编辑");
    M_CachePathLineEdit->setPlaceholderText("工程缓存路径根据工程名称自动调整");
    /* 色彩空间组合框 */
    M_ColorSpaceComboBox->setToolTip("色彩空间");
    /* 代理剪辑 */
    // M_ProxyClipCheckBox->setFixedSize(90, 35);
    /* 复制剪辑 */
    // M_CopyClipCheckBox->setFixedSize(90, 35);
    /* 自动保存 */
    // M_AutoSaveCheckBox->setFixedSize(90, 35);
    /* 自动保存秒数行编辑框 */
    M_IntervalLineEdit->setEnabled(false);
    M_IntervalLineEdit->setAlignment(Qt::AlignCenter);
    M_IntervalLineEdit->setPlaceholderText("整数");
    M_IntervalLineEdit->setFixedWidth(90);

    /* 高级设置 */
    /* 高级设置组盒子 */
    M_AdvancedFormGroupBox->setTitle("高级设置");
    /* 分辨率组合框 */
    M_ResolutionComboBox->setToolTip("分辨率");
    /* 宽高比组合框 */
    M_AspectRatioComboBox->setToolTip("宽高比");
    /* 位深度组合框 */
    M_VideoBitsComboBox->setToolTip("位深度");
    /* 帧率组合框 */
    M_FrameRateComboBox->setToolTip("帧率");

    /* 创建工程 */
    /* 创建工程按钮 */
    M_CreateProjectButton->setStyleSheet("font-size:25px;");
    /********************************************************************************************************/

    /* 设置布局 */
    /* 基础布局 */
    M_BaseFormGroupBox->setLayout(M_BaseFormLayout);
    M_BaseFormLayout->addRow(new QLabel("工程名称"), M_ProjectNameLineEdit);
    M_BaseFormLayout->addRow(new QLabel("工程路径"), M_ProjectPathLineEdit);
    M_BaseFormLayout->addRow(new QLabel("工程描述"), M_DescriptionTextEdit);

    /* 工程配置布局 */
    M_ProjectConfigFormGroupBox->setLayout(M_ProjectConfigFormLayout);
    M_ProjectConfigFormLayout->addRow(new QLabel("视频分辨率"), M_ResolutionComboBox);
    M_ProjectConfigFormLayout->addRow(new QLabel("视频宽高比"), M_AspectRatioComboBox);
    M_ProjectConfigFormLayout->addRow(new QLabel("视频位深度"), M_VideoBitsComboBox);
    M_ProjectConfigFormLayout->addRow(new QLabel("视频帧率"), M_FrameRateComboBox);
    M_ProjectConfigFormLayout->addRow(new QLabel(R"(Tips:并不是分辨率越高越清晰,帧率越高越流畅
相反,在某些情况下可能会有副作用~
1字节信息占8位，可以表示0到255之间的数字,
除了8位,还有10位和16位深度,16位深度的
范围是0到65535,这意味着能够呈现更丰富
的色彩信息.未来,我们将支持更多位深度的格式.)"));

    /* 自动保存布局 */
    M_AutoSaveLayout->addWidget(M_AutoSaveCheckBox, 0);
    M_AutoSaveLayout->addWidget(new QLabel("每隔"));
    M_AutoSaveLayout->addWidget(M_IntervalLineEdit);
    M_AutoSaveLayout->addWidget(new QLabel("秒保存一次"));
    M_AutoSaveLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));

    /* 高级设置布局 */
    M_AdvancedFormGroupBox->setLayout(M_AdvancedFormLayout);
    M_AdvancedFormLayout->addRow(new QLabel("工程缓存路径"), M_CachePathLineEdit);
    M_AdvancedFormLayout->addRow(new QLabel("色彩空间"), M_ColorSpaceComboBox);
    M_AdvancedFormLayout->addRow(new QLabel("代理剪辑"), M_ProxyClipCheckBox);
    M_AdvancedFormLayout->addRow(new QLabel("复制剪辑"), M_CopyClipCheckBox);
    M_AdvancedFormLayout->addRow(new QLabel("自动保存"), M_AutoSaveLayout);

    /* 创建工程布局 */
    M_CreateProjectLayout->setContentsMargins(0, 0, 15, 15);
    M_CreateProjectLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
    M_CreateProjectLayout->addWidget(new QLabel("大厅有更多选项喵~"));
    M_CreateProjectLayout->addWidget(M_CreateProjectButton);

    /* 主布局 */
    M_MainLayout->setRowStretch(0, 1);
    M_MainLayout->setRowStretch(1, 1);
    M_MainLayout->setColumnStretch(0, 2);
    M_MainLayout->setColumnStretch(1, 2);
    M_MainLayout->setSpacing(8);
    M_MainLayout->addWidget(M_BaseFormGroupBox, 0, 0);
    M_MainLayout->addWidget(M_ProjectConfigFormGroupBox, 0, 1);
    M_MainLayout->addWidget(M_AdvancedFormGroupBox, 1, 0);
    M_MainLayout->addLayout(M_CreateProjectLayout, 1, 1, Qt::AlignRight);
    /********************************************************************************************************/

    setLayout(M_MainLayout);
    /********************************************************************************************************/
}
