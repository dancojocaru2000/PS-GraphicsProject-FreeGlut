#ifndef DC_RECTANGLE_H
#define DC_RECTANGLE_H

#include "Point.h"

class Rectangle {
private:
    Point _points[4];
    bool _filled;

public:
    Rectangle();
    Rectangle(Point p1, Point p2, Point p3, Point p4, bool filled);
    ~Rectangle();

    static Rectangle filled(Point p1, Point p2, Point p3, Point p4);
    static Rectangle empty(Point p1, Point p2, Point p3, Point p4);

    void draw();
};

#endif