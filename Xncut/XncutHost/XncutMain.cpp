/*
 * @Author: xixi_
 * @Date: 2024-07-09 01:42:04
 * @LastEditors: xixi_
 * @LastEditTime: 2026-10-12 16:07:33
 * @FilePath: /Xncut/Xncut/XncutHost/XncutMain.cpp
 * Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
 */

#include <QApplication>
#include <XncutAssetsInitializer.h>
#include "Xncut.h"

int main(int argc, char **argv, char **envp)
{
    qDebug() << "PUBG:XNCUT is starting...";
    qDebug() << "与其用语言刷存在感, 不如用实力制造压迫感";
    qDebug() << "压制、手法、绝境、突破、自我、证明、巅峰、枷锁、答案、依赖、尽头、诠释、冷静、逆境、自信、无限、打破、困局、质疑、逆转、磨炼、极限、止步、假象、结果、终将、问鼎、挣脱、限制、领域、绝巅、过去、诀别、压制、手法、绝境、突破、自我、证明、巅峰、枷锁、答案、依赖、尽头、诠释、冷静、逆境、自信、无限、打破、困局、质疑、逆转、磨炼、极限、止步、假象、结果、终将、问鼎、挣脱、限制、领域、绝巅";
    qDebug() << "项目代号: 香飘飘星河";

    /* Initialize key services */
    XncutAssetsInitializer::init();

    /* App */
    QApplication openGameApplication(argc, argv);
    openGameApplication.setApplicationVersion(PUBG_XNCUT_VERSION);
    openGameApplication.setApplicationName("PUBGXNCUT");
    openGameApplication.setApplicationDisplayName("熙柠剪辑2022");

    /* Xncut */
    Xncut xncutApplication;
    xncutApplication.show();

    /* Exec */
    return QApplication::exec();
}