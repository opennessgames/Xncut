#
# @Author: xixi_
# @Date: 2026-02-05 23:45:14
# @LastEditors: xixi_
# @LastEditTime: 2026-02-05 23:47:41
# @FilePath: /Xncut/CMakeLists.txt
# Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
#

cmake_minimum_required(VERSION 3.19)
project(Xncut LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(Xncut
    WIN32 MACOSX_BUNDLE
    main.cpp
    Xncut.cpp
    Xncut.h
)

target_link_libraries(Xncut
    PRIVATE
    Qt::Core
    Qt::Widgets
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
