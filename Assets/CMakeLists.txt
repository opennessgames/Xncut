#
# @Author: xixi_
# @Date: 2025-10-15 19:58:50
# @LastEditors: xixi_
# @LastEditTime: 2026-06-04 15:40:25
# @FilePath: /Xncut/Assets/CMakeLists.txt
# Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
#

cmake_minimum_required(VERSION 3.19)
project(XncutAssets DESCRIPTION "资源文件" LANGUAGES CXX)

# QT设定
set(CMAKE_AUTOUIC OFF) # 禁用设计师
set(CMAKE_AUTOMOC OFF) # 禁用MOC
set(CMAKE_AUTORCC ON) # 启用RCC

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

# 资源文件
qt_add_resources(RESOURCES_SOURCES
    XncutIcons.qrc
)

# XncutAssets.so
add_library(XncutAssets SHARED
    ${RESOURCES_SOURCES}
    XncutAssetsInitializer/XncutAssetsInitializer.h
    XncutAssetsInitializer/XncutAssetsInitializer.cpp
)

# 链接库
target_link_libraries(XncutAssets PRIVATE Qt::Core) # QT

# 指定库的包含目录     
target_include_directories(XncutAssets PUBLIC XncutAssetsInitializer)

# 使用
# #include <QtGlobal>
# Q_INIT_RESOURCE(XncutIcons);