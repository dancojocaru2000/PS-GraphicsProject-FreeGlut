#ifndef DC_VECTOR2_H
#define DC_VECTOR2_H

#include "Shape.h"

class Point : public Shape {
private:
    double _x;
    double _y;

public:
    Point();
    Point(double x, double y);
    ~Point();

    double getX();
    void setX(double newX);

    double getY();
    void setY(double newY);

    void draw() override;
};

#endif