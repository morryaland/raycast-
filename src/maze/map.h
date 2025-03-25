#ifndef __MAP_H__
#define __MAP_H__

#define TRAIL_NUM  1
#define TRAIL_CHAR '@'

typedef struct _map {
  unsigned int width;
  unsigned int height;
  unsigned int seed;
  char *data;
} MAP;

extern MAP *stdmap;

MAP*
create_map(unsigned int seed, unsigned int width, unsigned int height);

void
free_map(MAP **map);

void
set_mtrail(MAP *map, int x, int y);

#define set_trail(        x, y) \
       set_mtrail(stdmap, x, y)

int
ismtrail(MAP *map, int x, int y);
#define istrail(        x, y) \
       ismtrail(stdmap, x, y)

void 
print_map(MAP *map);

#endif
