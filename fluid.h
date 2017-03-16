#ifndef FLUID_H
#define FLUID_H

#include <iostream>
#include <stdlib>

#define SIZE_X 64
#define SIZE_Y 64
#define SIZE_Z 64

#define GRID_SIZE ((SIZE_X)*(SIZE_Y)*(SIZE_Z)))
#define GRID_SIZE_X ((SIZE_X+1)*(SIZE_Y)*(SIZE_Z)))
#define GRID_SIZE_Y ((SIZE_X)*(SIZE_Y+1)*(SIZE_Z)))
#define GRID_SIZE_Z ((SIZE_X)*(SIZE_Y)*(SIZE_Z+1)))

class Fluid {
    float* u; // x velocity
    float* v; // y velocity
    float* w; // z velocity
    float* p; // pressure

    void advect();
    void addForce();
    void project();

public:
    Fluid();
    ~Fluid();
    void update();
};

#endif