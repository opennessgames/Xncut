/*
 * @Author: xixi_
 * @Date: 2025-08-15 01:25:54
 * @LastEditors: xixi_
 * @LastEditTime: 2025-08-15 01:26:09
 * @FilePath: /XncutUI/Src/XncutEditor/XncutProjectMonitor/XncutVideoWidget.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_VIDEO_WIDGET_H
#define XNCUT_VIDEO_WIDGET_H

#include <QWidget>

class XncutVideoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit XncutVideoWidget(QWidget *Parent = NULL);
    ~XncutVideoWidget();
    /********************************************************************************************************/

    /* 横幅 */
    /* 横幅内容 */
    void SetBanners(QString Content);

    /* 横幅字体大小(保留API) */
    void SetBannersContentFontSize(int Size);
    /********************************************************************************************************/

private:
    /********************************************************************************************************/

private slots:
    /********************************************************************************************************/

protected:
    /* 重载事件 */
    /* 绘制事件 */
    void paintEvent(QPaintEvent *Event) override;
    /********************************************************************************************************/

signals:
    /********************************************************************************************************/

private:
    /* 横幅文案 */
    int M_FontSize = 45;                                   /* 横幅大小 */
    QFont M_PainterFont = QFont("小扣折纸体", M_FontSize); /* 横幅字体 */
    QString M_BannersContent = "";                         /* 横幅内容 */
    int M_TextWidth = 0;                                   /* 横幅内容宽度 */
    int M_TextHeight = 0;                                  /* 横幅内容高度 */
    /********************************************************************************************************/

    /********************************************************************************************************/
};

#endif // XNCUT_VIDEO_WIDGET_H
