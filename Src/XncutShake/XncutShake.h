/*
 * @Author: xixi_
 * @Date: 2026-09-22 19:02:59
 * @LastEditors: xixi_
 * @LastEditTime: 2026-09-22 21:47:43
 * @FilePath: /Xncut/Src/XncutShake/XncutShake.h
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
 */

#ifndef PUBG_XNCUT_SHAKE_H
#define PUBG_XNCUT_SHAKE_H
#ifdef __cplusplus
extern "C"
{
#endif

    /* 臣 Ms奶昔 第一次写 前面基本上是以渲染管线为主战场 */

#define MAP_WIDTH 60
#define MAP_HEIGHT 25

    /**
     * @brief 熙柠剪辑官方出品的[戳戳手]
     * @brief
     **/
    typedef struct XncutShake
    {
#define PUBG_XNCUT_SHAKE_MAX_SIZE 50
        int X[PUBG_XNCUT_SHAKE_MAX_SIZE]; /* 蛇X */
        int Y[PUBG_XNCUT_SHAKE_MAX_SIZE]; /* 蛇Y */
        int Len;                          /* 长度 */
        int Speed;                        /* 速度 */
        unsigned char Dir;                /* 方向 */
    } XncutShake;

#ifdef __cplusplus
}
#endif
#endif /* PUBG_XNCUT_SHAKE_H */