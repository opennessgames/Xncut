/*
 * @Author: xixi_
 * @Date: 2025-07-06 15:44:47
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-07 21:45:20
 * @FilePath: /Xncut/Xncut/XncutCore/XncutFunTool.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_FUN_TOOL_H
#define XNCUT_FUN_TOOL_H

#include <xixi/cJSON.h>

class XncutFunTool
{
public:
    XncutFunTool();

    /*
     * 读取JSON文件,将JSON字符串转换成cJSON对象
     * NB! 如果`DestObject`不是NULL,将会返回`false`,
     * `DestObject`必须是`NULL`时才会返回`true`;
     */
    static bool ReadJsonFile(cJSON **DestObject, const char *SrcFilePath);

    /*
     * 将cJSON对象以字符串形式写入到磁盘
     * NB! 若此文件(即DestPath)存在,内容将会完全覆盖掉!
     */
    static bool WriteJson(cJSON *SrcObject, const char *DestFilePath, bool IsFreeSrcObject);
    /********************************************************************************************************/
};

#endif // XNCUT_FUN_TOOL_H
