/*
 * @Author: xixi_
 * @Date: 2026-08-28 16:36:33
 * @LastEditors: xixi_
 * @LastEditTime: 2026-09-22 21:43:34
 * @FilePath: /Xncut/Src/XncutToUpper.c
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
 */

#include <stdio.h>
#include <ctype.h>

int main(int Argc, char **Argv, char **Envp)
{
    char *SrcString = Argv[1];

    while (*SrcString != '\0')
    {
        *SrcString = toupper((unsigned char)*SrcString);
        SrcString++;
    }

    printf("%s\n", Argv[1]);

    return 0;
}
