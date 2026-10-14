#
# @Author: xixi_
# @Date: 2026-10-09 15:47:52
# @LastEditors: xixi_
# @LastEditTime: 2026-10-09 15:47:54
# @FilePath: /Xncut/Dockerfile
# Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
#

# 有点难, 还在研究
FROM ubuntu:22.04 AS builder
ENV DEBIAN_FRONTEND=noninteractive \
    QT_VERSION=6.12.0 \
    QT_PATH=/home/milkshake/Qt

RUN apt-get update &&

