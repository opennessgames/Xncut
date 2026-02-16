<!--
 * @Author: xixi_
 * @Date: 2026-02-05 23:54:18
 * @LastEditors: xixi_
 * @LastEditTime: 2026-02-16 22:43:50
 * @FilePath: /Xncut/README.md
 * Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
-->

# 熙柠剪辑

# 项目结构
- [DIR] Assets **资源**
  - [DIR] Images **图片**
    - [DIR] Icons **熙柠剪辑图标**
      - [FILE] PubgXncut128x128.png **128x128规格图标**
    - [DIR] Welcome **欢迎屏幕背景**
      - [FILE] *.png
  - [DIR] Fonts **字体**
    - [FILE] GuiFont.ttf **界面默认字体** 
  - [FILE] XncutIcons.qrc **熙柠剪辑图标索引**
  - [FILE] XncutWelcome.qrc **欢迎屏幕背景索引**
- [DIR] Template **标准布局模板**
  - [FILE] XncutClassLayoutTemplate.h **类标准布局模板**
- [DIR] Src **假源代码**
  - [FILE] Main.c **假启动文件**
- [DIR] Xncut **真源代码**
  - [DIR] XncutWelcome **欢迎**
    - [FILE] XncutWelcomeScreen.h **欢迎屏幕**
    - [FILE] XncutWelcomeScreen.cpp
    - [FILE] XncutBootloader.h **后台加载线程**
    - [FILE] XncutBootloader.cpp
  - [DIR] XncutPlugin **插件系统**
    - [DIR] XncutPluginManager.h **插件管理器**
    - [DIR] XncutPluginManager.cpp
  - [DIR] XncutClipHall **剪辑大厅**
    - [DIR] XncutClipHallWidget.h **剪辑大厅部件**
    - [DIR] XncutClipHallWidget.cpp
  - [FILE] Xncut.h **主窗口**
  - [FILE] Xncut.cpp
  - [FILE] XncutMain.cpp **启动文件**
- [DIR] XncutCores **熙柠剪辑核心**
  - [DIR] XncutCore **熙柠剪辑核心**
    - [DIR] XncutPluginFramework **插件框架**
      - [FILE] XncutAbstractPlugin.h **抽象插件**
      - [FILE] XncutAbstractPlugin.cpp
    - [FILE] XncutGlobalConfig.h **全局配置**
    - [FILE] XncutGlobalConfig.cpp
    - [FILE] CMakeLists.txt **CMake构建配置**
  - [DIR] XncutMilkshake **奶昔Kit**
  - [DIR] XncutWidgets **扩展部件**
    - [FILE] XncutCardWidget.h **卡片部件**
    - [FILE] XncutCardWidget.cpp
    - [FILE] CMakeLists.txt **CMake构建配置**
  - [FILE] CMakeLists.txt **CMake构建配置**
- [FILE] README.md **就是这个**
- [FILE] GPLv3 **GPLv3协议**
- [FILE] LICENSE **GPLv3协议**
- [FILE] CMakeLists.txt **总CMake构建配置**
- [FILE] XncutCodeLines.sh **统计代码行数脚本**