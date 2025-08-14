<!--
 * @Author: xixi_
 * @Date: 2025-07-12 15:31:16
 * @LastEditors: xixi_
 * @LastEditTime: 2025-08-15 00:52:31
 * @FilePath: /XncutUI/README.md
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
-->

# **熙柠剪辑UI**
> 于2025年7月14日 下午 04∶54∶37立项 <br/>
> 此版本为UI, 没有业务逻辑,UI是纯代码布局 <br/>
> 请注意: 业务逻辑的实现非常不稳定! 暂时只开源UI, 业务逻辑稳下来后再开源 <br/>
> 后续我会`push`一些测试的例子 <br/>

# 为什么不用Electron
> 多优点需要很大的代价的, 如果再增加新的优点时, 要保证和现有的优点不冲突<br/>
> Electron固然方便,但是在方便快速的同时(这是优点),占用了大量的内存和存储(这是代价),每个人的电脑并不都是16个G内存,1个T存储, 需要根据场景使用,别滥用。

# 关于商业
> 这个版本对于商用是不限制的, 你可以基于此UI开发你的业务逻辑<br/>
> Q: 我基于**此项目**进行**二次开发**是否可以**不开放源代码**? 是否可以拿来**商业化**？A: 你可以**不开放源代码**, 注意的是, 你需要在源代码里保留相应的版权信息(这是必须的), 也可以拿来**商业化**, 具体取决与你。

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
    - [DIR] XncutPublicStyle **公共样式**
      - [FILE] XncutCustomTabStyle.h **TAB样式**
      - [FILE] XncutCustomTabStyle.cpp
    - [DIR] XncutClipHall **剪辑大厅**
      - [FILE] XncutClipHallWidget.h **剪辑大厅部件**
      - [FILE] XncutClipHallWidget.cpp
      - [FILE] XncutUserInfoWidget.h **用户信息(实际上是布局)**
      - [FILE] XncutUserInfoWidget.cpp
    - [DIR] XncutProjectManager **工程管理器**
      - [FILE] XncutProjectManagerWidget.h **工程管理部件**
      - [FILE] XncutProjectManagerWidget.cpp
      - [FILE] XncutProjectCreateWidget.h **创建工程**
      - [FILE] XncutProjectCreateWidget.cpp
      - [FILE] XncutProjectModifyWidget.h **工程管理**
      - [FILE] XncutProjectModifyWidget.cpp
    - [DIR] XncutEditor **编辑器**
      - [DIR] XncutTitleBar **标题栏**  
        - [FILE] XncutTitleBarWidget.h **标题栏部件(实际上是布局)**
        - [FILE] XncutTitleBarWidget.cpp
      - [DIR] XncutBins **素材箱** 
        - [DIR] XncutMaterialField **素材领域**
          - [FILE] XncutMaterialFieldWidget.h **素材领域部件**
          - [FILE] XncutMaterialFieldWidget.cpp
        - [FILE] XncutBinsWidget.h **素材箱部件**
        - [FILE] XncutBinsWidget.cpp
      - [FILE] XncutEditorWidget.h **编辑器部件**
      - [FILE] XncutEditorWidget.cpp
    - [FILE] Main.cpp **入口**
    - [FILE] Xncut.h **主窗口,此文件等价于MainWindow.h**
    - [FILE] Xncut.cpp
  - [DIR] Data **一些配置**
  - [DIR] Doc **开发文档**
  - [FILE] CMakeLists.txt **Cmake的构建配置**
  - [FIEL] COPYING.AGPLv3 **AGPL协议**
  - [FILE] README.md **就是这个**

# 其他
1. 喜欢的话记得点个Star吧
2. 如果你有更好的建议,issues吧,这对我非常重要!
3. 高中生活自由又自在，嘿嘿