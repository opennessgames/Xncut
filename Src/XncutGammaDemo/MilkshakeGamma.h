/*
 * @Author: xixi_
 * @Date: 2026-04-14 16:44:25
 * @LastEditors: xixi_
 * @LastEditTime: 2026-10-04 16:32:05
 * @FilePath: /Xncut/Src/XncutGammaDemo/MilkshakeGamma.h
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
 */

#ifndef MILKSHAKE_GAMMA_H
#define MILKSHAKE_GAMMA_H
#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief Lookup生成器
     * @param Gamma 伽马值
     * @param Lookup 查找表
     */
    void MilkshakeGammaGetLookup(double Gamma, unsigned char *Lookup);

    /**
     * @brief Lookup映射器
     * @param SrcData 源数据
     * @param SrcW 源数据宽度
     * @param SrcH 源数据高度
     * @param SrcCh 源数据通道数
     * @param Lookup 查找表
     **/
    void MilkshakeGammaMapper(unsigned char *SrcData,
                              int SrcW, int SrcH, int SrcCh,
                              const unsigned char *Lookup);

#ifdef __cplusplus
}
#endif
#endif /* MILKSHAKE_GAMMA_H */