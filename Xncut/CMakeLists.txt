#
# @Author: xixi_
# @Date: 2024-07-09 01:42:04
# @LastEditors: xixi_
# @LastEditTime: 2026-02-05 23:47:41
# @FilePath: /Xncut/CMakeLists.txt
# Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
#

cmake_minimum_required(VERSION 3.19)
project(Xncut VERSION 0.0.1 DESCRIPTION "NEL剪辑软件" LANGUAGES CXX)

# C/C++标准
set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 26)

# error while loading shared libraries: libXncutCore.so: cannot open shared object file: No such file or directory
set(CMAKE_BUILD_RPATH "$ORIGIN")

# 编译模式
set(CMAKE_BUILD_TYPE "Debug") # 调试(Debug); 发布(Release MinSizeRel)模式

# 加大反编译力度

# QT设定
set(CMAKE_AUTOUIC OFF) # 禁止设计师
set(CMAKE_AUTOMOC ON) # 启用MOC
set(CMAKE_AUTORCC ON) # 启用RCC

# 搜索QT包
find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

# 可执行文件: Xncut.ELF
qt_add_executable(Xncut
    WIN32 MACOSX_BUNDLE
    ##########################
    ##########################
    Xncut.h
    Xncut.cpp
    ##########################
    XncutMain.cpp
)

# 链接库
target_link_libraries(Xncut PRIVATE Qt::Core Qt::Widgets) # QT

include(GNUInstallDirs)

install(TARGETS Xncut
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Xncut
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
