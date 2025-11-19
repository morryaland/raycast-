#include "window.h"
#include "raycast/ray.h"
#include <stdio.h>

SDL_Window *win;
SDL_Renderer *rend;

int drawrays(RAYDATA *r, int rc)
{
  int w = 0, h = 0;
  SDL_GetWindowSize(win, &w, &h);
  int wl = (float)w / rc;
  for (int i = 0; i < rc; i++) {
    for (int j = 0; j < MAX_DEEP; j++) {
      if (r[i].dist[j] <= 0)
        break;
      int hr = h / r[i].dist[j];
      int yr = (float)h / 2 - (float)hr / 2;
      switch (r[i].mat[j]) {
        case 1:
          SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
          break;
        case 2:
          SDL_SetRenderDrawColor(rend, 0, 255, 0, 255);
          break;
        case 3:
          SDL_SetRenderDrawColor(rend, 0, 0, 255, 255);
          break;
      }
      drawline(i * wl, yr, wl, hr);
    }
  }
}

int drawline(int x, int y, int w, int h)
{
  SDL_RenderFillRect(rend, &(SDL_FRect){.x = x, .y = y, .w = w, .h = h});
}
