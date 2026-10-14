/*
 * @Author: xixi_
 * @Date: 2026-09-22 19:17:13
 * @LastEditors: xixi_
 * @LastEditTime: 2026-09-22 21:25:55
 * @FilePath: /Xncut/Src/Xncut2048/Xncut2048Main.c
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
 */

#include "Xncut2048.h"
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void Print1DTable(int *Grid)
{
    for (int i = 0; i < 16; i++)
    {
        printf("%4d ", Grid[i]);
        if ((i + 1) % 4 == 0)
        {
            printf("\n");
        }
    }
}

void handle_signal(int signal)
{
    printf("\033[H\033[J"); /* 清屏 */
    exit(0);
}

static const int DirMap[4][3] = {
    {'W', 'w', 3},
    {'A', 'a', 0},
    {'S', 's', 1},
    {'D', 'd', 2},
}; /* 方向索引映射 */

int main(int Argc, char **Argv, char **Envp)
{
    signal(SIGINT, handle_signal);  /* 处理 Ctrl+C */
    signal(SIGTSTP, handle_signal); /* 处理 Ctrl+Z */

    Xncut2048 Game;
    Game.Grid = (int *)malloc(sizeof(int) * 16);

    int DirMapSize = sizeof(DirMap) / (4 * 4) + 1; /* 获取映射表大小 */
    char DirectionInput = '\0';                    /* 输入方向 */
    Xncut2048AddRandomNum(&Game);                  /* 随机添加一个数字 */
    while (true)
    {
        printf("\033[H\033[J");  /* 清屏 */
        Print1DTable(Game.Grid); /* 打印当前棋盘状态 */
        printf("请输入移动方向 (W: 上, A: 左, S: 下, D: 右 Q: 退出): ");
        scanf("%c", &DirectionInput); /* 读取用户输入，跳过前导空白字符 */
        for (int i = 0; i < DirMapSize; i++)
        {
            if (DirMap[i][0] == DirectionInput || DirMap[i][1] == DirectionInput)
            {
                printf("%s\n", Xncut2048Move(&Game, DirMap[i][2]) ? "移动" : "失败");
                Print1DTable(Game.Grid);
                break;
            }
        }
        if (DirectionInput == 'q' || DirectionInput == 'Q')
        {
            exit(0);
        }
    }

    free(Game.Grid);
    return 0;
}
