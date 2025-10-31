/*
 * @Author: xixi_
 * @Date: 2025-08-10 13:10:51
 * @LastEditors: xixi_
 * @LastEditTime: 2025-09-18 20:20:34
 * @FilePath: /Xncut/Test/XncutPenTool/XncutPenTool/MainWindow.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QVBoxLayout;
class QTabWidget;
class XncutPenToolWidget;
class XncutPenToolWidget2;
class XncutPenToolWidget3;
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    /********************************************************************************************************/

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /********************************************************************************************************/

    /********************************************************************************************************/

private:
    /********************************************************************************************************/

private slots:
    /********************************************************************************************************/

protected:
    /********************************************************************************************************/

signals:
    /********************************************************************************************************/

private:
    /* 中心部件布局 */
    QWidget *M_CentralWidget = NULL;  /* 中心部件 */
    QVBoxLayout *M_MainLayout = NULL; /* 主布局 */
    /********************************************************************************************************/

    /* 内容部件 */
    QTabWidget *M_AllPenToolTabWidget = NULL;     /* 所有版本的钢笔工具 */
    XncutPenToolWidget *M_PenToolWidget = NULL;   /* 第一代钢笔工具 */
    XncutPenToolWidget2 *M_PenToolWidget2 = NULL; /* 第二代钢笔工具 */
    XncutPenToolWidget3 *M_PenToolWidget3 = NULL; /* 第三代钢笔工具 */
    /********************************************************************************************************/

    /* 底部提示 */
    QLabel *M_Tips = NULL;
    /********************************************************************************************************/
};
#endif // MAINWINDOW_H
