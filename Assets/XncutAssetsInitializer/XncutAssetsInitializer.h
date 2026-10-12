/*
 * @Author: xixi_
 * @Date: 2026-06-05 23:52:56
 * @LastEditors: xixi_
 * @LastEditTime: 2026-10-12 17:57:36
 * @FilePath: /Xncut/Assets/XncutAssetsInitializer/XncutAssetsInitializer.h
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
 */

#ifndef PUBG_XNCUT_ASSETS_INITIALIZER_H
#define PUBG_XNCUT_ASSETS_INITIALIZER_H

/**
 * @brief The XncutAssetsInitializer class
 * @brief 资源初始化器
 * @note 
 * @note 2026-06-06 00:08:00 基本完成新资源架构与模式
 * @note 真正危险的从来不是别人变强
 * @note 而是为了不让别人变强
 * @note 自己也停止了前进
 **/
class XncutAssetsInitializer
{
private:
    explicit XncutAssetsInitializer() = delete;
    ~XncutAssetsInitializer() = delete;
    XncutAssetsInitializer(const XncutAssetsInitializer &) = delete;
    XncutAssetsInitializer &operator=(const XncutAssetsInitializer &) = delete;
    XncutAssetsInitializer(const XncutAssetsInitializer &&) = delete;
    XncutAssetsInitializer &operator=(const XncutAssetsInitializer &&) = delete;

    /* [OpenXncut] */

public:
    /* 对资源进行初始化 */
    static void init();
};

#endif /* PUBG_XNCUT_ASSETS_INITIALIZER_H */
