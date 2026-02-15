/*
 * @Author: xixi_
 * @Date: 2025-10-26 23:27:00
 * @LastEditors: xixi_
 * @LastEditTime: 2026-02-15 13:39:37
 * @FilePath: /Xncut/XncutCores/XncutCore/XncutPluginFramework/XncutAbstractPlugin.h
 * Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
 */

#ifndef XNCUT_ABSTRACT_PLUGIN_H
#define XNCUT_ABSTRACT_PLUGIN_H

#include <QObject>
#include <QVariantMap>

/**
 * @class XncutAbstractPlugin
 * @brief 高度抽象的插件类
 * @note 有多个虚函数必须要实现
 **/
class __attribute__((visibility("default"))) XncutAbstractPlugin : public QObject
{
    Q_OBJECT
private:
    /********************************************************************************************************/

    /********************************************************************************************************/

protected:
    /* 插件消息 */
    typedef struct
    {
        QString SenderPluginName; /* 发送着名称 */
        QString MessageType;      /* 消息类型 */
        QVariantMap MessageData;  /* 消息数据 */
    } XncutPluginMessage;
    /********************************************************************************************************/

    /********************************************************************************************************/

public:
    explicit XncutAbstractPlugin();
    ~XncutAbstractPlugin() = default;
    XncutAbstractPlugin(const XncutAbstractPlugin &) = delete;
    XncutAbstractPlugin &operator=(const XncutAbstractPlugin &) = delete;
    /********************************************************************************************************/

    /* 初始化 */
    virtual bool Init() = 0;

    /* 反向初始化 */
    virtual bool UnInit() = 0;

    /* 插件名称 */
    virtual QString GetPluginName() const = 0;

    /* 插件ID */
    virtual const int GetPluginId() const = 0;

    /* 插件版本 */
    virtual QString GetPluginVersion() const = 0;

    /* 插件描述 */
    virtual QString GetPluginDescription() const = 0;

    /* 获取插件数据 */
    virtual void *GetData() = 0;

    /**
     * @brief 处理消息
     * TODO: 函数命名不是很好
     **/
    virtual void Messages(XncutPluginMessage &Message) = 0;

    /**
     * @brief 插件类别
     * @return
     **/
    virtual QString GetCategory() const = 0;
    /********************************************************************************************************/

    /********************************************************************************************************/

public slots:
    /********************************************************************************************************/

    /********************************************************************************************************/

private:
    /********************************************************************************************************/

    /********************************************************************************************************/

private slots:
    /********************************************************************************************************/

    /********************************************************************************************************/

protected:
    /* 重载方法 */
    /********************************************************************************************************/

    /********************************************************************************************************/

signals:
    /********************************************************************************************************/

    /********************************************************************************************************/

private:
    /********************************************************************************************************/

    /********************************************************************************************************/
};

Q_DECLARE_INTERFACE(XncutAbstractPlugin, "openGAME.XncutPluginFramework.XncutAbstractPlugin/1.0.0")

#endif // XNCUT_ABSTRACT_PLUGIN_H