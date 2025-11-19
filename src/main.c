#include "map2map.h"
#include "raycast/ray.h"
#include "window.h"
#include <math.h>

int main(int argc, char *argv[])
{
  Uint64 nowf;
  Uint64 lastf = 0;
  genchunk(1, 0, 0);
  RAYDATA *r = malloc(sizeof(RAYDATA) * 300);
  ENTITY pl = {.pov = M_PI, .fov = M_PI_2, .x = 3, .y = 3};
  SDL_CreateWindowAndRenderer("test", 800, 600, 0, &win, &rend);
  SDL_Event event;
  for (;;) {
    nowf = SDL_GetTicks();
    Uint64 deltaf = nowf - lastf;
    lastf = nowf;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_EVENT_QUIT:
          return 0;
      }
    }
    const bool *keys = SDL_GetKeyboardState(NULL);
    if (keys[SDL_SCANCODE_UP]) {
        pl.x += cosf(pl.pov) * 0.02f;
        pl.y += sinf(pl.pov) * 0.02f;
    }
    if (keys[SDL_SCANCODE_DOWN]) {
        pl.x -= cosf(pl.pov) * 0.02f;
        pl.y -= sinf(pl.pov) * 0.02f;
    }
    if (keys[SDL_SCANCODE_LEFT]) {
        pl.pov -= 0.03;
    }
    if (keys[SDL_SCANCODE_RIGHT]) {
        pl.pov += 0.03;
    }
    let_rays(&pl, r, 300);
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
    SDL_RenderClear(rend);
    drawrays(r, 300);
    SDL_RenderPresent(rend);
    SDL_Delay(SDL_max(1000/60.0f - deltaf, 0));
  }
  return 0;
}
