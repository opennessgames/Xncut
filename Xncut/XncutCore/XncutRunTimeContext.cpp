/*
 * @Author: xixi_
 * @Date: 2025-07-04 10:01:12
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-07 20:33:07
 * @FilePath: /Xncut/Xncut/XncutCore/XncutRunTimeContext.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutRunTimeContext.h"
#include <stdlib.h>
#include <QDebug>

const char *XncutRunTimeContext::M_WorkPath = NULL;
char *XncutRunTimeContext::M_ProjectPath = NULL;
char *XncutRunTimeContext::M_XncutPath = NULL;

XncutRunTimeContext::XncutRunTimeContext(const char *WorkPath)
    : QObject(NULL)
{
    /* 初始化工作区路径 */
    M_WorkPath = WorkPath;

    /* 初始化工程目录 */
    M_ProjectPath = ConcatPath(M_WorkPath, "Project");

    /* 初始化Xncut.json路径 */
    M_XncutPath = ConcatPath(M_WorkPath, "Xncut.json");

    /* 打印日志 */
    qDebug() << "Working path: " << M_WorkPath;
}

XncutRunTimeContext::~XncutRunTimeContext()
{
    free(M_ProjectPath);
    free(M_XncutPath);
}

const char *XncutRunTimeContext::GetWorkPath()
{
    return M_WorkPath;
}

const char *XncutRunTimeContext::GetProjectPath()
{
    return M_WorkPath;
}

const char *XncutRunTimeContext::GetXncutPath()
{
    return M_XncutPath;
}

char *XncutRunTimeContext::ConcatPath(const char *Base, const char *Relative)
{

    size_t PathSize = strlen(Base) + strlen(Relative) + 2; /* +2 for '/' and '\0' */
    char *FullPath = (char *)malloc(PathSize);
    if (!FullPath)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE); /* Handle memory allocation failure */
    }
    snprintf(FullPath, PathSize, "%s/%s", Base, Relative);
    return FullPath;
}
