#include "map.h"
#include <stdio.h>
#include <stdlib.h>

MAP *stdmap;

MAP*
create_map(unsigned int seed, unsigned int width, unsigned int height)
{
  MAP *m = malloc(sizeof(MAP));
  m->height = height;
  m->width = width;
  m->seed = seed;
  m->data = calloc(1, width * height);
  return m;
}

void
free_map(MAP **map)
{
  free((**map).data);
  free(*map);
  *map = NULL;
}

void
set_mtrail(MAP *map, int x, int y)
{
  map->data[y * map->width + x] = TRAIL_NUM;
}

int
ismtrail(MAP *map, int x, int y)
{
  return map->data[y * map->width + x] == TRAIL_NUM;
}

#include <unistd.h>

void
print_map(MAP *map)
{
  for (int i = 0; i < map->height; i++) {
    for (int j = 0; j < map->width; j++) {
      if (map->data[i * map->width + j] == TRAIL_NUM) {
        putchar(TRAIL_CHAR);
      } else {
        putchar(' ');
      }
    }
    putchar('\n');
  }
}
