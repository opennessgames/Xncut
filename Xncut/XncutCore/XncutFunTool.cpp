/*
 * @Author: xixi_
 * @Date: 2025-07-06 15:45:06
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-08 22:48:05
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

bool XncutFunTool::ReadJsonFile(cJSON **DestObject, const char *SrcFilePath)
{
    /* 如果DestObject是有效的,或者SrcFilePath是无效的,不应该继续执行 */
    if (*DestObject || !SrcFilePath)
    {
        return false;
    }

    FILE *JsonFile = fopen(SrcFilePath, "r"); /* 以只读模式打开 */
    if (!JsonFile)
    {
        *DestObject = NULL;
        return false;
    }
    /* 跳到文件末尾以获取文件的大小 */
    fseek(JsonFile, 0, SEEK_END);
    int JsonFileSize = ftell(JsonFile);
    rewind(JsonFile);

    /**
     * 分配足够的内存,
     * TODO: 这里还有个问题: 如果JSON文件很大,内存很小的情况
     * */
    char *JsonString = (char *)malloc(JsonFileSize + 1);
    if (!JsonString)
    {
        fclose(JsonFile);
        *DestObject = NULL;
        return false;
    }
    /* 读取文件的内容 */
    int ReadSize = fread(JsonString, 1, JsonFileSize, JsonFile);
    JsonString[ReadSize] = '\0'; /* 加入结束符 */

    /* 尝试解析 */
    *DestObject = cJSON_Parse(JsonString);

    /**
     * 释放资源
     * 注意,这里不应该释放掉JSON对象
     * */
    fclose(JsonFile);
    free(JsonString);
    return true;
}

bool XncutFunTool::WriteJson(cJSON *SrcObject, const char *DestFilePath, bool IsFreeSrcObject)
{
    /* 对象无效或者路径无效时,不应该继续执行 */
    if (!SrcObject || !DestFilePath)
    {
        return false;
    }

    /* JSON文件指针 */
    FILE *JsonFile = fopen(DestFilePath, "w"); /* 以写的模式进行 */
    if (!JsonFile)
    {
        return false; /* 无效的指针应该停止执行 */
    }

    /**
     * 将cJSON转换成字符串,
     * 值得注意的是, 不应该提前转换, 如果fopen失败时, 这将会多一个free的步骤
     * */
    char *JsonString = cJSON_PrintUnformatted(SrcObject);
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
