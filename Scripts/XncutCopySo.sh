###
# @Author: xixi_
# @Date: 2026-04-30 20:36:40
# @LastEditors: xixi_
# @LastEditTime: 2026-04-30 20:36:41
# @FilePath: /Xncut/Scripts/XncutCopySo.sh
# Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
###


deplist=$( ldd $1 | awk '{if (match($3,"/")){ print $3}}' )

cp -L -n $deplist $2