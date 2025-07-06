/*
 * @Author: xixi_
 * @Date: 2025-07-04 10:01:12
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-06 16:15:59
 * @FilePath: /Xncut/Xncut/XncutCore/XncutRunTimeContext.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutRunTimeContext.h"
#include <stdlib.h>
#include "XncutFunTool.h"

const char *XncutRunTimeContext::M_WorkPath = NULL;
char *XncutRunTimeContext::M_ProjectPath = NULL;

XncutRunTimeContext::XncutRunTimeContext(const char *WorkPath)
    : QObject(NULL)
{
    /* 初始化工作区路径 */
    M_WorkPath = WorkPath;

    /*
     * 初始化工程目录
     * 首先,求出完整的路径大小
     * 然后使用malloc进行动态分配内存
     * 最后再使用snprintf函数拼接出完整的路径
     */
    int M_ProjectPathSize = strlen(WorkPath) + strlen("/Project") + 1;
    M_ProjectPath = (char *)malloc(M_ProjectPathSize);
    snprintf(M_ProjectPath, M_ProjectPathSize, "%s/%s", M_WorkPath, "Project"); /* 拼接 */
}

XncutRunTimeContext::~XncutRunTimeContext()
{
    free(M_ProjectPath);
}

const char *XncutRunTimeContext::GetWorkPath()
{
    return M_WorkPath;
}

const char *XncutRunTimeContext::GetProjectPath()
{
    return M_WorkPath;
}
