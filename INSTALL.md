<!--
 * @Author: xixi_
 * @Date: 2026-10-08 23:58:51
 * @LastEditors: xixi_
 * @LastEditTime: 2026-10-14 14:13:03
 * @FilePath: /Xncut/INSTALL.md
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
-->

# INSTALL 
> 嗯, 就是这么简单[摊手]
>
> 我不用SDL, 不用OpenCV, 也不用JACK等等......
> 
> 必须零冗余层, 延迟最低, 函数调用栈最浅......
>
> 如果需要跨平台, 那就用各自系统的原生APIs, 
> 
> 而不是用一个通用的“中间层”去糊弄所有系统。
>

----------------------------

## Start
```bash
sudo su
```

## Update
```bash
apt-get update
```
## GCC 15.3.0
```bash
Generally speaking, GCC is built into Linux.
```

## CUDA
```bash
```

## FFmpeg 9.0.2
```bash
apt-get install libavcodec-dev libavformat-dev libavutil-dev \
                    libswscale-dev libswresample-dev libavfilter-dev
```

## ALSA
```bash 
apt-get install libasound2-dev
```

## OpenGL
```
Using Qt built-in
```

## CMake 4.3.4
```bash 
apt-get install cmake=4.3.4-1 
```

## Git 2.53.0
```bash
apt-get install git=1:2.53.0-1
```

## Qt 6.12
```txt
Qt... Qt... Emmmm... online install......
```

## End
```txt
Alright, 
have the dependencies been installed? 
Let's begin.
```
