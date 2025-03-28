#ifndef __MAP2MAP_H__
#define __MAP2MAP_H__

#include "map.h"
#include "maze/map.h"

#define CHUNK_SIZE 31

int map2map(CHUNK *chunk, int x, int y);

int genchunk(unsigned int seed, int x, int y);

#endif
