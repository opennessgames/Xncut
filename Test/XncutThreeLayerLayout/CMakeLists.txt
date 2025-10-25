#
# @Author: xixi_
# @Date: 2025-10-25 13:20:25
# @LastEditors: xixi_
# @LastEditTime: 2025-10-25 13:20:45
# @FilePath: /XncutUI/Test/XncutThreeLayerLayout/CMakeLists.txt
# Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
#

cmake_minimum_required(VERSION 3.19)
project(XncutThreeLayerLayout LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(XncutThreeLayerLayout
    WIN32 MACOSX_BUNDLE
    Main.cpp
    MainWindow.cpp
    MainWindow.h
    XncutThreeLayerLayoutWidget.h XncutThreeLayerLayoutWidget.cpp
)

target_link_libraries(XncutThreeLayerLayout
    PRIVATE
    Qt::Core
    Qt::Widgets
)
target_link_libraries(XncutThreeLayerLayout PRIVATE Qt6::Widgets)

include(GNUInstallDirs)

install(TARGETS XncutThreeLayerLayout
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET XncutThreeLayerLayout
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
