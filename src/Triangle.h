#ifndef DC_TRIANGLE_H
#define DC_TRIANGLE_H

#include "Point.h"
#include "Shape.h"
#include <ostream>

class Triangle : public Shape {
private:
    Point _points[3];
    bool _filled;

public:
    Triangle();
    Triangle(Point p1, Point p2, Point p3, bool filled);
    ~Triangle();

    static Triangle filled(Point p1, Point p2, Point p3);
    static Triangle empty(Point p1, Point p2, Point p3);

    void draw() override;
    void print() override;

    friend std::ostream& operator<<(std::ostream& o, const Triangle& t);
};

#endif