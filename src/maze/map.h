#ifndef __MAZE_MAP_H__
#define __MAZE_MAP_H__

#define TRAIL_CHAR '@'

typedef struct _map {
  unsigned int width;
  unsigned int height;
  unsigned int seed;
  char *data;
} CHUNK;

extern CHUNK *stdmap;

CHUNK*
create_map(unsigned int seed, unsigned int width, unsigned int height);

void
free_map(CHUNK **map);

void
set_mtrail(CHUNK *map, int x, int y);

int
ismtrail(CHUNK *map, int x, int y);

void 
print_map(CHUNK *map);

#endif
