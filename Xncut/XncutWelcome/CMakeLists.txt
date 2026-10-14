#
# @Author: xixi_
# @Date: 2026-06-07 22:51:59
# @LastEditors: xixi_
# @LastEditTime: 2026-06-07 22:52:01
# @FilePath: /Xncut/Xncut/XncutWelcome/CMakeLists.txt
# Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
#

# cmake_minimum_required(VERSION 3.19)
# project(XncutWelcome VERSION 0.0.1 DESCRIPTION "欢迎屏幕" LANGUAGES CXX)

set(PUBG_XNCUT_SRCS
    ${PUBG_XNCUT_SRCS}
    XncutWelcome/XncutBootloader.h
    XncutWelcome/XncutBootloader.cpp
    XncutWelcome/XncutWelcomeScreen.h
    XncutWelcome/XncutWelcomeScreen.cpp
    PARENT_SCOPE
)
