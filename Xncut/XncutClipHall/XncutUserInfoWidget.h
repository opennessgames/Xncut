/*
 * @Author: xixi_
 * @Date: 2025-07-02 13:30:46
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-02 13:38:57
 * @FilePath: /Xncut/Xncut/XncutClipHall/XncutUserInfoWidget.h
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_USER_INFO_WIDGET_H
#define XNCUT_USER_INFO_WIDGET_H

#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

class XncutUserInfoWidget : public QHBoxLayout
{
    Q_OBJECT
public:
    explicit XncutUserInfoWidget(QWidget *Parent = NULL);

    /* 设置用户头像大小 */
    void SetUserAvatarSize(int Size);

    /* 设置用户头像 */
    void SetUserAvatar(QString ImageUrl);

    /* 设置VIP等级图标 */
    void SetVipLevelIcon(QPixmap VipLevelIcon);
    /********************************************************************************************************/

private:
private slots:

protected:
signals:

private:
    /* 用户头像 */
    QPushButton *M_UserAvatar = NULL;
    /********************************************************************************************************/

    /* 用户信息 */
    QVBoxLayout *M_UserInfoLayout = NULL; /* 布局 */
    QLabel *M_UserName = NULL;            /* 用户名称 */
    QLabel *M_UserVipLevel = NULL;        /* 用户VIP等级 */
    QLabel *M_UserVipLogo = NULL;         /* VIP等级图标 */
    /********************************************************************************************************/
};

#endif // XNCUT_USER_INFO_WIDGET_H