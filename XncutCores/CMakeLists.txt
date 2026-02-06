#
# @Author: xixi_
# @Date: 2026-02-06 14:25:17
# @LastEditors: xixi_
# @LastEditTime: 2026-02-06 14:25:19
# @FilePath: /Xncut/XncutCore/CMakeLists.txt
# Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
#

cmake_minimum_required(VERSION 3.19)
project(XncutCores VERSION 0.0.1 DESCRIPTION "核心" LANGUAGES CXX)

# XncutCore
add_subdirectory(XncutCore)

# XncutWidgets
add_subdirectory(XncutWidgets)

# 指定库的包含目录
target_include_directories(XncutCore PUBLIC XncutCore)
target_include_directories(XncutCore PUBLIC XncutWidgets)