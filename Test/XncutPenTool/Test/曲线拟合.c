/*
 * @Author: xixi_
 * @Date: 2025-09-27 15:26:47
 * @LastEditors: xixi_
 * @LastEditTime: 2025-09-27 16:03:49
 * @FilePath: /Xncut/Test/XncutPenTool/Test/曲线拟合.c
 * Copyright (c) 2020-2025 by xixi_ , All Rights Reserved.
 */

#include <stdio.h>

typedef struct
{
    int X;
    int Y;
} Point2D;

void splitCublicBezier(Point2D Point1, Point2D Point2, Point2D Point3, Point2D Point4, float t)
{
    Point2D a = lerp(Point1, Point2, t);
    Point2D b = lerp(Point2, Point3, t);
    Point2D c = lerp(Point3, Point4, t);

    Point2D d = lerp(a, b, t);
    Point2D e = lerp(b, c, t);

    Point2D f = lerp(d, e, t);

    /* return {{Point1, a, d, f}, {f, e, c, Point4}}; */
}

Point2D lerp(Point2D Point1, Point2D Point2, float t)
{
    return (Point2D){
        .X = Point1.X + (Point2.X - Point1.X) * t,
        .Y = Point1.Y + (Point2.Y - Point1.Y) * t,
    };
}

int main()
{
}