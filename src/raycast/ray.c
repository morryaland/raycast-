#include "ray.h"
#include "../window.h"
#include <math.h>

int let_rays(ENTITY e, RAYDATA *r, int rc)
{
  float fovrc = e.fov / rc;
  float ang = e.pov - e.fov / 2;
  for (int i = 0; i < rc; i++) {
    float a = ang;
    float x = e.x;
    float y = e.y;
    for (int j = 0; j < MAX_DEEP; j++) {
      int ret;
      if (abs((int)(sin(ang) * 1000))  > 707) {
        ret = let_ray_x(&r[i].dist, &x, &y, a);
      }
      else {
        ret = let_ray_y(&r[i].dist, &x, &y, a);
      }
      r[i].mat = ret;
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
}

static int let_ray(int *d, float *x, float *y, float ax, float ay)
{
  for (; *d < MAX_DIST; (*d)++) {
    *x += ax;
    *y += ay;
    //TODO if ()
  }
  *d = -1;
  return 0;
}

int let_ray_x(float *dist, float *x, float *y, float ang)
{
  float ax = cosf(ang);
  int ay = sinf(ang) > 0 ? 1 : -1;
  int diy = 0;
  int ret = let_ray(&diy, x, y, ax, ay);
  *dist = diy / (sinf(ang) * ay);
  return ret;
}

int let_ray_y(float *dist, float *x, float *y, float ang)
{
  int ax = cosf(ang) > 0 ? 1 : -1;
  float ay = sinf(ang);
  int dix = 0;
  int ret = let_ray(&dix, x, y, ax, ay);
  *dist = dix / (cosf(ang) * ax);
  return ret;
}
