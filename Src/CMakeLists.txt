#
# @Author: xixi_
# @Date: 2026-09-22 19:16:35
# @LastEditors: xixi_
# @LastEditTime: 2026-09-22 19:16:37
# @FilePath: /Xncut/Src/CMakeLists.txt
# Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
#

cmake_minimum_required(VERSION 3.19)
project(Src VERSION 0.0.1 DESCRIPTION "作战指挥中心!!!" LANGUAGES C CXX)

# 集中重定向
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PUBG_XNCUT_BINARY_DIR}/XncutCDC)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PUBG_XNCUT_BINARY_DIR}/XncutCDC)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PUBG_XNCUT_BINARY_DIR}/XncutCDC)

add_subdirectory(Xncut2048)
add_subdirectory(XncutGammaDemo)
add_executable(XncutMain Main.c)
add_executable(XncutToUpper XncutToUpper.c)
