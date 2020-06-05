#include "Line.h"

Line::Line() : Line(Point{}, Point{}) {}

Line::Line(Point p1, Point p2) {
    _points[0] = p1;
    _points[1] = p2;
}

Line::~Line() {

}

//

#include "EngineGlut.h"

void Line::draw() {
    _engine.drawLine(
        _points[0].getX(), _points[0].getY(),
        _points[1].getX(), _points[1].getY()
    );
}

#include <iostream>

void Line::print() {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream& o, const Line& l) {
    o << "Line defined by two points:" << std::endl;
    o << "  " << l._points[0];
    o << "  " << l._points[1];

    return o;
}