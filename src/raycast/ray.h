#ifndef __RAY_H__
#define __RAY_H__

#include "../entity.h"
#include <stdlib.h>

#define MAX_DIST 100

#define MAX_DEEP 10

typedef struct _raydata {
  float dist;
  int mat;
} RAYDATA;

int let_rays(ENTITY e, RAYDATA *r, int rc);

int let_ray_x(float *dist, float *x, float *y, float ang);
int let_ray_y(float *dist, float *x, float *y, float ang);

#endif
