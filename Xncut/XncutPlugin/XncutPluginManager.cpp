/*
 * @Author: xixi_
 * @Date: 2026-02-06 15:43:06
 * @LastEditors: xixi_
 * @LastEditTime: 2026-02-06 15:49:14
 * @FilePath: /Xncut/Xncut/XncutPlugin/XncutPluginManager.cpp
 * Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
 */

#include "XncutPluginManager.h"

XncutPluginManager &XncutPluginManager::GetGlobalInstance()
{
    static XncutPluginManager Instance;
    return Instance;
}

XncutPluginManager::XncutPluginManager()
{
}

XncutPluginManager::~XncutPluginManager()
{
}
