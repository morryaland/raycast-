#ifndef __MAP_H__
#define __MAP_H__

#include <Judy.h>

int clear_map();

int is_celfill(int *mat, int x, int y);

int fillcel(int mat, int x, int y);

int freecel(int x, int y);

#endif
