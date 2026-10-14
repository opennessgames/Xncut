###
# @Author: xixi_
# @Date: 2026-05-27 17:25:27
# @LastEditors: xixi_
# @LastEditTime: 2026-05-27 17:25:29
# @FilePath: /Xncut/Scripts/XncutRename.sh
# Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
###

find . -name "*.cc" -type f | while read file; do
    mv "$file" "${file%.cc}.cpp"
done