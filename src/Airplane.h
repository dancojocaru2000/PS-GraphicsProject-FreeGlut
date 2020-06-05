#ifndef GRAPHICSPROJECT_AIRPLANE_H
#define GRAPHICSPROJECT_AIRPLANE_H

#include "Point.h"
#include "Triangle.h"
#include "Rectangle.h"

class Airplane {
private:
    Triangle _triangles[5];
    Point _points[2];
    Rectangle _rectangles[1];

public:
    Airplane();
    Airplane(Point bottomLeftCorner, int width, int height);

    void draw();
};

#endif //GRAPHICSPROJECT_AIRPLANE_H
