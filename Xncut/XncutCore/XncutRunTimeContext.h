/*
 * @Author: xixi_
 * @Date: 2025-07-04 10:01:23
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-06 16:19:26
 * @FilePath: /Xncut/Xncut/XncutCore/XncutRunTimeContext.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_RUN_TIME_CONTEXT_H
#define XNCUT_RUN_TIME_CONTEXT_H

#include <QObject>

/*
 * 在V7.1版本引入上下文类
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
    /********************************************************************************************************/

private:
private slots:

protected:
signals:

private:
    /* 路径 */
    static const char *M_WorkPath; /* 工作区路径 */
    static char *M_ProjectPath;    /* 工程路径 */
    /********************************************************************************************************/
};

#endif // XNCUT_RUN_TIME_CONTEXT_H
