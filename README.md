<!--
 * @Author: xixi_
 * @Date: 2025-07-12 15:31:16
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-14 17:00:21
 * @FilePath: /XncutUI/README.md
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
-->

# **熙柠剪辑UI**
> 此版本为UI, 没有业务逻辑,UI纯代码布局<br/>

# 关于商业
> 这个版本对于商用是不限制的, 你可以基于此UI开发你的业务逻辑

# 核心模块
> 主要分为四个核心模块
1. **管理系统**
2. **编辑器**
3. **设置**

# 项目文件(夹)结构
- 根目录
  - [DIR] Assets **资源目录**
    - [DIR] Images **图片**
      - [DIR] ClipHall **剪辑大厅**
      - [DIR] Public **公共的**
      - [DIR] Welcome **欢迎屏幕**
      - [FILE] XncutClipHall.qrc **剪辑大厅资源文件**
      - [FILE] XncutPublic.qrc **公共的资源文件**
      - [FILE] XncutWelcome.qrc **欢迎屏幕资源文件**
  - [DIR] Src **源代码目录**
    - [DIR] XncutWelcome **欢迎**
      - [FILE] XncutWelcomeScreen.h **欢迎屏幕**
      - [FILE] XncutWelcomeScreen.cpp
    - [DIR] XncutPublicWidget **共有部件**
      - [FILE] XncutListView.h **列表视图**
      - [FILE] XncutListView.cpp 
    - [DIR] XncutClipHall **剪辑大厅**
      - [FILE] XncutClipHallWidget.h **剪辑大厅部件**
      - [FILE] XncutClipHallWidget.cpp
      - [FILE] XncutUserInfoWidget.h **用户信息(实际上是布局)**
      - [FILE] XncutUserInfoWidget.cpp
    - [FILE] Main.cpp **入口**
    - [FILE] Xncut.h **主窗口,此文件等价于MainWindow.h**
    - [FILE] Xncut.cpp
  - [DIR] Data **一些配置**
  - [DIR] Doc **开发文档**
  - [FILE] CMakeLists.txt **Cmake的构建配置**
  - [FIEL] COPYING.AGPLv3 **AGPL协议**
  - [FILE] README.md **就是这个**
