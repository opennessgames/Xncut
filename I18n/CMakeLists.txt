#
# @Author: xixi_
# @Date: 2026-04-19 22:49:17
# @LastEditors: xixi_
# @LastEditTime: 2026-04-19 22:49:19
# @FilePath: /Xncut/I18n/CMakeLists.txt
# Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
#

cmake_minimum_required(VERSION 3.19)
project(XncutI18n DESCRIPTION "国际化" LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS LinguistTools)

set(CMAKE_AUTOUIC OFF) # 禁用设计师
set(CMAKE_AUTOMOC OFF) # 禁用MOC
set(CMAKE_AUTORCC OFF) # 禁用RCC

set(LANGUAGES
    lzh     # 文言文(華夏)
    zh_CN   # 简体中文
    zh_TW   # 繁体中文
    en      # 英文
)

list(TRANSFORM LANGUAGES PREPEND "Xncut_" OUTPUT_VARIABLE TS_FILES)
list(TRANSFORM TS_FILES APPEND ".qm" OUTPUT_VARIABLE QM_FILES)
list(TRANSFORM TS_FILES APPEND ".ts")

qt6_add_translation(QM_FILES ${TS_FILES})
add_custom_target(qm ALL DEPENDS ${QM_FILES})
