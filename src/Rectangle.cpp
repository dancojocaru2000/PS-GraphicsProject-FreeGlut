#include "Rectangle.h"

Rectangle::Rectangle() : Rectangle(Point{}, Point{}, Point{}, Point{}, false) {}

Rectangle::Rectangle(Point p1, Point p2, Point p3, Point p4, bool filled) {
    _points[0] = p1;
    _points[1] = p2;
    _points[2] = p3;
    _points[3] = p4;

    _filled = filled;
}

Rectangle::~Rectangle() {}

Rectangle Rectangle::filled(Point p1, Point p2, Point p3, Point p4) {
    return Rectangle(p1, p2, p3, p4, true);
}

Rectangle Rectangle::empty(Point p1, Point p2, Point p3, Point p4) {
    return Rectangle(p1, p2, p3, p4, false);
}

//

#include "EngineGlut.h"
#include "Line.h"

void Rectangle::draw() {
    EngineGlut e;

    if (_filled) {
        e.drawSurface(
            _points[0].getX(), _points[0].getY(),
            _points[1].getX(), _points[1].getY(),
            _points[2].getX(), _points[2].getY()
        );
        e.drawSurface(
            _points[0].getX(), _points[0].getY(),
            _points[3].getX(), _points[3].getY(),
            _points[2].getX(), _points[2].getY()
        );
    }
    else {
        Line(_points[0], _points[1]).draw();
        Line(_points[1], _points[2]).draw();
        Line(_points[2], _points[3]).draw();
        Line(_points[3], _points[0]).draw();
    }
}