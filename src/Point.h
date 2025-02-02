#ifndef DC_VECTOR2_H
#define DC_VECTOR2_H

#include "Shape.h"
#include <ostream>

class Point : public Shape {
private:
    double _x;
    double _y;

public:
    Point();
    Point(double x, double y);
    ~Point();

    double getX() const;
    void setX(double newX);

    double getY() const;
    void setY(double newY);

    void draw() override;
    void print() override;

    friend std::ostream& operator<<(std::ostream& o, const Point& p);
};

#endif