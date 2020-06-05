#ifndef DC_LINE_H
#define DC_LINE_H

#include "Point.h"
#include "Shape.h"

class Line : public Shape {
private:
    Point _points[2];

public:
    Line();
    Line(Point p1, Point p2);
    ~Line();

    void draw() override;
};

#endif