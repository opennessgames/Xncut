#
# @Author: xixi_
# @Date: 2026-06-03 17:32:15
# @LastEditors: xixi_
# @LastEditTime: 2026-06-03 17:32:17
# @FilePath: /Xncut/CMakeLists.txt
# Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
#

cmake_minimum_required(VERSION 3.19)
project(Xncut VERSION 0.0.0 DESCRIPTION "NLE剪辑软件" LANGUAGES ASM C CXX)

# C/C++标准
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# error while loading shared libraries: libXncutCore.so: cannot open shared object file: No such file or directory
set(CMAKE_BUILD_RPATH "$ORIGIN")

# 编译模式
set(CMAKE_BUILD_TYPE "Debug") # 调试(Debug); 发布(Release MinSizeRel)模式

# # 版本（现代化桌面/ES/上古神器版）
# # ModernDesktop/ES/Retro
# set(PUBG_XNCUT_BUILD_VERSION "MODERN_DESKTOP" CACHE STRING "Build Version")
# set_property(CACHE PUBG_XNCUT_BUILD_VERSION PROPERTY STRINGS "MODERN_DESKTOP" "ES" "RETRO")

# 输出目录
set(PUBG_XNCUT_BINARY_DIR "Bin/${CMAKE_BUILD_TYPE}" CACHE PATH "Global output directory for libraries")

# 集中重定向
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PUBG_XNCUT_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PUBG_XNCUT_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PUBG_XNCUT_BINARY_DIR})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # PS:只有在调试模式时, 这两个才算上
    # 作战指挥中心
    add_subdirectory(Src)
endif()

# 资源
add_subdirectory(Assets)

# 国际化
add_subdirectory(I18n)

# 主程序
add_subdirectory(Xncut)

# 版本号
set(PUBG_XNCUT_VERSION "0.0.0")
target_compile_definitions(Xncut PRIVATE PUBG_XNCUT_VERSION="${PUBG_XNCUT_VERSION}")
