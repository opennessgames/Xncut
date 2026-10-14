/*
 * @Author: xixi_
 * @Date: 2026-10-03 22:50:54
 * @LastEditors: xixi_
 * @LastEditTime: 2026-10-04 12:34:31
 * @FilePath: /Xncut/Src/XncutGammaDemo/MainWindow.h
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
 */

#ifndef PUBG_MAINWINDOW_H
#define PUBG_MAINWINDOW_H

#include <QMainWindow>

class XncutImageWidget;
class QDoubleSpinBox;

/**
 * @brief The MainWindow class
 * @brief 主窗口
 * @note
 * @note
 **/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    MainWindow(const MainWindow &) = delete;
    MainWindow &operator=(const MainWindow &) = delete;
    MainWindow(const MainWindow &&) = delete;
    MainWindow &operator=(const MainWindow &&) = delete;

private:
    void onOpenTriggered();
    void onResetTriggered();
    void onClearTriggered();
    void onSaveTriggered();

    void onGammaSpinBoxValueChanged(double);

private:
    XncutImageWidget *m_imgWidget = nullptr;
    QDoubleSpinBox *m_gammaSpinBox = nullptr;

    /* 原始图像 */
    QImage m_rawImg;
};

#endif /* PUBG_MAINWINDOW_H */