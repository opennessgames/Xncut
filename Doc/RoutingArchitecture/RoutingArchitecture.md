<!--
 * @Author: xixi_
 * @Date: 2026-02-07 01:27:33
 * @LastEditors: xixi_
 * @LastEditTime: 2026-02-07 01:50:49
 * @FilePath: /XncutUI/Doc/RoutingArchitecture/RoutingArchitecture.md
 * Copyright (c) 2020-2026 by xixi_ , All Rights Reserved.
-->

# 路由架构
> Q: 解决了什么问题? A: 页面之间复杂的跳转与通信问题

# 回顾
> 我们之前是这样实现页面跳转的:
1. 主窗口类有若干的跳转函数和内容部件(多个页面)
```cpp
class Xncut : public QMainWindow /* 主窗口类 */
{
private slots:
    /* 跳转界面函数 */
    /* 跳转到大厅 */
    void JmpHall();

    /* 跳转到工程管理 */
    void JmpProjectManager();

    /* 跳转到编辑器 */
    void JmpEditor();

private:
    /* 主部件 */
    QStackedWidget *M_CentralStackedWidget = NULL; /* 中心控件 */

    /* 内容部件 */
    XncutClipHallWidget *M_ClipHallWidget = NULL;             /* 剪辑大厅 */
    XncutProjectManagerWidget *M_ProjectManagerWidget = NULL; /* 工程管理器 */
    XncutEditorWidget *M_EditorWidget = NULL;                 /* 编辑器 */
};
```
2. 每一个子页面都有HasJmpClipHallRequest()信号
3. 主界面连接这些子页面跳转信号和对应的跳转槽, 就像这样: 
```cpp
    connect(M_ClipHallWidget, &XncutClipHallWidget::HasJmpProjectManagerRequest, this, &Xncut::JmpProjectManager);
    connect(M_ClipHallWidget, &XncutClipHallWidget::HasJmpEditorRequest, this, &Xncut::JmpEditor);
    connect(M_ProjectManagerWidget, &XncutProjectManagerWidget::HasJmpClipHallRequest, this, &Xncut::JmpHall);
    connect(M_EditorWidget, &XncutEditorWidget::HasJmpClipHallRequest, this, &Xncut::JmpHall);
```

# 后期的问题:
> 后期问题还是很大的, 我们注意到, 返回按钮的实例重复了, 内存浪费, 维护变得困难了一些, 页面通信和跳转都不够灵活.<br/> 假设有100个界面, 难道需要连接100个槽函数吗? new 100返回按钮吗? <br/>当然不会, 这会变成大屎山的, 我们必须寻找一个解决这个难题的方案: 使用**路由架构**来实现上述功能; 微信小程序, 美团的框架也是用这种架构.

<!-- 啊啊啊啊啊啊啊啊啊啊啊啊啊啊!!!!! -->