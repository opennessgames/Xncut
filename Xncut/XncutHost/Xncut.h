/*
 * @Author: xixi_
 * @Date: 2024-07-09 01:42:04
 * @LastEditors: xixi_
 * @LastEditTime: 2026-10-12 15:46:32
 * @FilePath: /Xncut/Xncut/XncutHost/Xncut.h
 * Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
 */

#ifndef PUBG_XNCUT_H
#define PUBG_XNCUT_H

#include <QMainWindow>

/* 白允y nb */

class Xncut : public QMainWindow
{
    Q_OBJECT

public:
    explicit Xncut(QWidget *parent = nullptr);
    ~Xncut();
    Xncut(const Xncut &) = delete;
    Xncut &operator=(const Xncut &) = delete;
    Xncut(const Xncut &&) = delete;
    Xncut &operator=(const Xncut &&) = delete;

    /* [OpenXncut] */

private:
};

#endif /* PUBG_XNCUT_H */