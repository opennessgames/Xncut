#
# @Author: xixi_
# @Date: 2026-02-06 16:12:08
# @LastEditors: xixi_
# @LastEditTime: 2026-02-06 16:12:09
# @FilePath: /Xncut/XncutCores/XncutWidgets/CMakeLists.txt
# Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
#

cmake_minimum_required(VERSION 3.19)
project(XncutWidgets VERSION 0.0.1 DESCRIPTION "扩展部件" LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

# XncutWidgets.so
add_library(XncutWidgets SHARED
    XncutCardWidget.h
    XncutCardWidget.cpp
)

# 链接库
target_link_libraries(XncutWidgets PRIVATE
    Qt::Core Qt::Widgets
)
