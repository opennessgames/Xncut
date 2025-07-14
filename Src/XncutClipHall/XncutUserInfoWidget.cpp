/*
 * @Author: xixi_
 * @Date: 2025-07-14 17:20:41
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-14 17:51:23
 * @FilePath: /XncutUI/Src/XncutClipHall/XncutUserInfoWidget.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "XncutUserInfoWidget.h"

XncutUserInfoWidget::XncutUserInfoWidget(QWidget *Parent)
    : QHBoxLayout(Parent)
{
    /* 初始化 */
    /* 用户头像 */
    M_UserAvatar = new QPushButton(); /* 头像按钮 */
    /* 用户信息 */
    M_UserInfoLayout = new QVBoxLayout();        /* 布局 */
    M_UserName = new QLabel("是小祯祯吖~");      /* 用户名字标签 */
    M_UserVipLevel = new QLabel("VIPPPP114514"); /* 用户等级标签 */
    M_UserVipLogo = new QLabel();                /* VIP等级图标 */
    /********************************************************************************************************/

    /* 用户信息布局 */
    M_UserInfoLayout->setContentsMargins(0, 0, 0, 0);
    M_UserInfoLayout->setSpacing(0);
    M_UserInfoLayout->addWidget(M_UserName);
    M_UserInfoLayout->addWidget(M_UserVipLevel);
    M_UserInfoLayout->addWidget(M_UserVipLogo);
    /********************************************************************************************************/

    /* 主布局 */
    setContentsMargins(0, 0, 0, 0);
    addWidget(M_UserAvatar);
    addLayout(M_UserInfoLayout);
    /********************************************************************************************************/
}

void XncutUserInfoWidget::SetUserAvatarSize(int Size)
{
    M_UserAvatar->setFixedSize(Size, Size);
    M_UserAvatar->setIconSize(QSize(Size, Size));
}

void XncutUserInfoWidget::SetUserAvatar(QString ImageUrl)
{
    M_UserAvatar->setIcon(QIcon(ImageUrl));
}

void XncutUserInfoWidget::SetVipLevelIcon(QPixmap VipLevelIcon)
{
    M_UserVipLogo->setPixmap(VipLevelIcon);
}
