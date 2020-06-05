#include "Triangle.h"

Triangle::Triangle() : Triangle(Point{}, Point{}, Point{}, false) {}

Triangle::Triangle(Point p1, Point p2, Point p3, bool filled) {
    _points[0] = p1;
    _points[1] = p2;
    _points[2] = p3;

    _filled = filled;
}

Triangle::~Triangle() {}

Triangle Triangle::filled(Point p1, Point p2, Point p3) {
    return Triangle(p1, p2, p3, true);
}

Triangle Triangle::empty(Point p1, Point p2, Point p3) {
    return Triangle(p1, p2, p3, false);
}

//

#include "EngineGlut.h"
#include "Line.h"

void Triangle::draw() {
    if (_filled) {
        _engine.drawSurface(
            _points[0].getX(), _points[0].getY(),
            _points[1].getX(), _points[1].getY(),
            _points[2].getX(), _points[2].getY()
        );
    }
    else {
        Line(_points[0], _points[1]).draw();
        Line(_points[1], _points[2]).draw();
        Line(_points[2], _points[0]).draw();
    }
}