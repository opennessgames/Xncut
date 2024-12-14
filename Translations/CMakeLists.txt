#
# @Author: xixi_
# @Date: 2024-12-14 20:31:12
# @LastEditors: xixi_
# @LastEditTime: 2024-12-14 20:31:41
# @FilePath: /pubg-xncut-mvp/Translations/CMakeLists.txt
# Copyright (c) 2020-2024 by xixi_ , All Rights Reserved. 
#

find_package(Qt6 REQUIRED COMPONENTS LinguistTools)
set(LANGUAGES zh_CN)

list(TRANSFORM LANGUAGES PREPEND "PubgXncutMvp_" OUTPUT_VARIABLE TS_FILES)
list(TRANSFORM TS_FILES APPEND ".qm" OUTPUT_VARIABLE QM_FILES)
list(TRANSFORM TS_FILES PREPEND ${CMAKE_CURRENT_SOURCE_DIR}/)
list(TRANSFORM TS_FILES APPEND ".ts")

file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/XncutMvp/#")
qt6_add_lupdate(pubg-xncut-mvp TS_FILES ${TS_FILES} SOURCES ${SOURCES}
    OPTIONS -locations absolute -no-obsolete -recursive)
add_custom_target(translations DEPENDS pubg_xncut_lupdate)

# generate qm files with lrelease
qt6_add_translation(QM_FILES ${TS_FILES})
add_custom_target(qm ALL DEPENDS ${QM_FILES})

