#include <iostream>
#include "EngineGlut.h"

#include "Rectangle.h"
#include "Airplane.h"
#include "Robot.h"

int main() {
    initEngineGlut(0, nullptr);

    int width = 300;
    int height = 400;

    Airplane(
            {-width, -(height/2)},
            width,
            height
    ).draw();

    Rectangle::empty(
        {-width, -(height/2)},
        {0, -(height/2)},
        {0, (height/2)},
        {-width, (height/2)}).draw();

    Robot(
        {0, -(height/2)},
        width,
        height
    ).draw();

    Rectangle::empty(
        {0, -(height/2)},
        {width, -(height/2)},
        {width, (height/2)},
        {0, (height/2)}).draw();

    std::cin.ignore();

    return 0;
}