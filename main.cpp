/*
 * @Author: xixi_
 * @Date: 2026-02-05 23:45:14
 * @LastEditors: xixi_
 * @LastEditTime: 2026-02-05 23:47:37
 * @FilePath: /Xncut/main.cpp
 * Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
 */

#include "Xncut.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Xncut w;
    w.show();
    return a.exec();
}
