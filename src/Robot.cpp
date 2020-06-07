#include "Robot.h"

Robot::Robot(Point bottomLeftCorner, int width, int height) {
    double H_per_part = height / 19.0;
    double W_per_part = width / 26.0;

    // Y goes up
    // X goes right

    // Head
    // P4: W=8, H=19  P3: W=18, H=19
    // P1: W=8, H=14  P2: W=18, H=14
    _rectangles[0] = Rectangle::empty(
            {bottomLeftCorner.getX() + W_per_part * 8, bottomLeftCorner.getY() + H_per_part * 14},
            {bottomLeftCorner.getX() + W_per_part * 18, bottomLeftCorner.getY() + H_per_part * 14},
            {bottomLeftCorner.getX() + W_per_part * 18, bottomLeftCorner.getY() + H_per_part * 19},
            {bottomLeftCorner.getX() + W_per_part * 8, bottomLeftCorner.getY() + H_per_part * 19}
    );

    // Left eye
    // W=10, H=18
    _points[0] = {bottomLeftCorner.getX() + W_per_part * 10, bottomLeftCorner.getY() + H_per_part * 18};
    // Right eye
    // W=16, H=18
    _points[1] = {bottomLeftCorner.getX() + W_per_part * 16, bottomLeftCorner.getY() + H_per_part * 18};

    // Nose
    // P1: W=12, H=16
    // P2: W=14, H=16
    // P3: W=13, H=17
    _triangles[0] = Triangle::empty(
            {bottomLeftCorner.getX() + W_per_part * 12, bottomLeftCorner.getY() + H_per_part * 16},
            {bottomLeftCorner.getX() + W_per_part * 14, bottomLeftCorner.getY() + H_per_part * 16},
            {bottomLeftCorner.getX() + W_per_part * 13, bottomLeftCorner.getY() + H_per_part * 17}
    );

    // Mouth
    _lines[0] = Line(
            {_points[0].getX(), bottomLeftCorner.getY() + H_per_part * 15},
            {_points[1].getX(), bottomLeftCorner.getY() + H_per_part * 15}
    );

    // Neck
    _lines[1] = Line(
            {bottomLeftCorner.getX() + W_per_part * 13, bottomLeftCorner.getY() + H_per_part * 14},
            {bottomLeftCorner.getX() + W_per_part * 13, bottomLeftCorner.getY() + H_per_part * 13}
    );

    // Body
    // P4: W=6, H=13  P3: W=20, H=13
    // P1: W=6, H=3   P2: W=20, H=3
    _rectangles[1] = Rectangle::empty(
            {bottomLeftCorner.getX() + W_per_part * 6, bottomLeftCorner.getY() + H_per_part * 3},
            {bottomLeftCorner.getX() + W_per_part * 20, bottomLeftCorner.getY() + H_per_part * 3},
            {bottomLeftCorner.getX() + W_per_part * 20, bottomLeftCorner.getY() + H_per_part * 13},
            {bottomLeftCorner.getX() + W_per_part * 6, bottomLeftCorner.getY() + H_per_part * 13}
    );

    // Left arm
    _lines[2] = Line(
            {bottomLeftCorner.getX() + W_per_part * 0, bottomLeftCorner.getY() + H_per_part * 7},
            {bottomLeftCorner.getX() + W_per_part * 6, bottomLeftCorner.getY() + H_per_part * 12}
    );

    // Right arm
    _lines[3] = Line(
            {bottomLeftCorner.getX() + W_per_part * 26, bottomLeftCorner.getY() + H_per_part * 7},
            {bottomLeftCorner.getX() + W_per_part * 20, bottomLeftCorner.getY() + H_per_part * 12}
    );

    // Left leg
    _lines[4] = Line(
            {bottomLeftCorner.getX() + W_per_part * 10.5, bottomLeftCorner.getY() + H_per_part * 3},
            {bottomLeftCorner.getX() + W_per_part * 10.5, bottomLeftCorner.getY() + H_per_part * 0}
    );

    // Right leg
    _lines[5] = Line(
            {bottomLeftCorner.getX() + W_per_part * 15.5, bottomLeftCorner.getY() + H_per_part * 3},
            {bottomLeftCorner.getX() + W_per_part * 15.5, bottomLeftCorner.getY() + H_per_part * 0}
    );
}

Robot::Robot() = default;

void Robot::draw() {
    for (auto & _triangle : _triangles) {
        _triangle.draw();
    }

    for (auto & _point : _points) {
        _point.draw();
    }

    for (auto & _rectangle : _rectangles) {
        _rectangle.draw();
    }

    for (auto & _line : _lines) {
        _line.draw();
    }
}

#include <iostream>

void Robot::print() {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream& o, const Robot& a) {
    o << "Robot." << std::endl;

    return o;
}