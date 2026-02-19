/*
 * @Author: xixi_
 * @Date: 2025-07-24 18:32:39
 * @LastEditors: xixi_
 * @LastEditTime: 2026-02-19 16:31:13
 * @FilePath: /Xncut/Xncut/XncutClipHall/XncutClipHallInfoWidget.h
 * Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_CLIP_HALL_INFO_WIDGET_H
#define XNCUT_CLIP_HALL_INFO_WIDGET_H

#include <QWidget>

class XncutClipHallInfoWidget : public QWidget
{
    Q_OBJECT
private:
    /********************************************************************************************************/

public:
    explicit XncutClipHallInfoWidget(QWidget *Parent = NULL);
    ~XncutClipHallInfoWidget();
    XncutClipHallInfoWidget(const XncutClipHallInfoWidget&) = delete;
    XncutClipHallInfoWidget& operator=(const XncutClipHallInfoWidget&) = delete;
    /********************************************************************************************************/

    /********************************************************************************************************/

public slots:
    /********************************************************************************************************/

private:
    /********************************************************************************************************/

private slots:
    /********************************************************************************************************/

protected:
    /* 事件重载 */
    /* 绘制事件 */
    void paintEvent(QPaintEvent *Event) override;
    /********************************************************************************************************/

signals:
    /********************************************************************************************************/

private:
    /* 背景 */
    QPixmap M_InfoBgPixmap = QPixmap();
    /********************************************************************************************************/
};

#endif // XNCUT_CLIP_HALL_INFO_WIDGET_H