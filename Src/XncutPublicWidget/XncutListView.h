/*
 * @Author: xixi_
 * @Date: 2025-07-14 17:23:45
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-14 17:30:17
 * @FilePath: /XncutUI/Src/XncutPublicWidget/XncutListView.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_LIST_VIEW_H
#define XNCUT_LIST_VIEW_H

#include <QListView>
#include <QLabel>

class XncutListView : public QListView
{
    Q_OBJECT
public:
    explicit XncutListView(QWidget *Parent = NULL);

    /* 设置空空如也的提示 */
    void SetEmptyPixmap(QString EmptyImgUrl, int Size);

    /* 是否要绘制空空如也Pixmap,天哪,这样好麻烦 */
    void SetEmptyPixmapVisible(bool Visible);
    /********************************************************************************************************/

private:
private slots:

protected:
    /* 重载事件 */
    /* 缩放事件 */
    void resizeEvent(QResizeEvent *Event) override;
    /********************************************************************************************************/

    /* 鼠标事件 */
    /* 鼠标点击按下 */
    void mousePressEvent(QMouseEvent *Event) override;
    /********************************************************************************************************/

signals:

private:
    /* 空空如也标签 */
    QLabel *M_EmptyLabel = NULL;
    /********************************************************************************************************/
};

#endif // XNCUT_LIST_VIEW_H
