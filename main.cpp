#include <iostream>
#include "EngineGlut.h"

#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Rectangle.h"

void testPoint() {
    Point p1;
    p1.draw();

    Point p2 { 8, 16 };
    p2.draw();
}

void testLine() {
    Line l1;
    l1.draw();

    Line l2 { {5, 10}, {15, 20} };
    l2.draw();
}

void testTriangle() {
    Triangle t1;
    t1.draw();

    Triangle t2 = Triangle::empty( {75, 75}, {75, 50}, {50, 75} );
    t2.draw();

    Triangle t3 = Triangle::filled( {-75, -75}, {-75, -50}, {-50, -75} );
    t3.draw();
}

void testRectangle() {
    Rectangle r1;
    r1.draw();

    Rectangle r2 = Rectangle::empty( {100, 100}, {-100, 100}, {-100, -100}, {100, -100} );
    r2.draw();

    Rectangle r21 = Rectangle::filled( {100, 100}, {100+25, 100}, {100+25, 100+25}, {100, 100+25} );
    r21.draw();

    Rectangle r22 = Rectangle::filled( {100, -100}, {100+25, -100}, {100+25, -100-25}, {100, -100-25} );
    r22.draw();

    Rectangle r23 = Rectangle::filled( {-100, -100}, {-100-25, -100}, {-100-25, -100-25}, {-100, -100-25} );
    r23.draw();

    Rectangle r24 = Rectangle::filled( {-100, 100}, {-100-25, 100}, {-100-25, 100+25}, {-100, 100+25} );
    r24.draw();
}

int main(int argc, char** argv) {
    initEngineGlut(argc, argv);

    testPoint();
    testLine();
    testTriangle();
    testRectangle();

    std::cin.ignore();

    return 0;
}