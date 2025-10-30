#
# @Author: xixi_
# @Date: 2025-10-30 22:02:59
# @LastEditors: xixi_
# @LastEditTime: 2025-10-30 22:03:36
# @FilePath: /XncutUI/Test/XncutAbstractTabItemView/CMakeLists.txt
# Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
#

cmake_minimum_required(VERSION 3.19)
project(XncutAbstractTabItemView LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(XncutAbstractTabItemView
    WIN32 MACOSX_BUNDLE
    Main.cpp
    MainWindow.cpp
    MainWindow.h
    XncutAbstractTabItemViewWidget.h
    XncutAbstractTabItemViewWidget.cpp
    XncutMyAssetsWidget.h
    XncutMyAssetsWidget.cpp
)

target_link_libraries(XncutAbstractTabItemView
    PRIVATE
    Qt::Core
    Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS XncutAbstractTabItemView
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET XncutAbstractTabItemView
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
