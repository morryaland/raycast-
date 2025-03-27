#include "map2map.h"
#include "raycast/ray.h"
#include <stdio.h>


int main(int argc, char *argv[])
{
  genchunk(&(MAP_INFO){.seed = 1}, 0, 0);
  RAYDATA *r = malloc(sizeof(RAYDATA) * 10);
  let_rays((ENTITY){.pov = 180, .fov = 90, .x = 3, .y = 3}, r, 10);
  for (int i = 0; i < 10; i++) {
    printf("%f ", r[i].dist[0]);
  }
  putchar('\n');
  for (int i = 0; i < 10; i++) {
    printf("%d ", r[i].mat[0]);
  }
  return 0;
}
