#include "map.h"
#include "json.h"
#include <stdint.h>
#include <Judy.h>

/** compress two int to one unsigned long */
#define KEY(x, y) ((*(uint64_t*)&x << 32) | *(uint32_t*)&y)

static Pvoid_t current_map;

int is_celfill(int *mat, int x, int y)
{
  PWord_t PValue = NULL;
  JLG(PValue, current_map, KEY(x, y));
  if (!PValue) {
    return 0;
  }
  *mat = *(int64_t*)PValue;
  return 1;
}

int fillcel(int mat, int x, int y)
{
  PWord_t PValue = NULL;
  JLI(PValue, current_map, KEY(x, y));
  *PValue = *(Word_t*)&mat;
} // TODO ret

int load_map()
{
  Word_t rc;
  JLFA(rc, current_map); //TODO ret?
  // TODO json load
}
