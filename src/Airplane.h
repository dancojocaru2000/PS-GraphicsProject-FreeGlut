#ifndef GRAPHICSPROJECT_AIRPLANE_H
#define GRAPHICSPROJECT_AIRPLANE_H

#include "Point.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Shape.h"
#include <ostream>

class Airplane : public Shape {
private:
    Triangle _triangles[5];
    Point _points[2];
    Rectangle _rectangles[1];

public:
    Airplane();
    Airplane(Point bottomLeftCorner, int width, int height);

    void draw() override;
    void print() override;

    friend std::ostream& operator<<(std::ostream& o, const Airplane& a);
};

#endif //GRAPHICSPROJECT_AIRPLANE_H
