<!--
 * @Author: xixi_
 * @Date: 2025-04-22 18:18:18
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-06 16:54:08
 * @FilePath: /Xncut/README.md
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
-->

# **熙柠剪辑: QT基岩版**
# 禁止商用! 
# 禁止商用! 
# 禁止商用! 
# 禁止商用! 
# 商用者生孩子没皮燕!

# 你可以:
1. **学习**或者拿来当**教学材料**都可以
2. 二次开发时需要标注**基于熙柠剪辑**
3. 在非盈利性质的项目中使用，帮助他人理解或分享
4. 与朋友、同事共享，但仅限于**非商用**的场景
5. 在自己的博客、论坛、社交平台分享，但不得以**盈利**为目的
# 你不可以,包括但不限于: 
1. 挂到**闲鱼等电商平台**上贩卖,老子最讨厌**二手码贩子**了
2. 将其作为产品的一部分进行商业化或变现
3. 修改后用于盈利、广告宣传等商业活动
4. 分发给不符合授权条件的人或组织
5. 声称为自己的原创作品，未经许可进行再分发或出售

# 简介
> 这是小妤的初中到高中作品, 经历了多次重构, 希望你喜欢^_^</br>
> 熙柠剪辑经过了很多次优化与调优, 致力于提供**更低的内存占用**、**更快的剪辑速度**和**更专业的剪辑方案**~</br>
> 我们的目标是向企业级,系统级看齐; 做到和剪映,Pr一样的规模</br>
> **C/C++**是很漂亮的语言, 人菜就是人菜, 人菜不要责怪工具

# 各种版本: 
- WEB版最早创建于: 2022年4月
- LUA版最早创建于: 作者也不知道
- Unity引擎版最早创建于: 作者也不知道
- OpenGL版最早创建于: 作者也不知道
- 虚幻引擎版最早创建于: 作者也不知道
- QT版最早创建于2024年7月8日 下午 08∶47∶56

# 核心模块
> 主要分为四个核心模块
1. 大厅
2. 工程管理
3. 编辑器
4. 设置

# 项目文件(夹)结构

- 根目录
  - [DIR] Assets **资源目录**
    - [DIR] Images **图片**
      - [DIR] ClipHall **剪辑大厅**
        - [DIR] BottomMenu **底部菜单**
        - [FILE] XHeadImg.png **用户默认头像**
      - [DIR] Public **公共的图片资源**
    - [FILE] ClipHall.qrc **大厅资源文件**
    - [FILE] Public.qrc **公共的资源文件**
  - [DIR] Src **假的目录,嘿嘿**
  - [DIR] Xncut **真正的源代码目录**
    - [DIR] XncutClipHall **剪辑大厅**
      - [FILE] XncutClipHallWidget.h **主部件**
      - [FILE] XncutClipHallWidget.cpp
      - [FILE] XncutRecentProjectCardDelegate.h **最近工程卡片委托**
      - [FILE] XncutRecentProjectCardDelegate.cpp
      - [FILE] XncutUserInfoWidget.h **用户信息(实际上是布局)**
      - [FILE] XncutUserInfoWidget.cpp
    - [DIR] XncutCore **一些核心组件**
      - [FILE] XncutRunTimeContext.h **熙柠剪辑运行时上下文**
      - [FILE] XncutRunTimeContext.cpp
      - [FILE] XncutFunTool.h **常用的函数,类似于std::max这样的(保留类)**
      - [FILE] XncutFunTool.cpp
    - [DIR] XncutPublicWidget **公共的部件**
      - [FILE] XncutListView.h **列表视图**
      - [FILE] XncutListView.cpp
    - [DIR] XncutWelcome **欢迎**
      - [FILE] XncutWelcomeScreen.h **欢迎屏幕**
      - [FILE] XncutWelcomeScreen.cpp
    - [FILE] Main.cpp **入口**
    - [FILE] Xncut.h **主窗口**
    - [FILE] Xncut.cpp
  - [DIR] Data **一些配置**
  - [DIR] Doc **开发文档**
  - [DIR] Test **测试例子**
  - [FILE] CMakeLists.txt **Cmake的构建配置**
  - [FILE] README.md **就是这个**

# 各板块性能
1. **剪辑大厅**
  - [最近工程列表(性能瓶颈)] 一百万数据,搜索时界面会卡死,需要很长时间显示搜索的结果
2. **工程管理器**
3. **编辑器**
# 骚操作
1. (X + Y - 1) / Y **向上取整**
2. (X + 5) / 10 **四舍五入**