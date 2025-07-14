/*
 * @Author: xixi_
 * @Date: 2025-07-14 18:54:05
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-14 18:54:38
 * @FilePath: /XncutUI/Src/XncutPublicStyle/XncutCustomTabStyle.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_CUSTOM_TAB_STYLE_H
#define XNCUT_CUSTOM_TAB_STYLE_H

/*
 * 主要应用场景: QTabWidget需要将标签设置到左右两侧时
 * 也会减少很多的代码,
 */

#include <QPainter>
#include <QCommonStyle>
#include <QStyleOptionTab>

class XncutCustomTabStyle : public QCommonStyle
{
private:
    /* 绘制矩形 */
    void DrawTabRect(QPainter *Painter, const QRect &Rect, const QColor &Color) const;
    /********************************************************************************************************/

protected:
    /* 重载函数 */
    /* 确定元素尺寸 */
    QSize sizeFromContents(ContentsType Type, const QStyleOption *Option, const QSize &Size, const QWidget *Widget) const override;

    /* 绘制具体的控制元素 */
    void drawControl(ControlElement Element, const QStyleOption *Option, QPainter *Painter, const QWidget *Widget) const override;
    /********************************************************************************************************/
};

#endif // XNCUT_CUSTOM_TAB_STYLE_H
