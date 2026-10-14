/*
 * @Author: xixi_
 * @Date: 2026-07-25 22:58:16
 * @LastEditors: xixi_
 * @LastEditTime: 2026-10-14 14:31:44
 * @FilePath: /Xncut/Src/XncutGammaDemo/XncutImageWidget.h
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
 */

#ifndef PUBG_XNCUT_IMAGE_WIDGET_H
#define PUBG_XNCUT_IMAGE_WIDGET_H

#include <QWidget>

/**
 * @brief The XncutImageWidget class
 * @brief 图片部件
 * @note
 * @note
 **/
class XncutImageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit XncutImageWidget(QWidget *parent = nullptr);
    ~XncutImageWidget() override;
    XncutImageWidget(const XncutImageWidget &) = delete;
    XncutImageWidget &operator=(const XncutImageWidget &) = delete;
    XncutImageWidget(const XncutImageWidget &&) = delete;
    XncutImageWidget &operator=(const XncutImageWidget &&) = delete;

    /* [OpenXncut] */

    void setImages(const QImage &img);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QImage m_img;
};

#endif /* PUBG_XNCUT_IMAGE_WIDGET_H */
