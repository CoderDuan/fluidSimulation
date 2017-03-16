#ifndef FLUID_H
#define FLUID_H

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "vector3.h"

#define SIZE_X 64
#define SIZE_Y 64
#define SIZE_Z 64

#define GRID_SIZE ((SIZE_X)*(SIZE_Y)*(SIZE_Z))
#define GRID_SIZE_X ((SIZE_X+1)*(SIZE_Y)*(SIZE_Z))
#define GRID_SIZE_Y ((SIZE_X)*(SIZE_Y+1)*(SIZE_Z))
#define GRID_SIZE_Z ((SIZE_X)*(SIZE_Y)*(SIZE_Z+1))

#define DT 0.01f // time step
#define DH 1.0f  // width per grid

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

    inline float getu(int x, int y, int z) {
        return u[x*SIZE_Y*SIZE_Z + y*SIZE_Z + z];
    }

    inline float getv(int x, int y, int z) {
        return v[x*(SIZE_Y+1)*SIZE_Z + y*SIZE_Z + z];
    }

    inline float getw(int x, int y, int z) {
        return w[x*SIZE_Y*(SIZE_Z+1) + y*SIZE_Z + z];
    }

    inline Vector3 getVel(int x, int y, int z) {
        return Vector3((getu(x, y, z) + getu(x+1, y, z))/2,
                    (getv(x, y, z) + getv(x, y+1, z))/2,
                    (getw(x, y, z) + getw(x, y, z+1))/2);
    }

    inline float getp(int x, int y, int z) {
        return p[x*SIZE_Y*SIZE_Z + y*SIZE_Z + z];
    }

    inline bool validPos(float i, float j, float k) {
        return (i >= 0.5f && i <= SIZE_X+0.5f
                && j >= 0.5f && j <= SIZE_Y+0.5f
                && k >= 0.5f && k <= SIZE_Z+0.5f);
    }

    inline bool validPos(Vector3 pos) {
        return validPos(pos.x, pos.y, pos.z);
    }
};

#endif