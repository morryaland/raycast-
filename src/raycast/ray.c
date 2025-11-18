#include "ray.h"
#include "../map.h"
#include <math.h>

int let_rays(ENTITY *e, RAYDATA *r, int rc)
{
  float fovrc = e->fov / rc;
  float ang = e->pov - e->fov / 2;
  for (int i = 0; i < rc; i++) {
    float a = ang;
    float x = e->x;
    float y = e->y;
    for (int j = 0; j < MAX_DEEP; j++) {
      int ret;
      ret = let_ray(&r[i].dist[j], &x, &y, a);
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

int let_ray(float *dist, float *x, float *y, float ang)
{
  int mat = 0;
  float x0 = *x;
  float y0 = *y;
  float sx = cosf(ang);
  float sy = sinf(ang);
  for (int i = 0; i < MAX_DIST; i++) {
    if (is_celfill(&mat, *x, *y))
      break;
    *x += sx;
    *y += sy;
  }
  if (mat)
    *dist = sqrtf((*x - x0)*(*x - x0) + ((int)*y - y0)*(*y - y0));
  else
    *dist = -1;
  return mat;
}
