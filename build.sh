#!/usr/bin/env bash
g++ -std=c++11 -lGL -lGLU -lglut -lpthread EngineGlut.cpp GlutData.cpp GlutDrawing.cpp main.cpp Point.cpp Line.cpp Triangle.cpp Rectangle.cpp -D=LINUX_PLATFORM -o program