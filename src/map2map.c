#include "map.h"
#include "map2map.h"
#include "maze/map.h"
#include "maze/maze.h"
#include <math.h>

int map2map(CHUNK *chunk, int x, int y)
{
  for (int i = 0; i < chunk->height; i++) {
    for (int j = 0; j < chunk->width; j++) {
      if (!chunk->data[i * chunk->width + j]) {
        if (fillcel(rand_r(&chunk->seed) % 3 + 1, x + j, y + i) < 0) { //TODO mat
          return -1;
        }
      }
    }
  }
  return 0;
}

int genchunk(unsigned int seed, int x, int y)
{
  for (int i = 0; i < 4; i++) {
    CHUNK *ch = create_map(seed, CHUNK_SIZE, CHUNK_SIZE);
    if (!ch)
      return -1;
    nextstep(ch, 3, 3);
    print_map(ch);
    if (map2map(ch, x, y) < 0)
      return -1;
    free_map(&ch);
    if (ch)
      return -1;
    x += (int)roundf(cosf(i * M_PI_2) * 10) * CHUNK_SIZE;
    y += (int)roundf(sinf(i * M_PI_2) * 10) * CHUNK_SIZE;
  }
  return 0;
}
