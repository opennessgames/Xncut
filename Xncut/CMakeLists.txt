#
# @Author: xixi_
# @Date: 2024-04-24 19:26:03
# @LastEditors: xixi_
# @LastEditTime: 2026-02-05 23:47:41
# @FilePath: /Xncut/CMakeLists.txt
# Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
#

cmake_minimum_required(VERSION 3.19)
project(Xncut DESCRIPTION "熙柠剪辑宿主程序" LANGUAGES ASM C CXX)

# 搜索QT包
find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

# QT设定
set(CMAKE_AUTOUIC OFF) # 禁止设计师
set(CMAKE_AUTOMOC ON) # 启用MOC
set(CMAKE_AUTORCC OFF) # 禁止RCC

qt_standard_project_setup()

# 添加子模块
add_subdirectory(XncutHost) # 宿主程序
# Xncut.ELF
qt_add_executable(Xncut WIN32 MACOSX_BUNDLE ${PUBG_XNCUT_SRCS})

# 依赖
set(PUBG_XNCUT_LIB ${PUBG_XNCUT_LIB} Qt::Core Qt::Widgets) # QT
# 链接库
target_link_libraries(Xncut PRIVATE ${PUBG_XNCUT_LIB})

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
