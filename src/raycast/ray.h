#ifndef __RAY_H__
#define __RAY_H__

#include "../entity.h"
#include <stdlib.h>

#define MAX_DIST 100

#define MAX_DEEP 10

typedef struct _raydata {
  float dist[MAX_DEEP];
  int mat[MAX_DEEP];
  float x[MAX_DEEP];
  float y[MAX_DEEP];
} RAYDATA;

int let_rays(ENTITY *e, RAYDATA *r, int rc);

int let_ray(float *dist, float *x, float *y, float a, float b);

#endif
