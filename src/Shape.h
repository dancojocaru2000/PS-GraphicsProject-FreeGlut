#ifndef GRAPHICSPROJECT_SHAPE_H
#define GRAPHICSPROJECT_SHAPE_H

#include "EngineGlut.h"

class Shape {
protected:
    EngineGlut _engine;

public:
    virtual void draw() = 0;
};

#endif //GRAPHICSPROJECT_SHAPE_H
