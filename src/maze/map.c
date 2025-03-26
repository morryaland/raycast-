#include "map.h"
#include <stdio.h>
#include <stdlib.h>

CHUNK*
create_map(unsigned int seed, unsigned int width, unsigned int height)
{
  CHUNK *m = malloc(sizeof(CHUNK));
  m->height = height;
  m->width = width;
  m->seed = seed;
  m->data = calloc(1, width * height);
  return m;
}

void
free_map(CHUNK **map)
{
  free((**map).data);
  free(*map);
  *map = NULL;
}

void
set_mtrail(CHUNK *map, int x, int y)
{
  map->data[y * map->width + x] = 1;
}

int
ismtrail(CHUNK *map, int x, int y)
{
  return map->data[y * map->width + x];
}

void
print_map(CHUNK *map)
{
  for (int i = 0; i < map->height; i++) {
    for (int j = 0; j < map->width; j++) {
      if (map->data[i * map->width + j]) {
        putchar(TRAIL_CHAR);
      } else {
        putchar(' ');
      }
    }
    putchar('\n');
  }
}
