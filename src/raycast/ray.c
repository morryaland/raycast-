#include "ray.h"
#include "../map.h"
#include <math.h>

int let_rays(ENTITY *e, RAYDATA *r, int rc)
{
  float fovrc = e->fov / rc;
  float ang = e->pov - e->fov / 2;
  for (int i = 0; i < rc; i++) {
    r[i].x[0] = e->x;
    r[i].y[0] = e->y;
    for (int j = 0; j < MAX_DEEP; j++) {
      int ret;
      ret = let_ray(&r[i].dist[j], &r[i].x[j], &r[i].y[j], ang, e->pov - ang);
      r[i].mat[j] = ret;
      if (r[i].dist < 0 || ret > 0) {
        break;
      }
      if (!ret) {
        //TODO mirror
      } else {
        //TODO transparent
      }
    }
    ang += fovrc; //TODO
  }
} //TODO ret

int let_ray(float *dist, float *x, float *y, float a, float b)
{
  int mat = 0;
  char side = 0;
  int mx = (int)*x;
  int my = (int)*y;
  const float dx = cosf(a);
  const float dy = sinf(a);
  const float sx = dx ? fabsf(1 / dx) : 1e30;
  const float sy = dy ? fabsf(1 / dy) : 1e30;
  const int stx = dx > 0 ? 1 : -1;
  const int sty = dy > 0 ? 1 : -1;
  float dix = (dx > 0 ? mx + 1 - *x : *x - mx) * sx;
  float diy = (dy > 0 ? my + 1 - *y : *y - my) * sy;

  for (int i = 0; i < MAX_DIST; i++) {
    if (dix < diy) {
      mx += stx;
      dix += sx;
      side = 0;
    } else {
      my += sty;
      diy += sy;
      side = 1;
    }
    if (is_celfill(&mat, mx, my)) {
      *dist = (side ? diy - sy : dix - sx);
      *x += dx * *dist;
      *y += dy * *dist;
      *dist *= cosf(b);
      return mat;
    }
  }
  *dist = -1;
  return mat;
}
