#include <iostream>
#include "EngineGlut.h"

#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Airplane.h"

int main() {
    initEngineGlut(0, nullptr);

    Airplane({-50, -100}, 100, 200).draw();

    std::cin.ignore();

    return 0;
}