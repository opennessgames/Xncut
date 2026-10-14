#
# @Author: xixi_
# @Date: 2026-09-22 19:17:28
# @LastEditors: xixi_
# @LastEditTime: 2026-09-22 19:17:30
# @FilePath: /Xncut/Src/Xncut2048/CMakeLists.txt
# Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
#

cmake_minimum_required(VERSION 3.19)
project(Xncut2048 VERSION 1.0.0 DESCRIPTION "2048" LANGUAGES C)

add_executable(Xncut2048
    Xncut2048.h
    Xncut2048.c
    Xncut2048Main.c
)
