/*
 * @Author: xixi_
 * @Date: 2025-07-04 10:01:23
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-08 19:23:39
 * @FilePath: /Xncut/Xncut/XncutCore/XncutRunTimeContext.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_RUN_TIME_CONTEXT_H
#define XNCUT_RUN_TIME_CONTEXT_H

#include <QObject>

/*
 * 在V7.1版本引入上下文类
 * 能让代码活起来的类
 */

class XncutRunTimeContext : public QObject
{
    Q_OBJECT
public:
    /*
     * 构造
     * 构造时必须提供工作区目录
     * NB! 不能在堆区上构造, 必须在栈上构造
     */
    explicit XncutRunTimeContext(const char *WorkPath);
    ~XncutRunTimeContext();

    /* 获取工作区目录 */
    static const char *GetWorkPath();

    /* 获取工程目录 */
    static const char *GetProjectPath();

    /*
     * 获取熙柠剪辑的状态文件路径
     * 返回的路径将会和工作区路径有关
     * 例如工作区路径是`/home/yzx/.config/xncut`,那么此函数将返回`/home/yzx/.config/xncut/Xncut.json`
     */
    static const char *GetXncutPath();
    /********************************************************************************************************/

private:
    /* [封装功能] 路径拼接 */
    char *ConcatPath(const char *Base, const char *Relative);
    /********************************************************************************************************/

private slots:

protected:
signals:

private:
    /* 路径 */
    static const char *M_WorkPath; /* 工作区路径 */
    static char *M_ProjectPath;    /* 工程路径 */
    static char *M_XncutPath;      /* Xncut.json */
    /********************************************************************************************************/
};

#endif // XNCUT_RUN_TIME_CONTEXT_H
