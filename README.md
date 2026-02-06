<!--
 * @Author: xixi_
 * @Date: 2025-07-12 15:31:16
 * @LastEditors: xixi_
 * @LastEditTime: 2026-02-07 01:52:51
 * @FilePath: /XncutUI/README.md
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
-->

# **熙柠剪辑UI**
> BY: 雷电法王杨永信(在B站名字)<br/>

# 项目历史: 
> 熙柠剪辑于**2022年4月**左右首次立项(由熙柠游戏网站衍生出来, 最初为**熙柠云剪**, 运行在Web上) <br/>
> Unity引擎版本创建于2023年8月20日, 早期工程文件已封存, 不上传到GitHub。 <br/>
> UE引擎版本创建于2023年11月4日, 意外丢失。 <br/>
> QT版本创建于2023年11月30日, 现存, 很早期的C++入门项目。 <br/>
> QT纯UI版于2025-07-14 16:54:37立项。<br/>
> 此版本为UI, 没有业务逻辑,UI是纯代码布局, 你也可以学习如何使用代码来布局。<br/>
> 请注意: 业务逻辑的实现非常不稳定! 暂时只开源UI, 业务逻辑稳下来后再开源。 <br/>
> 后续我会`push`一些测试的例子, 位于`Test`目录下。

# 重要消息:
1. 目前还在实现一些底层所需要的, 包括一些些小框架, 所以这个仓库将会很长一段时间不更新, 希望您知道
2. 我尝试只使用Qt的**QWidget模块**, 其余的一律不用, 属性, 哈希表, 队列, 动态容器等等都是自己使用C语言实现的

# 更改日志
- 2026-02-04 03:06:37 [大规模更改] 部分布局由工具栏取代, 以及多个细节, 啊啊啊啊啊

# Q&A: 为什么不用Electron
杨永信认为这个问题非常好, 原因如下: 
1. 多优点需要很大的代价的, 如果再增加新的优点时, 要保证和现有的优点不冲突<br/>
2. Electron固然方便,但是在方便快速的同时(这是优点),占用了大量的内存和存储(这是代价),每个人的电脑并不都是16个G内存,1个T存储, 需要根据场景使用, 别滥用。<br/>
3. 最重要的一点是`JavaScript`对于这样计算非常密集的场景是很吃力的

# Q&A: 关于商业
> 这个版本对于商用是不限制的, 你可以基于此UI开发你的业务逻辑<br/>
- Q: 我基于**此项目**进行**二次开发**是否可以**不开放源代码**? 是否可以拿来**商业化**？ <br/>
- A: 你可以**不开放源代码**, 注意的是, 你需要在源代码里保留相应的**版权信息**(这是必须的), 也可以拿来**商业化**, 具体取决与你。

# Q&A: 我该如何运行?
> 最简单的方法是使用`Qt Creator`来运行, 确保你的QT版本是较新的, 而不是过时的, 因为本项目使用的版本是`QT6.8.0`
1. 克隆本项目
```bash
git clone https://github.com/opennessgames/Xncut
```
2. 打开Qt Creator

# 多快好省
> 于**2025-08-31 19:43:34**提出软件版本的
- 软件功能**多**
- 代码执行速度**快**
- 代码质量**好**
- 更**省**资源, 内存, 磁盘, CPU
- **微信**和**QQ**就是反面教材

# 代码规范
> 首先，使用**Markdown编辑器**或者**具有Markdown功能**的编辑器把**规范**完整的打一边, 然后, 全部删除掉, 不能按下**Ctrl+Z**, 立即关闭你的编辑器, 彻底的删掉<br/>
> 然后呢, 现在可以开始了
1. 关键字
   - 禁止使用**auto**关键字
2. 缩进
   - if语句超过三层, 说明程序开始朝不好的方向发展, 需要修复, 请尝试使用**策略**, **卫语句**或者其他的方法来优化
   - 代码**必须**有缩进, 至少**4个空格甚至更大**, 因为**更大的缩进**可以让你很舒服
3. 变量名
   - **禁止**使用**aa**,**bb**,**cc**,**abc**来命名
   - **禁止**使用**汉语拼音**来命名
   - **禁止**将变量名**全部大写**或者**全部小写**, 除非使用了下划线作为分割
   - 如果你使用了上面三种方式, 说明你的程序已经**严重**混乱, 你必须立即进行修复, 当然, for循环等流程控制除外, 比如**for (int i = 0; i < 114514; i++)**
   - **正确的方法**是你应该使用**专有的英文名**来命名并遵守**命名规范**
4. 函数
   - 如果函数有返回值, 那么无论如何都要有返回值
5. 性能
   - 你应该尽量避免线性, 特别是逐个遍历, 在遍历前, 你应该尝试寻找一种不需要遍历的处理方式, 尽可能的将时间复杂度从**o(n)**降到**o(log n)**来提高程序的速度, 除非只能使用遍历, 没有其他的更优方法
   - **冒泡排序法**你不应该使用, 因为**时间复杂度**是糟糕的**n的平方**, 这意味着是非常低效且非常糟糕的, 你因该让**快速排序**和**Timsort**等**高效的排序算法**来取代冒泡排序
6. 安全
    - 在**堆中**申请的内存块, 你应该在不需要的时候释放它, 归还给操作系统, 并立即**赋于NULL**来避免**野指针**, 你务必知道: **if语句**是**无法检查出**野指针的, 来看下面的例子
    ```c
    #include <stdio.h>
    #include <stdlib.h>

    int main()
    {
      int *Number = (int *)malloc(sizeof(int)); /* 申请一块内存 */
      *Number = 114514;
      printf("%d\n", *Number); /* 正常打印是114514 */

      /* 然后我们释放它, 不赋为NULL */
      free(Number); /* 如果不释放, 将会引发内存泄漏, 你可以通俗理解为占着茅坑不拉屎, 造成了公共的资源浪费 */

      /* 判空 */
      if (!Number)
      {
          printf("无效的数字!\n"); /* 是不会打印这句话的, 因为没有赋为NULL, 这就是非常危险的野指针 */
      }
      /* 比如小明约好了你去奶茶店, 你需要找到小明, 小明告诉你地址是奶茶店门口的长椅, 你去了奶茶店, 长椅上坐的并不是小明而是其他顾客,这个小明, 又TM放我鸽子 */
    }
    ```
    - 在使用任何递归算法时, 必须进行评估, 确保不会爆栈(递归深度过大导致堆栈溢出); 如果出现爆栈, 则不应该使用递归, 而是由**迭代**取代**递归**

# 核心模块
> 主要分为四个核心模块
1. **管理系统**
2. **编辑器**
3. **设置**

# 项目文件(夹)结构
> 你务必知道: 不同的模块有着不同的协议, 以MIT居多
- 根目录
  - [DIR] Doc
    - [DIR] RoutingArchitecture **页面路由架构**
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
      - [DIR] XncutProjectMonitor **工程监视器**
        - [FILE] XncutProjectMonitorWidget.h **工程监视器部件**
        - [FILE] XncutProjectMonitorWidget.cpp
        - [FILE] XncutVideoWidget.h **视频部件**
        - [FILE] XncutVideoWidget.cpp 
      - [FILE] XncutEditorWidget.h **编辑器部件**
      - [FILE] XncutEditorWidget.cpp
    - [FILE] Main.cpp **入口**
    - [FILE] Xncut.h **主窗口,此文件等价于MainWindow.h**
    - [FILE] Xncut.cpp
  - [DIR] Test **测试例子**
    - [DIR] XncutThreeLayerLayout **三层垂直布局部件**
    - [DIR] XncutAbstractTabItemView **抽象标签视图部件**
    - [DIR] XncutTitleBar **标题栏**  **MIT协议**
    - [DIR] XncutPenTool **钢笔工具**
  - [DIR] Data **一些配置**
  - [DIR] Doc **开发文档**
  - [FILE] CMakeLists.txt **Cmake的构建配置**
  - [FIEL] COPYING.AGPLv3 **AGPL协议**
  - [FILE] README.md **就是这个**

# 其他
1. 喜欢的话记得点个Star吧
2. 如果你有更好的建议,issues吧,这对我非常重要!
3. 高中生活自由又自在，嘿嘿~
4. 你一定要记住, 先开始, 后完美
5. 奈何网络就是我的弱点啊, 尝试搓个网络模拟器吧, 感谢彭老师留的时间
6. 高二的时光过的真TM快啊, 好好珍惜吧~

# 你不怕失败吗
> 哈哈, 我当然怕, 让我尝试一下, 万一成功了呢?  <br/>
> 如果成功了, 剪映VIP是啥? Pr订阅费用是啥? 我不知道