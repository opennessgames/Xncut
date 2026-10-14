/*
 * @Author: xixi_
 * @Date: 2025-03-18 14:06:22
 * @LastEditors: xixi_
 * @LastEditTime: 2026-09-25 10:47:12
 * @FilePath: /Xncut/Src/Xncut2048/Xncut2048.c
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
 */

/* PUBG-XNCUT-0 */
#include "Xncut2048.h"
/* STD-0 */
#include <stdlib.h>

static const int lbrt[64] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, /* 左 */
    12, 8, 4, 0, 13, 9, 5, 1, 14, 10, 6, 2, 15, 11, 7, 3, /* 下 */
    3, 2, 1, 0, 7, 6, 5, 4, 11, 10, 9, 8, 15, 14, 13, 12, /* 右 */
    0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15  /* 上 */
}; /* 四方向快速索引数组,仅适用于`4*4`尺寸 */

static inline bool Xncut2048MergeLine(int *OldLine, int *NewLine)
{
    int Index = 0; /* 用于跟踪新表中的下一个插入位置 */
    bool CanMove = false;
    bool MergedMark[4] = {false, false, false, false};
    for (int i = 0; i < 4; i++)
    {
        if (OldLine[i] != 0) /* 如果当前格子不为空 */
        {
            if (Index > 0 && NewLine[Index - 1] == OldLine[i] && !MergedMark[Index - 1])
            {
                NewLine[Index - 1] *= 2;      /* 合并 */
                MergedMark[Index - 1] = true; /* 标记已合并 */
                CanMove = true;               /* 标记可移动 */
            }
            else
            {
                NewLine[Index++] = OldLine[i]; /* 将当前数字放入新表并移动到下一个插入的位置 */
            }
        }
        else
        {
            CanMove = true; /* 发现0值,标记可移动 */
        }
    }
    return CanMove; /* 返回移动标志 */
}

void Xncut2048AddRandomNum(Xncut2048 *Game)
{
    int EmptyIndices[16] = {0}; /* 空索引列表 */
    int EmptyCont = 0;          /* 空索引总数 */
    for (int i = 0; i < 16; i++)
    {
        if (Game->Grid[i] == 0)
        {
            EmptyIndices[EmptyCont++] = i; /* 记录 */
        }
    }
    if (EmptyCont > 0) /* 如果存在空格 */
    {
        int SelectedIndex = EmptyIndices[rand() % EmptyCont]; /* 随机获取空索引 */
        Game->Grid[SelectedIndex] = (rand() % 10 < 1) ? 4 : 2;
    }
}

bool Xncut2048Move(Xncut2048 *Game, int Direction)
{
    bool HasMoved = false; /* 标记是否发生过移动 */
    for (int i = 0; i < 4; i++)
    {
        int Index = Direction * 16 + i * 4 + 3; /* 计算当前处理的方块组的起始索引 */
        int OldLine[4] = {Game->Grid[lbrt[Index - 3]], Game->Grid[lbrt[Index - 2]],
                          Game->Grid[lbrt[Index - 1]], Game->Grid[lbrt[Index]]}; /* 拿到当前行/列 */
        int NewLine[4] = {0, 0, 0, 0};                                           /* 初始化新表 */
        bool CanMove = Xncut2048MergeLine(OldLine, NewLine);                     /* 合并方块并获取新状态 */
        if (CanMove)                                                             /* 如果可以移动或合并 */
        {
            for (int j = 0; j < 4; j++)
            {
                Game->Grid[lbrt[Index + j - 3]] = NewLine[j]; /* 更新网格中的方块 */
            }
            HasMoved = true; /* 标记发生过移动 */
        }
    }

    if (HasMoved)
    {
        Xncut2048AddRandomNum(Game); /* 可移动,随机刷新2/4 */
    }
    return HasMoved;
}
