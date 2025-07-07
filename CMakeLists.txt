#
# @Author: xixi_
# @Date: 2025-07-02 12:32:51
# @LastEditors: xixi_
# @LastEditTime: 2025-07-02 12:33:22
# @FilePath: /Xncut/CMakeLists.txt
# Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
#

cmake_minimum_required(VERSION 3.5)

project(Xncut VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC OFF) # 关闭掉UIC,因为我不使用QT设计师
set(CMAKE_AUTOMOC ON) # 这个是必须要打开的,MOC
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    Xncut/Main.cpp # 入口
    Xncut/Xncut.cpp # 主窗口
    Xncut/Xncut.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Xncut
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        Xncut/XncutClipHall/XncutClipHallWidget.h # 剪辑大厅
        Xncut/XncutClipHall/XncutClipHallWidget.cpp
        Assets/ClipHall.qrc #剪辑大厅资源文件
        Xncut/XncutClipHall/XncutUserInfoWidget.h # 用户信息
        Xncut/XncutClipHall/XncutUserInfoWidget.cpp
        Assets/Public.qrc # 共有的资源文件
        Xncut/XncutPublicWidget/XncutListView.h # 列表视图
        Xncut/XncutPublicWidget/XncutListView.cpp
        Xncut/XncutClipHall/XncutRecentProjectCardDelegate.h # 最近工程卡片委托
        Xncut/XncutClipHall/XncutRecentProjectCardDelegate.cpp
        Xncut/XncutCore/XncutRunTimeContext.h # 熙柠剪辑运行时上下文
        Xncut/XncutCore/XncutRunTimeContext.cpp
        Xncut/XncutWelcome/XncutWelcomeScreen.h # 欢迎屏幕
        Xncut/XncutWelcome/XncutWelcomeScreen.cpp
        Xncut/XncutCore/XncutFunTool.h # 常用的函数
        Xncut/XncutCore/XncutFunTool.cpp
        Xncut/XncutProjectManager/XncutProjectManagerWidget.h # 工程管理部件
        Xncut/XncutProjectManager/XncutProjectManagerWidget.cpp
        Xncut/XncutProjectManager/XncutProjectCreateWidget.h # 工程创建(负责增)
        Xncut/XncutProjectManager/XncutProjectCreateWidget.cpp
        Xncut/XncutProjectManager/XncutProjectModifyWidget.h # 工程管理(负责删改查)
        Xncut/XncutProjectManager/XncutProjectModifyWidget.cpp
        Xncut/XncutPublicWidget/XncutSwitchButton.h # 类安卓开关控件
        Xncut/XncutPublicWidget/XncutSwitchButton.cpp
        Xncut/XncutProjectManager/XncutProjectCardDelegate.h # 工程卡片委托
        Xncut/XncutProjectManager/XncutProjectCardDelegate.cpp
    )
    # Define target properties for Android with Qt 6 as:
    #    set_property(TARGET Xncut APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Xncut SHARED
            ${PROJECT_SOURCES}
        )
        # Define properties for Android with Qt 5 after find_package() calls as:
        #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Xncut
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Xncut PRIVATE Qt${QT_VERSION_MAJOR}::Widgets xixi)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Xncut)
endif()
set_target_properties(Xncut PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Xncut
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Xncut)
endif()
