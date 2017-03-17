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

    Vector3* velCurr;
    Vector3* velNext;
    float* pNext; // pressure

    void advectPressure();
    void advectVelocity();
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
        return w[x*SIZE_Y*(SIZE_Z+1) + y*(SIZE_Z+1) + z];
    }

    inline Vector3 getVel(int x, int y, int z) {
        return Vector3((getu(x, y, z) + getu(x+1, y, z))/2,
                    (getv(x, y, z) + getv(x, y+1, z))/2,
                    (getw(x, y, z) + getw(x, y, z+1))/2);
    }

    inline Vector3 getVelCurr(int x, int y, int z) {
        return velCurr[x*SIZE_Y*SIZE_Z + y*SIZE_Z + z];
    }

    inline Vector3 getVelCurr(Vector3 pos) {
        int i = (int)pos.x;
        int j = (int)pos.y;
        int k = (int)pos.z;

        float alpha = pos.x - i;
        float beta  = pos.y - j;
        float gamma = pos.z - k;

        return (alpha    * beta     * gamma     * getVelCurr(i,   j,   k)
             + (1-alpha) * beta     * gamma     * getVelCurr(i+1, j,   k)
             + alpha     * (1-beta) * gamma     * getVelCurr(i,   j+1, k)
             + (1-alpha) * (1-beta) * gamma     * getVelCurr(i+1, j+1, k)
             + alpha     * beta     * (1-gamma) * getVelCurr(i,   j,   k+1)
             + (1-alpha) * beta     * (1-gamma) * getVelCurr(i+1, j,   k+1)
             + alpha     * (1-beta) * (1-gamma) * getVelCurr(i,   j+1, k+1)
             + (1-alpha) * (1-beta) * (1-gamma) * getVelCurr(i+1, j+1, k+1));
    }

    inline void setVelCurr(int x, int y, int z, Vector3 val) {
        velCurr[x*SIZE_Y*SIZE_Z + y*SIZE_Z + z] = val;
    }

    inline Vector3 getVelNext(int x, int y, int z) {
        return velNext[x*SIZE_Y*SIZE_Z + y*SIZE_Z + z];
    }

    inline void setVelNext(int x, int y, int z, Vector3 val) {
        velNext[x*SIZE_Y*SIZE_Z + y*SIZE_Z + z] = val;
    }

    inline float getp(int x, int y, int z) {
        return p[x*SIZE_Y*SIZE_Z + y*SIZE_Z + z];
    }

    inline void setpNext(int x, int y, int z, float val) {
        pNext[x*SIZE_Y*SIZE_Z + y*SIZE_Z + z] = val;
    }

    inline float getp(Vector3 pos) {
        int i = (int)pos.x;
        int j = (int)pos.y;
        int k = (int)pos.z;

        float alpha = pos.x - i;
        float beta  = pos.y - j;
        float gamma = pos.z - k;

        return (alpha    * beta     * gamma     * getp(i,   j,   k)
             + (1-alpha) * beta     * gamma     * getp(i+1, j,   k)
             + alpha     * (1-beta) * gamma     * getp(i,   j+1, k)
             + (1-alpha) * (1-beta) * gamma     * getp(i+1, j+1, k)
             + alpha     * beta     * (1-gamma) * getp(i,   j,   k+1)
             + (1-alpha) * beta     * (1-gamma) * getp(i+1, j,   k+1)
             + alpha     * (1-beta) * (1-gamma) * getp(i,   j+1, k+1)
             + (1-alpha) * (1-beta) * (1-gamma) * getp(i+1, j+1, k+1));
    }

    inline bool validPos(float i, float j, float k) {
        return (i >= 0.0f && i < SIZE_X
                && j >= 0.0f && j < SIZE_Y
                && k >= 0.0f && k < SIZE_Z);
    }

    inline bool validPos(Vector3 pos) {
        return validPos(pos.x, pos.y, pos.z);
    }
};

#endif