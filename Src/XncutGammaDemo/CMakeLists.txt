#
# @Author: xixi_
# @Date: 2026-10-03 22:44:24
# @LastEditors: xixi_
# @LastEditTime: 2026-10-03 22:44:25
# @FilePath: /Xncut/Src/XncutGamma/CMakeLists.txt
# Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
#

cmake_minimum_required(VERSION 3.19)
project(XncutGammaDemo VERSION 1.0.0 DESCRIPTION "伽马效果Demo" LANGUAGES ASM C CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(XncutGammaDemo
    WIN32 MACOSX_BUNDLE
    XncutImageWidget.h
    XncutImageWidget.cpp
    MilkshakeGamma.h
    MilkshakeGamma.c
    MainWindow.h
    MainWindow.cpp
    XncutGammaDemoMain.cpp
)

target_link_libraries(XncutGammaDemo PRIVATE
    Qt::Core Qt::Widgets # QT
)
