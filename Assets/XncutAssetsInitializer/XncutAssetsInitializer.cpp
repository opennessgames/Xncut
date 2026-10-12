/*
 * @Author: xixi_
 * @Date: 2026-06-05 23:52:56
 * @LastEditors: xixi_
 * @LastEditTime: 2026-10-12 18:05:08
 * @FilePath: /Xncut/Assets/XncutAssetsInitializer/XncutAssetsInitializer.cpp
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
 */

/* PUBG-XNCUT-0 */
#include "XncutAssetsInitializer.h"
/* QT-0 */
#include <QResource>

void XncutAssetsInitializer::init()
{
    qInfo() << "Init All Assets";

    /* Init */
    Q_INIT_RESOURCE(XncutIcons);
}
