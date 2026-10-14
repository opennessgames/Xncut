/*
 * @Author: xixi_
 * @Date: 2025-10-01 14:33:13
 * @LastEditors: xixi_
 * @LastEditTime: 2026-10-13 12:32:34
 * @FilePath: /Xncut/Xncut/XncutWelcome/XncutBootloader.h
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
 */

#ifndef PUBG_XNCUT_BOOTLOADER_H
#define PUBG_XNCUT_BOOTLOADER_H

#include <QThread>

/**
 * @brief The XncutBootloader class
 * @brief 后台加载器
 * @note
 * @note 后台启动加载线程
 * @note 避免页面卡成一坨翔
 * @note
 * @note 我发呆的时候常常会想 我这样的人 会和什么样的人有以后呢
 **/
class Q_DECL_HIDDEN XncutBootloader : public QThread
{
    Q_OBJECT
public:
    explicit XncutBootloader(QObject *parent = nullptr);
    ~XncutBootloader();
    XncutBootloader(const XncutBootloader &) = delete;
    XncutBootloader &operator=(const XncutBootloader &) = delete;
    XncutBootloader(const XncutBootloader &&) = delete;
    XncutBootloader &operator=(const XncutBootloader &&) = delete;

public slots:

protected:
    void run() override;

signals:
    void progressChange(int);

private:
};

#endif /* PUBG_XNCUT_BOOTLOADER_H */