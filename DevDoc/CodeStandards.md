<!--
 * @Author: xixi_
 * @Date: 2026-10-03 16:54:41
 * @LastEditors: xixi_
 * @LastEditTime: 2026-10-12 16:22:13
 * @FilePath: /Xncut/DevDoc/CodeStandards.md
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
-->

# 代码规范
- Qt模块：遵循`Qt6`官方Coding Style
- 非Qt模块：遵循`UE5.8`代码规范, 传送门: 
    > https://dev.epicgames.com/documentation/unreal-engine/epic-cplusplus-coding-standard-for-unreal-engine

# 番外规范
1. [强制] 模块**不允许分散**, 强制**统一**并在**一个文件夹内**
2. [强制] 禁止出现 **#include "../../"** 情况
3. [强制] 禁止使用任何**递归**

# 本领域规范
> 本领域属于**多媒体:NLE剪辑**
1. [强制] 业务层(**引擎外部**)禁止调用**av_seek_frame**等函数
2. [强制] **引擎外部**禁止出现任何与ffmpeg相关结构体, 枚举类型不算
   - 具体哪些结构体禁止出现在引擎外部? 这些:
   - XxxxContext 各种上下文
   - AVStream
   - AVCodec
   - AVPacket
   - AVFrame
3. [强制] 任何与**音视频功能**的实现禁止调用**ffmpeg命令**, 而是用**APIs**实现
4. [强制] 二进制构建目录**禁止**出现**ffmpeg可执行程序**
5. [强制] 尽量减少累加去累积误差, 彻底杜绝掉滚雪球, 改用直接计算