/*
 * @Author: xixi_
 * @Date: 2025-03-18 14:06:22
 * @LastEditors: xixi_
 * @LastEditTime: 2026-09-25 10:47:26
 * @FilePath: /Xncut/Src/Xncut2048/Xncut2048.h
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
 */

#ifndef PUBG_XNCUT_2048_H
#define PUBG_XNCUT_2048_H
#ifdef __cplusplus
extern "C"
{
#endif
#include <stdbool.h>

    /**
     * @brief The Xncut2048 struct
     * @brief 2048游戏
     * @note 熙柠剪辑官方出品[戳戳手]
     * @note Lookup table的方式
     **/
    typedef struct Xncut2048
    {
        int *Grid;
    } Xncut2048;

    extern void Xncut2048AddRandomNum(Xncut2048 *Game);
    extern bool Xncut2048Move(Xncut2048 *Game, int Direction);

#ifdef __cplusplus
}
#endif
#endif /* PUBG_XNCUT_2048_H */