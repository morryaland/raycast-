#ifndef __MAP_H__
#define __MAP_H__

#include <Judy.h>

typedef struct _map_info {
  unsigned int seed;
  char title[16];
} MAP_INFO;

#define CHUNK_SIZE 31

int clear_map();

int is_celfill(int *mat, int x, int y);

int fillcel(int mat, int x, int y);

int freecel(int x, int y);

#endif
