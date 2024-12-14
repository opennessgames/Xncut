/*
 * @Author: xixi_
 * @Date: 2024-12-14 20:10:09
 * @LastEditors: xixi_
 * @LastEditTime: 2024-12-14 20:36:54
 * @FilePath: /pubg-xncut-mvp/XncutMvp/main.cpp
 * Copyright (c) 2020-2024 by xixi_ , All Rights Reserved.
 */
#include "PubgXncutMvp.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages)
    {
        const QString baseName = "PubgXncutMvp_" + QLocale(locale).name();
        if (translator.load(QDir::currentPath() + "/Translations/" + baseName))
        {
            a.installTranslator(&translator); /* 应用翻译 于2024年11月25日 2:25:27解锁 */
            break;
        }
    }

    PubgXncutMvp w;
    w.show();
    return a.exec();
}
