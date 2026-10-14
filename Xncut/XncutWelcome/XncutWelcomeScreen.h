/*
 * @Author: xixi_
 * @Date: 2025-04-17 16:12:43
 * @LastEditors: xixi_
 * @LastEditTime: 2026-10-14 08:47:17
 * @FilePath: /Xncut/Xncut/XncutWelcome/XncutWelcomeScreen.h
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
 */

#ifndef PUBG_XNCUT_WELCOME_SCREEN_H
#define PUBG_XNCUT_WELCOME_SCREEN_H

/* QT-0 */
#include <QSplashScreen>

/**
 * @brief The XncutWelcomeScreen class
 * @brief 欢迎屏幕
 * @note
 * @note 不要为了做什么而做什么
 **/
class Q_DECL_HIDDEN XncutWelcomeScreen : public QSplashScreen
{
    Q_OBJECT
public:
    /**
     * @brief XncutWelcomeScreen
     * @param Pixmap
     */
    explicit XncutWelcomeScreen(const QPixmap &pixmap = QPixmap());
    ~XncutWelcomeScreen() override;
    XncutWelcomeScreen(const XncutWelcomeScreen &) = delete;
    XncutWelcomeScreen &operator=(const XncutWelcomeScreen &) = delete;
    XncutWelcomeScreen(const XncutWelcomeScreen &&) = delete;
    XncutWelcomeScreen &operator=(const XncutWelcomeScreen &&) = delete;

    /* [OpenXncut] */

public slots:
    void setProgress(int val);

protected:
    void drawContents(QPainter *painter) override;

    /* 鼠标按下事件 */
    void mousePressEvent(QMouseEvent *event) override;

    /* 鼠标移动事件 */
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    /**
     * @brief M_PressPos
     */
    QPoint m_pressPos = QPoint();

    int m_progress = 0;
};

#endif /* PUBG_XNCUT_WELCOME_SCREEN_H */