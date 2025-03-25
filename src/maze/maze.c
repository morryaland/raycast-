#include "maze.h"
#include <stdio.h>
#include <stdlib.h>

void
nextstep(int x, int y)
{
  int order[4] = {0, 1, 2, 3};
  for (int i = 3; i > 0; i--) {
    int j = rand_r(&stdmap->seed) % (i + 1);
    int temp = order[i];
    order[i] = order[j];
    order[j] = temp;
  }
  for (int i = 0; i < 4; i++) {
    switch (order[i]) {
      case 0:
        if (x - 2 > 0 && !istrail(x - 2, y)) {
          set_trail(x - 1, y);
          set_trail(x - 2, y);
          nextstep(x - 2, y);
        }
        break;
      case 1:
        if (x + 2 < stdmap->width && !istrail(x + 2, y)) {
          set_trail(x + 1, y);
          set_trail(x + 2, y);
          nextstep(x + 2, y);
        }
        break;
      case 2:
        if (y - 2 > 0 && !istrail(x, y - 2)) {
          set_trail(x, y - 1);
          set_trail(x, y - 2);
          nextstep(x, y - 2);
        }
        break;
      case 3:
        if (y + 2 < stdmap->height && !istrail(x, y + 2)) {
          set_trail(x, y + 1);
          set_trail(x, y + 2);
          nextstep(x, y + 2);
        }
        break;
    }
  }
}
