#ifndef GRAPHICSPROJECT_ROBOT_H
#define GRAPHICSPROJECT_ROBOT_H

#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Shape.h"
#include <ostream>

class Robot : public Shape {
private:
    Triangle _triangles[1];
    Point _points[2];
    Rectangle _rectangles[2];
    Line _lines[6];

public:
    Robot();
    Robot(Point bottomLeftCorner, int width, int height);

    void draw() override;
    void print() override;

    friend std::ostream& operator<<(std::ostream& o, const Robot& a);
};

#endif //GRAPHICSPROJECT_ROBOT_H
