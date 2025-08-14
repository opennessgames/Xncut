#
# @Author: xixi_
# @Date: 2025-07-14 16:54:45
# @LastEditors: xixi_
# @LastEditTime: 2025-07-14 17:05:39
# @FilePath: /XncutUI/CMakeLists.txt
# Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
#

cmake_minimum_required(VERSION 3.5)

project(XncutUI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    Src/Main.cpp
    Src/Xncut.cpp
    Src/Xncut.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    find_package(Qt6 REQUIRED COMPONENTS Widgets)
    find_package(Qt6 REQUIRED COMPONENTS Widgets)
    find_package(Qt6 REQUIRED COMPONENTS Widgets)
    find_package(Qt6 REQUIRED COMPONENTS Widgets)

    qt_add_executable(XncutUI
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        Src/XncutClipHall/XncutClipHallWidget.h
        Src/XncutClipHall/XncutClipHallWidget.cpp
        Src/XncutClipHall/XncutUserInfoWidget.h
        Src/XncutClipHall/XncutUserInfoWidget.cpp
        Src/XncutPublicWidget/XncutListView.h
        Src/XncutPublicWidget/XncutListView.cpp
        Assets/XncutClipHall.qrc
        Assets/XncutPublic.qrc
        Src/XncutWelcome/XncutWelcomeScreen.h
        Src/XncutWelcome/XncutWelcomeScreen.cpp
        Assets/XncutWelcome.qrc
        Src/XncutProjectManager/XncutProjectManagerWidget.h
        Src/XncutProjectManager/XncutProjectManagerWidget.cpp
        Src/XncutProjectManager/XncutProjectCreateWidget.h
        Src/XncutProjectManager/XncutProjectCreateWidget.cpp
        Src/XncutProjectManager/XncutProjectModifyWidget.h
        Src/XncutProjectManager/XncutProjectModifyWidget.cpp
        Src/XncutEditor/XncutEditorWidget.h
        Src/XncutEditor/XncutEditorWidget.cpp
        Src/XncutEditor/XncutTitleBar/XncutTitleBarWidget.h
        Src/XncutEditor/XncutTitleBar/XncutTitleBarWidget.cpp
        Assets/XncutEditor.qrc
        Src/XncutEditor/XncutBins/XncutBinsWidget.h
        Src/XncutEditor/XncutBins/XncutBinsWidget.cpp
        Src/XncutEditor/XncutBins/XncutMaterialField/XncutMaterialFieldWidget.h
        Src/XncutEditor/XncutBins/XncutMaterialField/XncutMaterialFieldWidget.cpp
        Src/XncutPublicStyle/XncutCustomTabStyle.h
        Src/XncutPublicStyle/XncutCustomTabStyle.cpp
        Src/XncutEditor/XncutProjectMonitor/XncutProjectMonitorWidget.h
        Src/XncutEditor/XncutProjectMonitor/XncutProjectMonitorWidget.cpp
        Src/XncutEditor/XncutProjectMonitor/XncutVideoWidget.h
        Src/XncutEditor/XncutProjectMonitor/XncutVideoWidget.cpp
        Src/XncutEditor/XncutInspector/XncutInspectorWidget.h
        Src/XncutEditor/XncutInspector/XncutInspectorWidget.cpp
        Src/XncutEditor/XncutInspector/XncutProjectArgWidget.h
        Src/XncutEditor/XncutInspector/XncutProjectArgWidget.cpp
    )
    # Define target properties for Android with Qt 6 as:
    #    set_property(TARGET XncutUI APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(XncutUI SHARED
            ${PROJECT_SOURCES}
        )
        # Define properties for Android with Qt 5 after find_package() calls as:
        #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(XncutUI
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(XncutUI PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(XncutUI PRIVATE Qt6::Widgets)
target_link_libraries(XncutUI PRIVATE Qt6::Widgets)
target_link_libraries(XncutUI PRIVATE Qt6::Widgets)
target_link_libraries(XncutUI PRIVATE Qt6::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.XncutUI)
endif()
set_target_properties(XncutUI PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS XncutUI
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(XncutUI)
endif()
