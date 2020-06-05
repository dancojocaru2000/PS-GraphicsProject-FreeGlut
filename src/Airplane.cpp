#include "Airplane.h"

Airplane::Airplane(Point bottomLeftCorner, int width, int height) {
    int H_per_part = height / 8;
    int W_per_part = width / 6;

    // Y goes up
    // X goes right

    // P1: W=3, H=8
    // P2: W=2, H=6
    // P3: W=2, H=6
    _triangles[0] = Triangle::empty(
            {bottomLeftCorner.getX() + W_per_part * 3, bottomLeftCorner.getY() + H_per_part * 8},
            {bottomLeftCorner.getX() + W_per_part * 2, bottomLeftCorner.getY() + H_per_part * 6},
            {bottomLeftCorner.getX() + W_per_part * 4, bottomLeftCorner.getY() + H_per_part * 6}
    );

    // P1: W=0, H=6
    // P2: W=0, H=4
    // P3: W=6, H=4
    _triangles[1] = Triangle::empty(
            {bottomLeftCorner.getX() + W_per_part * 0, bottomLeftCorner.getY() + H_per_part * 6},
            {bottomLeftCorner.getX() + W_per_part * 0, bottomLeftCorner.getY() + H_per_part * 4},
            {bottomLeftCorner.getX() + W_per_part * 6, bottomLeftCorner.getY() + H_per_part * 4}
    );

    // P1: W=0, H=6
    // P2: W=6, H=6
    // P3: W=6, H=4
    _triangles[2] = Triangle::empty(
            {bottomLeftCorner.getX() + W_per_part * 0, bottomLeftCorner.getY() + H_per_part * 6},
            {bottomLeftCorner.getX() + W_per_part * 6, bottomLeftCorner.getY() + H_per_part * 6 },
            {bottomLeftCorner.getX() + W_per_part * 6, bottomLeftCorner.getY() + H_per_part * 4}
    );

    // W=1, H=5
    _points[0] = Point(
            {bottomLeftCorner.getX() + W_per_part * 1, bottomLeftCorner.getY() + H_per_part * 5}
    );

    // W=5, H=5
    _points[1] = Point(
            {bottomLeftCorner.getX() + W_per_part * 5, bottomLeftCorner.getY() + H_per_part * 5}
    );

    // P4: W=2, H=4       P3: W=4, H=4
    // P1: W=2, H=1       P2: W=4, H=1
    _rectangles[0] = Rectangle::empty(
            {bottomLeftCorner.getX() + W_per_part * 2, bottomLeftCorner.getY() + H_per_part * 1},
            {bottomLeftCorner.getX() + W_per_part * 4, bottomLeftCorner.getY() + H_per_part * 1},
            {bottomLeftCorner.getX() + W_per_part * 4, bottomLeftCorner.getY() + H_per_part * 4},
            {bottomLeftCorner.getX() + W_per_part * 2, bottomLeftCorner.getY() + H_per_part * 4}
    );

    // P1: W=1, H=1
    // P2: W=1, H=0
    // P3: W=5, H=0
    _triangles[3] = Triangle::empty(
            {bottomLeftCorner.getX() + W_per_part * 1, bottomLeftCorner.getY() + H_per_part * 1},
            {bottomLeftCorner.getX() + W_per_part * 1, bottomLeftCorner.getY() + H_per_part * 0},
            {bottomLeftCorner.getX() + W_per_part * 5, bottomLeftCorner.getY() + H_per_part * 0}
    );

    // P1: W=1, H=1
    // P2: W=5, H=1
    // P3: W=5, H=0
    _triangles[4] = Triangle::empty(
            {bottomLeftCorner.getX() + W_per_part * 1, bottomLeftCorner.getY() + H_per_part * 1},
            {bottomLeftCorner.getX() + W_per_part * 5, bottomLeftCorner.getY() + H_per_part * 1},
            {bottomLeftCorner.getX() + W_per_part * 5, bottomLeftCorner.getY() + H_per_part * 0}
    );
}

Airplane::Airplane() = default;

void Airplane::draw() {
    for (auto & _triangle : _triangles) {
        _triangle.draw();
    }

    for (auto & _point : _points) {
        _point.draw();
    }

    for (auto & _rectangle : _rectangles) {
        _rectangle.draw();
    }
}