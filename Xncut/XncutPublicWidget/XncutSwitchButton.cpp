/*
 * @Author: xixi_
 * @Date: 2025-07-06 20:04:11
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-06 20:07:44
 * @FilePath: /Xncut/Xncut/XncutPublicWidget/XncutSwitchButton.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutSwitchButton.h"
#include <qpainter.h>
#include <qevent.h>
#include <qtimer.h>
#include <qdebug.h>
#include <qpainterpath.h>

XncutSwitchButton::XncutSwitchButton(QWidget *Parent)
    : QWidget(Parent)
{
    checked = false;
    buttonStyle = ButtonStyle_Rect;

    bgColorOff = QColor(225, 225, 225);
    bgColorOn = QColor(250, 250, 250);

    sliderColorOff = QColor(100, 100, 100);
    sliderColorOn = QColor(100, 184, 255);

    textColorOff = QColor(255, 255, 255);
    textColorOn = QColor(10, 10, 10);

    textOff = "";
    textOn = "";

    imageOff = ":/image/btncheckoff1.png";
    imageOn = ":/image/btncheckon1.png";

    space = 2;
    rectRadius = 5;

    step = width() / 50;
    startX = 0;
    endX = 0;

    timer = new QTimer(this);
    timer->setInterval(5);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateValue()));

    setFont(QFont("Microsoft Yahei", 10));
}

XncutSwitchButton::~XncutSwitchButton()
{
}

void XncutSwitchButton::mousePressEvent(QMouseEvent *)
{
    checked = !checked;
    emit checkedChanged(checked);

    // 每次移动的步长为宽度的 50分之一
    step = width() / 50;

    // 状态切换改变后自动计算终点坐标
    if (checked)
    {
        if (buttonStyle == ButtonStyle_Rect)
        {
            endX = width() - width() / 2;
        }
        else if (buttonStyle == ButtonStyle_CircleIn)
        {
            endX = width() - height();
        }
        else if (buttonStyle == ButtonStyle_CircleOut)
        {
            endX = width() - height() + space;
        }
    }
    else
    {
        endX = 0;
    }

    timer->start();
}

void XncutSwitchButton::resizeEvent(QResizeEvent *)
{
    // 每次移动的步长为宽度的 50分之一
    step = width() / 50;

    // 尺寸大小改变后自动设置起点坐标为终点
    if (checked)
    {
        if (buttonStyle == ButtonStyle_Rect)
        {
            startX = width() - width() / 2;
        }
        else if (buttonStyle == ButtonStyle_CircleIn)
        {
            startX = width() - height();
        }
        else if (buttonStyle == ButtonStyle_CircleOut)
        {
            startX = width() - height() + space;
        }
    }
    else
    {
        startX = 0;
    }

    update();
}

void XncutSwitchButton::paintEvent(QPaintEvent *)
{
    // 绘制准备工作,启用反锯齿
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    if (buttonStyle == ButtonStyle_Image)
    {
        // 绘制图片
        drawImage(&painter);
    }
    else
    {
        // 绘制背景
        drawBg(&painter);
        // 绘制滑块
        drawSlider(&painter);
        // 绘制文字
        drawText(&painter);
    }
}

void XncutSwitchButton::drawBg(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);

    if (!checked)
    {
        painter->setBrush(bgColorOff);
    }
    else
    {
        painter->setBrush(bgColorOn);
    }

    if (buttonStyle == ButtonStyle_Rect)
    {
        painter->drawRoundedRect(rect(), rectRadius, rectRadius);
    }
    else if (buttonStyle == ButtonStyle_CircleIn)
    {
        QRect rect(0, 0, width(), height());
        // 半径为高度的一半
        int radius = rect.height() / 2;
        // 圆的宽度为高度
        int circleWidth = rect.height();

        QPainterPath path;
        path.moveTo(radius, rect.left());
        path.arcTo(QRectF(rect.left(), rect.top(), circleWidth, circleWidth), 90, 180);
        path.lineTo(rect.width() - radius, rect.height());
        path.arcTo(QRectF(rect.width() - rect.height(), rect.top(), circleWidth, circleWidth), 270, 180);
        path.lineTo(radius, rect.top());

        painter->drawPath(path);
    }
    else if (buttonStyle == ButtonStyle_CircleOut)
    {
        QRect rect(space, space, width() - space * 2, height() - space * 2);
        painter->drawRoundedRect(rect, rectRadius, rectRadius);
    }

    painter->restore();
}

void XncutSwitchButton::drawSlider(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);

    if (!checked)
    {
        painter->setBrush(sliderColorOff);
    }
    else
    {
        painter->setBrush(sliderColorOn);
    }

    if (buttonStyle == ButtonStyle_Rect)
    {
        int sliderWidth = width() / 2 - space * 2;
        int sliderHeight = height() - space * 2;
        QRect sliderRect(startX + space, space, sliderWidth, sliderHeight);
        painter->drawRoundedRect(sliderRect, rectRadius, rectRadius);
    }
    else if (buttonStyle == ButtonStyle_CircleIn)
    {
        QRect rect(0, 0, width(), height());
        int sliderWidth = rect.height() - space * 2;
        QRect sliderRect(startX + space, space, sliderWidth, sliderWidth);
        painter->drawEllipse(sliderRect);
    }
    else if (buttonStyle == ButtonStyle_CircleOut)
    {
        QRect rect(0, 0, width() - space, height() - space);
        int sliderWidth = rect.height();
        QRect sliderRect(startX, space / 2, sliderWidth, sliderWidth);
        painter->drawEllipse(sliderRect);
    }

    painter->restore();
}

void XncutSwitchButton::drawText(QPainter *painter)
{
    painter->save();

    if (!checked)
    {
        painter->setPen(textColorOff);
        painter->drawText(width() / 2, 0, width() / 2 - space, height(), Qt::AlignCenter, textOff);
    }
    else
    {
        painter->setPen(textColorOn);
        painter->drawText(0, 0, width() / 2 + space * 2, height(), Qt::AlignCenter, textOn);
    }

    painter->restore();
}

void XncutSwitchButton::drawImage(QPainter *painter)
{
    painter->save();

    QPixmap pix;

    if (!checked)
    {
        pix = QPixmap(imageOff);
    }
    else
    {
        pix = QPixmap(imageOn);
    }

    // 自动等比例平滑缩放居中显示
    int targetWidth = pix.width();
    int targetHeight = pix.height();
    pix = pix.scaled(targetWidth, targetHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    int pixX = rect().center().x() - targetWidth / 2;
    int pixY = rect().center().y() - targetHeight / 2;
    QPoint point(pixX, pixY);
    painter->drawPixmap(point, pix);

    painter->restore();
}

void XncutSwitchButton::updateValue()
{
    if (checked)
    {
        if (startX < endX)
        {
            startX = startX + step;
        }
        else
        {
            startX = endX;
            timer->stop();
        }
    }
    else
    {
        if (startX > endX)
        {
            startX = startX - step;
        }
        else
        {
            startX = endX;
            timer->stop();
        }
    }

    update();
}

void XncutSwitchButton::setChecked(bool checked)
{
    if (this->checked != checked)
    {
        this->checked = checked;
        emit checkedChanged(checked);
        update();
    }
}

void XncutSwitchButton::setButtonStyle(XncutSwitchButton::ButtonStyle buttonStyle)
{
    this->buttonStyle = buttonStyle;
    update();
}

void XncutSwitchButton::setBgColor(QColor bgColorOff, QColor bgColorOn)
{
    this->bgColorOff = bgColorOff;
    this->bgColorOn = bgColorOn;
    update();
}

void XncutSwitchButton::setSliderColor(QColor sliderColorOff, QColor sliderColorOn)
{
    this->sliderColorOff = sliderColorOff;
    this->sliderColorOn = sliderColorOn;
    update();
}

void XncutSwitchButton::setTextColor(QColor textColorOff, QColor textColorOn)
{
    this->textColorOff = textColorOff;
    this->textColorOn = textColorOn;
    update();
}

void XncutSwitchButton::setText(QString textOff, QString textOn)
{
    this->textOff = textOff;
    this->textOn = textOn;
    update();
}

void XncutSwitchButton::setImage(QString imageOff, QString imageOn)
{
    this->imageOff = imageOff;
    this->imageOn = imageOn;
    update();
}

void XncutSwitchButton::setSpace(int space)
{
    this->space = space;
    update();
}

void XncutSwitchButton::setRectRadius(int rectRadius)
{
    this->rectRadius = rectRadius;
    update();
}