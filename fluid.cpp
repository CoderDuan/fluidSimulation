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
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            for (int k = 0; k < GRID_SIZE; k++) {
                Vector3 pos(i, j, k);
                // advect pressure field
                Vector3 vel = getVel(i, j, k);

                Vector3 oldPos = pos - vel * DT / DH;
            }
        }
    }
    return;
}

void Fluid::addForce() {
    return;
}

void Fluid::project() {
    return;
}

#endif