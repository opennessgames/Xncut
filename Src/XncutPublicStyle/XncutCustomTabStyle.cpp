/*
 * @Author: xixi_
 * @Date: 2025-07-14 18:54:20
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-14 18:54:34
 * @FilePath: /XncutUI/Src/XncutPublicStyle/XncutCustomTabStyle.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutCustomTabStyle.h"

void XncutCustomTabStyle::DrawTabRect(QPainter *Painter, const QRect &Rect, const QColor &Color) const
{

    Painter->save();
    Painter->setBrush(QBrush(Color));
    Painter->drawRect(Rect); /* 画矩形 */
    Painter->restore();
}

QSize XncutCustomTabStyle::sizeFromContents(ContentsType Type, const QStyleOption *Option, const QSize &Size, const QWidget *Widget) const
{

    QSize ContentsSize = QCommonStyle::sizeFromContents(Type, Option, Size, Widget);

    if (Type == QStyle::CT_TabBarTab)
    {
        ContentsSize.transpose();
        ContentsSize.rwidth() = 100; /* 设置每个tabBar中item的大小 */
        ContentsSize.rheight() = 35;
    }

    return ContentsSize;
}

void XncutCustomTabStyle::drawControl(ControlElement Element, const QStyleOption *Option, QPainter *Painter, const QWidget *Widget) const
{
    if (Element == CE_TabBarTabLabel)
    {
        return;
    }

    if (const QStyleOptionTab *Tab = qstyleoption_cast<const QStyleOptionTab *>(Option))
    {
        QRect AllRect = Tab->rect;
        QFont Font = Painter->font();
        AllRect.setWidth(AllRect.width() - 5);
        AllRect.setHeight(AllRect.height() - 5);

        /*
         * 根据状态选择颜色
         TODO: Hover状态的配色不是很好
         */
        QColor TabColor;
        if (Tab->state & QStyle::State_Selected)
        {
            TabColor = QColor(0xD4, 0x3F, 0x77, 0x7F); /* 选中状态 */
            Font.setBold(true);
        }
        else if (Tab->state & QStyle::State_MouseOver)
        {
            TabColor = QColor(0x00, 0x4E, 0xA1, 0x7F); /* Hover状态 */
            Font.setBold(false);
        }
        else
        {
            TabColor = QColor(0xFC, 0x51, 0x85, 0xFF); /* 普通状态 */
            Font.setBold(false);
        }

        /* 绘制矩形 */
        DrawTabRect(Painter, AllRect, TabColor);

        /* 设置文本 */
        QTextOption TextOption;
        TextOption.setAlignment(Qt::AlignCenter);

        /* 设置字体 */
        Painter->setFont(Font);
        /* 钢笔颜色 */
        Painter->setPen(0xFFFFFF);
        /* 绘制文本 */
        Painter->drawText(AllRect, Tab->text, TextOption);
    }

    if (Element == CE_TabBarTab)
    {
        QCommonStyle::drawControl(Element, Option, Painter, Widget);
    }
}
