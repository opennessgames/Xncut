#!/bin/bash
###
# @Author: xixi_
# @Date: 2026-03-11 19:50:44
 # @LastEditors: xixi_
 # @LastEditTime: 2026-03-12 19:34:07
 # @FilePath: /Xncut/build/Bin/XncutCheckError.sh
# Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
###

valgrind --leak-check=full ./Xncut --platform xcb  > ERROR.txt 2>&1