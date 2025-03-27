#include "maze/map.h"
#include "maze/maze.h"
#include "map.h"
#include <math.h>

int map2map(CHUNK *chunk, int x, int y)
{
  for (int i = 0; i < chunk->height; i++) {
    for (int j = 0; j < chunk->width; j++) {
      if (!chunk->data[i * chunk->width + j]) {
        fillcel(1, x + j, y + i); //TODO mat
      }
    }
  }
}

int genchunk(MAP_INFO *mi, int x, int y)
{
  for (int i = 0; i < 4; i++) {
    CHUNK *ch = create_map(mi->seed, CHUNK_SIZE, CHUNK_SIZE);
    nextstep(ch, 3, 3);
    print_map(ch);
    map2map(ch, x, y);
    free_map(&ch);
    x += (int)roundf(cosf(i * M_PI_2) * 10) * CHUNK_SIZE;
    y += (int)roundf(sinf(i * M_PI_2) * 10) * CHUNK_SIZE;
  }
}
