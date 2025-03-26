#include "map.h"
#include <stdint.h>
#include <Judy.h>

/** compress two int to one unsigned long */
#define KEY(x, y) ((*(uint64_t*)&x << 32) | *(uint32_t*)&y)

static Pvoid_t c_map;

int clear_map()
{
  Word_t Rc;
  JLFA(Rc, c_map);
}

int is_celfill(int *mat, int x, int y)
{
  PWord_t PValue = NULL;
  JLG(PValue, c_map, KEY(x, y));
  if (!PValue) {
    return 0;
  }
  *mat = *(int64_t*)PValue;
  return 1;
}

int fillcel(int mat, int x, int y)
{
  PWord_t PValue = NULL;
  JLI(PValue, c_map, KEY(x, y));
  *PValue = *(Word_t*)&mat;
} // TODO ret
