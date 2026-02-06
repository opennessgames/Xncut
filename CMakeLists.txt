#
# @Author: xixi_
# @Date: 2026-02-05 23:45:14
# @LastEditors: xixi_
# @LastEditTime: 2026-02-05 23:47:41
# @FilePath: /Xncut/CMakeLists.txt
# Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
#

cmake_minimum_required(VERSION 3.19)
project(Xncut VERSION 0.0.1 DESCRIPTION "NEL剪辑软件" LANGUAGES CXX)

# 全局默认设定
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Bin)

set(CMAKE_AUTOUIC OFF) # 禁止设计师
set(CMAKE_AUTOMOC ON) # 启用MOC
set(CMAKE_AUTORCC ON) # 启用RCC

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

# 资源文件
qt_add_resources(RESOURCES_SOURCES
    Assets/XncutIcons.qrc
    Assets/XncutWelcome.qrc
)
# XncutCore
add_subdirectory(XncutCores)
# 可执行文件
qt_add_executable(Xncut
    WIN32 MACOSX_BUNDLE
    ${RESOURCES_SOURCES}
    Xncut/XncutMain.cpp
    Xncut/Xncut.cpp
    Xncut/Xncut.h
    Xncut/XncutWelcome/XncutWelcomeScreen.h
    Xncut/XncutWelcome/XncutWelcomeScreen.cpp
    Xncut/XncutWelcome/XncutBootloader.h
    Xncut/XncutWelcome/XncutBootloader.cpp
    Xncut/XncutPlugin/XncutPluginManager.h
    Xncut/XncutPlugin/XncutPluginManager.cpp
    Xncut/XncutClipHall/XncutClipHallWidget.h
    Xncut/XncutClipHall/XncutClipHallWidget.cpp
)

target_link_libraries(Xncut
    PRIVATE
    Qt::Core
    Qt::Widgets
    XncutCore
)

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
