/*
 * @Author: xixi_
 * @Date: 2025-08-15 02:37:43
 * @LastEditors: xixi_
 * @LastEditTime: 2026-02-04 02:33:32
 * @FilePath: /XncutUI/Src/XncutEditor/XncutInspector/XncutInspectorWidget.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_INSPECTOR_WIDGET_H
#define XNCUT_INSPECTOR_WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include "XncutProjectArgWidget.h"
#include <QScrollArea>

/**
 * @brief 检查器部件
 * @note 早期很简单, 后来发现存在一些问题, 后续考虑使用`视图模型`架构去改进
 * TODO: M/V架构优化
 **/
class XncutInspectorWidget : public QWidget
{
    Q_OBJECT
private:
    /********************************************************************************************************/

public:
    explicit XncutInspectorWidget(QWidget *Parent = NULL);
    ~XncutInspectorWidget();
    /********************************************************************************************************/

    /********************************************************************************************************/

private:
    /********************************************************************************************************/

private slots:
    /********************************************************************************************************/

protected:
    /* 重载事件 */
    /* 鼠标指针进入时 */
    void enterEvent(QEnterEvent *Event) override;
    /********************************************************************************************************/

signals:
    /* 请求显示底部提示 */
    void HasShowBottonTipsRequest(QString Tips);
    /********************************************************************************************************/

private:
    /* 主布局 */
    QVBoxLayout *M_MainLayout = NULL;
    /********************************************************************************************************/

    /* 标题标签 */
    QLabel *M_TitleLabel = NULL;
    /********************************************************************************************************/

    /* 滚动容器 */
    QScrollArea *M_InspectorScrollArea = NULL;
    /********************************************************************************************************/

    /* 内容 */
    XncutProjectArgWidget *M_ProjectArgWidget = NULL; /* 工程参数 */
    /********************************************************************************************************/
};

#endif // XNCUT_INSPECTOR_WIDGET_H