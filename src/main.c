#include "map2map.h"
#include "raycast/ray.h"
#include "window.h"
#include <math.h>

int main(int argc, char *argv[])
{
  genchunk(1, 0, 0);
  RAYDATA *r = malloc(sizeof(RAYDATA) * 200);
  ENTITY pl = {.pov = M_PI, .fov = M_PI_4, .x = 3, .y = 3};
  SDL_CreateWindowAndRenderer("test", 800, 600, 0, &win, &rend);
  SDL_Event event;
  for (;;) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_EVENT_QUIT:
          return 0;
        case SDL_EVENT_KEY_DOWN:
          switch (event.key.key) {
            case SDLK_UP:
              pl.x += cosf(pl.pov) * 0.05f;
              pl.y += sinf(pl.pov) * 0.05f;
              break;
            case SDLK_DOWN:
              pl.x -= cosf(pl.pov) * 0.05f;
              pl.y -= sinf(pl.pov) * 0.05f;
              break;
            case SDLK_LEFT:
              pl.pov -= 0.1;
              break;
            case SDLK_RIGHT:
              pl.pov += 0.1;
              break;
          }
          break;
      }
    }
    let_rays(&pl, r, 200);
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
    SDL_RenderClear(rend);
    drawrays(r, 200);
    drawdots(r, 200);
    SDL_RenderPresent(rend);
  }
  return 0;
}
