#include "Point.h"

Point::Point() : _x(double{}), _y(double{}) {

}

Point::Point(double x, double y) : _x(x), _y(y) {

}

Point::~Point() {

}

double Point::getX() const {
    return _x;
}

void Point::setX(double newX) {
    _x = newX;   
}

double Point::getY() const {
    return _y;
}

void Point::setY(double newY) {
    _y = newY;
}

//

#include "EngineGlut.h"

void Point::draw() {
    _engine.drawPoint(_x, _y);
}

#include <iostream>

void Point::print() {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream& o, const Point& p) {
    o << "Point of coordinates X=" << p.getX() << " and Y=" << p.getY() << std::endl;

    return o;
}