/*
 * @Author: xixi_
 * @Date: 2025-10-01 14:33:13
 * @LastEditors: xixi_
 * @LastEditTime: 2026-10-13 13:01:20
 * @FilePath: /Xncut/Xncut/XncutWelcome/XncutBootloader.cpp
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
 */

#include "XncutBootloader.h"

XncutBootloader::XncutBootloader(QObject *parent)
    : QThread(parent)
{
}

XncutBootloader::~XncutBootloader()
{
}

void XncutBootloader::run()
{
    for (int i = 0; i <= 100; i++)
    {
        emit progressChange(i);
        QThread::msleep(50);
    }
}
