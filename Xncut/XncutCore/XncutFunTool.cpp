/*
 * @Author: xixi_
 * @Date: 2025-07-06 15:45:06
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-07 20:34:21
 * @FilePath: /Xncut/Xncut/XncutCore/XncutFunTool.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */
#include "XncutFunTool.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

XncutFunTool::XncutFunTool()
{
}

bool XncutFunTool::WriteJson(cJSON *SrcObject, const char *DestPath, bool IsFreeSrcObject)
{
    /* 对象无效或者路径无效时,不应该继续执行 */
    if (!SrcObject || !DestPath)
    {
        return false;
    }

    /* JSON文件指针 */
    FILE *JsonFile = fopen(DestPath, "w"); /* 以写的模式进行 */
    if (!JsonFile)
    {
        return false; /* 无效的指针应该停止执行 */
    }

    /*
     * 将cJSON转换成字符串,
     * 值得注意的是, 不应该提前转换, 如果fopen失败时, 这将会多一个free的步骤
     */
    char *JsonString = cJSON_Print(SrcObject);
    int JsonStringLen = strlen(JsonString); /* 计算字符串长度 */
    int BufferSize = 1024;                  /* 缓冲区大小 */
    int WriterLen = 0;

    /* 写入 */
    while (WriterLen < JsonStringLen)
    {
        int ChunkSize = (JsonStringLen - WriterLen < BufferSize) ? (JsonStringLen - WriterLen) : BufferSize;
        WriterLen += fwrite(JsonString + WriterLen, 1, ChunkSize, JsonFile);
    }

    /* 写入完成后,清理资源 */
    fclose(JsonFile);
    free(JsonString);
    if (IsFreeSrcObject)
    {
        cJSON_Delete(SrcObject);
        SrcObject = NULL;
    }
    JsonFile = NULL;
    JsonString = NULL;

    /* 写入完毕 */
    return true;
}