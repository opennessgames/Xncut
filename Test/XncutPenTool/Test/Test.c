/*
 * @Author: xixi_
 * @Date: 2025-08-10 21:40:51
 * @LastEditors: xixi_
 * @LastEditTime: 2025-08-10 23:46:11
 * @FilePath: /Xncut/Test/XncutPenTool/Test/Test.c
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include <stdio.h>
#include <math.h>

// 定义一个结构体表示二维点
typedef struct
{
    double x;
    double y;
} Point;

// 计算两个点之间的距离
double distance(Point p1, Point p2)
{
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

// 计算三次贝塞尔曲线的点
void cubicBezier(double t, Point P0, Point P1, Point P2, Point P3, Point *B)
{
    double u = 1 - t;
    double tt = t * t;
    double uu = u * u;
    double uuu = uu * u;
    double ttt = tt * t;

    B->x = uuu * P0.x + 3 * uu * t * P1.x + 3 * u * tt * P2.x + ttt * P3.x;
    B->y = uuu * P0.y + 3 * uu * t * P1.y + 3 * u * tt * P2.y + ttt * P3.y;
}

// 判断点是否在贝塞尔曲线附近
int isPointOnBezier(Point P, Point P0, Point P1, Point P2, Point P3, double threshold, int steps)
{
    for (double t = 0; t <= steps; t++)
    { // t从0到1，步长为0.001
        Point B;
        cubicBezier(t / steps, P0, P1, P2, P3, &B);

        // 计算点与曲线点之间的距离
        double dist = distance(P, B);

        if (dist < threshold)
        {
            return 1; // 点在贝塞尔曲线上
        }
    }
    return 0; // 点不在贝塞尔曲线上
}

int main()
{
    // 定义四个控制点
    Point P0 = {134, 313}; // 锚点P0
    Point P1 = {250, 110}; // 控制点P1
    Point P2 = {736, 324}; // 控制点P2
    Point P3 = {736, 324}; // 锚点P3

    // 定义待判断的点
    Point P = {327, 223};

    // 定义阈值
    double threshold = 10.0;

    // 判断点是否在曲线附近
    if (isPointOnBezier(P, P0, P1, P2, P3, threshold, 100))
    {
        printf("点在贝塞尔曲线附近。\n");
    }
    else
    {
        printf("点不在贝塞尔曲线附近。\n");
    }

    return 0;
}
