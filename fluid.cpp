#ifndef FLUID_CPP
#define FLUID_CPP

#include "fluid.h"

Fluid::Fluid() {
    u = (float*)malloc(GRID_SIZE_X*sizeof(float));
    v = (float*)malloc(GRID_SIZE_Y*sizeof(float));
    w = (float*)malloc(GRID_SIZE_Z*sizeof(float));
    p = (float*)malloc(GRID_SIZE*sizeof(float));

    memset(u, 0, GRID_SIZE_X*sizeof(float));
    memset(v, 0, GRID_SIZE_Y*sizeof(float));
    memset(w, 0, GRID_SIZE_Z*sizeof(float));
    memset(p, 0, GRID_SIZE*sizeof(float));
}

Fluid::~Fluid() {
    free(u);
    free(v);
    free(w);
    free(p);
}

void Fluid::update() {
    return;
}

void Fluid::advect() {
    return;
}

void Fluid::addForce() {
    return;
}

void Fluid::project() {
    return;
}

#endif