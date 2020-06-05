#include "Point.h"

Point::Point() : _x(double{}), _y(double{}) {

}

Point::Point(double x, double y) : _x(x), _y(y) {

}

Point::~Point() {

}

double Point::getX() {
    return _x;
}

void Point::setX(double newX) {
    _x = newX;   
}

double Point::getY() {
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