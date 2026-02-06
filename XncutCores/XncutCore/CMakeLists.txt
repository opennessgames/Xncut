#
# @Author: xixi_
# @Date: 2026-02-06 14:26:24
# @LastEditors: xixi_
# @LastEditTime: 2026-02-06 14:26:26
# @FilePath: /Xncut/XncutCore/XncutCore/CMakeLists.txt
# Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
#

cmake_minimum_required(VERSION 3.19)
project(XncutCore VERSION 0.0.1 DESCRIPTION "核心" LANGUAGES CXX)

# XncutCore.so
add_library(XncutCore SHARED
    XncutGlobalConfig.h
    XncutGlobalConfig.cpp
    XncutPluginFramework/XncutAbstractPlugin.h
    XncutPluginFramework/XncutAbstractPlugin.cpp
)

# 链接库
target_link_libraries(XncutCore PRIVATE
    Qt::Core
)
