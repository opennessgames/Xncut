/*
 * @Author: xixi_
 * @Date: 2026-10-03 22:45:38
 * @LastEditors: xixi_
 * @LastEditTime: 2026-10-04 00:55:41
 * @FilePath: /Xncut/Src/XncutGammaDemo/XncutGammaDemoMain.cpp
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
 */

#include <QApplication>
#include "MainWindow.h"

int main(int argc, char **argv, char **envp)
{
    QApplication openGameApplication(argc, argv);

    MainWindow w;
    w.setWindowTitle("创意效果-伽马调色Demo");
    w.setWindowOpacity(0.6);
    w.resize(870, 470);
    w.show();

    return QApplication::exec();
}
