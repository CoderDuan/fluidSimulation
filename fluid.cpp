#ifndef FLUID_CPP
#define FLUID_CPP

#include "fluid.h"

Fluid::Fluid() {
    u = (float*)malloc(GRID_SIZE_X*sizeof(float));
    v = (float*)malloc(GRID_SIZE_Y*sizeof(float));
    w = (float*)malloc(GRID_SIZE_Z*sizeof(float));
    p = (float*)malloc(GRID_SIZE*sizeof(float));
    velCurr = (Vector3*)malloc(GRID_SIZE*sizeof(Vector3));
    pNext = (float*)malloc(GRID_SIZE*sizeof(float));

    memset(u, 0, GRID_SIZE_X*sizeof(float));
    memset(v, 0, GRID_SIZE_Y*sizeof(float));
    memset(w, 0, GRID_SIZE_Z*sizeof(float));
    memset(p, 0, GRID_SIZE*sizeof(float));
    memset(pNext, 0, GRID_SIZE*sizeof(float));
}

Fluid::~Fluid() {
    if (u) free(u);
    if (v) free(v);
    if (w) free(w);
    if (p) free(p);
    if (velCurr) free(velCurr);
    if (pNext) free(pNext);
}

void Fluid::update() {
    return;
}

void Fluid::advectPressure() {
    // calculate velTmp
    for (int i = 0; i < SIZE_X; i++) {
        for (int j = 0; j < SIZE_Y; j++) {
            for (int k = 0; k < SIZE_Z; k++) {
                Vector3 pos(i, j, k);
                setVelNext(i, j, k, getVel(i, j, k));
            }
        }
    }

    for (int i = 0; i < SIZE_X; i++) {
        for (int j = 0; j < SIZE_Y; j++) {
            for (int k = 0; k < SIZE_Z; k++) {
                Vector3 pos(i, j, k);

                // advect pressure field
                Vector3 vel = getVelNext(i, j, k);
                Vector3 oldPos = pos - vel * DT / DH;

                if (validPos(oldPos)) {
                    setpNext(i, j, k, getp(oldPos));
                }
            }
        }
    }
    return;
}

void Fluid::advectVelocity() {
    for (int i = 1; i < SIZE_X; i++) {
        for (int j = 0; j < SIZE_Y; j++) {
            for (int k = 0; k < SIZE_Z; k++) {
                Vector3 pos(i, j, k);

                Vector3 vel = getVel(i, j, k);
            }
        }
    }
}

void Fluid::addForce() {
    return;
}

void Fluid::project() {
    return;
}

#endif