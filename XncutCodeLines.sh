#!/bin/bash
###
# @Author: xixi_
# @Date: 2026-02-06 11:44:08
 # @LastEditors: xixi_
 # @LastEditTime: 2026-02-06 16:00:44
 # @FilePath: /Xncut/XncutCodeLines.sh
# Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
###

# 统计的文件后缀
FileTypes=("*.cpp" "*.h" "*.c" "*.S" "*.lua")

# 需要统计的源代码目录
Directories=(
    "Xncut"          # 熙柠剪辑宿主程序
    "XncutCore"      # 熙柠剪辑核心库
    "XncutMilkshake" # 熙柠剪辑渲染引擎
    "XncutPlugins"   # 熙柠剪辑插件
)

# 总行数
TotalLines=0

# 开始
echo "统计熙柠剪辑的代码总行数, 将会输出每一个目录的详细信息"

# 遍历每个定义的目录
for Dir in "${Directories[@]}"; do
    if [ -d "$Dir" ]; then
        echo "统计目录: $Dir"
        # 遍历每种文件类型
        for FileType in "${FileTypes[@]}"; do
            # 找到文件并统计行数
            count=$(find "$Dir" -name "$FileType" -exec cat {} + | wc -l)
            echo "$FileType 文件行数: $count"
            TotalLines=$((TotalLines + count))
        done
    else
        echo "$Dir 不是有效的目录"
    fi
done

echo "总行数: $TotalLines"