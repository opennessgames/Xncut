#
# @Author: xixi_
# @Date: 2026-09-22 21:46:31
# @LastEditors: xixi_
# @LastEditTime: 2026-09-22 21:46:32
# @FilePath: /Xncut/Src/XncutShake/CMakeLists.txt
# Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
#

cmake_minimum_required(VERSION 3.19)
project(XncutShake VERSION 0.0.1 DESCRIPTION "2048" LANGUAGES C)

add_executable(XncutShake
    XncutShake.h
    XncutShake.c
    XncutShakeMain.c
)
