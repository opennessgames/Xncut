/*
 * @Author: xixi_
 * @Date: 2026-04-14 16:44:25
 * @LastEditors: xixi_
 * @LastEditTime: 2026-10-04 16:32:02
 * @FilePath: /Xncut/Src/XncutGammaDemo/MilkshakeGamma.c
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
 */

#include "MilkshakeGamma.h"
#include <math.h>

void MilkshakeGammaGetLookup(double Gamma, unsigned char *Lookup)
{
    double Exp = 1 / Gamma;

    /* 构建查找表 */
    for (int i = 0; i < 256; i++)
    {
        Lookup[i] = (unsigned char)(pow((double)i / 255.0, Exp) * 255);
    }
}

void MilkshakeGammaMapper(unsigned char *SrcData,
                          int SrcW, int SrcH, int SrcCh,
                          const unsigned char *Lookup)
{
    unsigned char *Start = SrcData;
    unsigned char *End = SrcData + (SrcW * SrcH * SrcCh);
    while (Start != End)
    {
        /* 处理每一粒像素 */
        *Start = Lookup[*Start];
        Start++;
    }
}
