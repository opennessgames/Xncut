/*
 * @Author: xixi_
 * @Date: 2025-07-02 12:35:08
 * @LastEditors: xixi_
 * @LastEditTime: 2025-07-07 20:36:32
 * @FilePath: /Xncut/Xncut/Xncut.cpp
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include "Xncut.h"
#include <xixi/cJSON.h>
#include <QSettings>
#include "XncutCore/XncutFunTool.h"
#include "XncutCore/XncutRunTimeContext.h"

Xncut::Xncut(QWidget *Parent)
    : QMainWindow(Parent)
{
    /* 初始化 */
    M_CentralStackedWidget = new QStackedWidget();

    /* 核心部件 */
    M_ClipHallWidget = new XncutClipHallWidget();             /* 大厅 */
    M_ProjectManagerWidget = new XncutProjectManagerWidget(); /* 工程管理器 */
    /********************************************************************************************************/

    /* 设置属性 */
    M_CentralStackedWidget->setContentsMargins(10, 10, 10, 10);
    M_CentralStackedWidget->addWidget(M_ClipHallWidget);
    M_CentralStackedWidget->addWidget(M_ProjectManagerWidget);
    M_CentralStackedWidget->setCurrentWidget(M_ClipHallWidget);
    /********************************************************************************************************/

    /* 设置中心控件 */
    setCentralWidget(M_CentralStackedWidget);
    /********************************************************************************************************/

    /* 连接信号槽 */
    /* 剪辑大厅 */
    connect(M_ClipHallWidget, &XncutClipHallWidget::HasJmpProjectManagerRequest, this, &Xncut::JmpProjectManager);
    connect(M_ClipHallWidget, &XncutClipHallWidget::HasJmpEditorRequest, this, &Xncut::JmpEditor);
    /* 工程管理器 */
    connect(M_ProjectManagerWidget, &XncutProjectManagerWidget::HasJmpClipHallRequest, this, &Xncut::JmpHall);
    /********************************************************************************************************/
}

Xncut::~Xncut()
{
    Sync(); /* 数据持久化 */
    qDebug() << "Exit PUGB:XNCUT...";
}

void Xncut::Sync()
{
    /* 保存大厅数据 */
    /* 创建JSON对象 */
    QStandardItemModel *StandardItemModel = M_ClipHallWidget->GetRecentProjectCardModel();
    cJSON *Root = cJSON_CreateObject();         /* 根对象 */
    cJSON *RecentProject = cJSON_CreateArray(); /* 最近工程数组 */

    /* 逐个添加进数组 */
    for (int i = 0; i < StandardItemModel->rowCount(); i++)
    {
        QStandardItem *Item = StandardItemModel->item(i);
        cJSON *ProjectJsonObject = cJSON_CreateObject();
        cJSON_AddStringToObject(ProjectJsonObject, "XName", Item->text().toUtf8().data());
        cJSON_AddStringToObject(ProjectJsonObject, "XDescription",
                                qvariant_cast<QString>(Item->data(XncutRecentProjectCardDelegate::PRO_CARD_DATA_DESCRIPTION)).toUtf8().data());
        cJSON_AddItemToArray(RecentProject, ProjectJsonObject);
    }

    /* 添加到根对象 */
    cJSON_AddStringToObject(Root, "XCurrentProject", M_ClipHallWidget->GetCurrentProject().toUtf8().data());
    cJSON_AddItemToObject(Root, "XRecentProjectList", RecentProject);

    /* 写入到磁盘 */
    qDebug() << XncutFunTool::WriteJson(Root, XncutRunTimeContext::GetXncutPath(), true);
    /********************************************************************************************************/
}

void Xncut::JmpHall()
{
    M_CentralStackedWidget->setCurrentWidget(M_ClipHallWidget);
    setWindowTitle("剪辑大厅");
}

void Xncut::JmpProjectManager()
{
    M_CentralStackedWidget->setCurrentWidget(M_ProjectManagerWidget);
    setWindowTitle("工程管理");
}

void Xncut::JmpEditor()
{
}

void Xncut::closeEvent(QCloseEvent *Event)
{
    /* 窗口是否被修改 */
    if (isWindowModified())
    {
    }
}
