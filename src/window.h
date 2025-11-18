#ifndef __WINDOW_h__
#define __WINDOW_h__

#include "raycast/ray.h"
#include <SDL3/SDL.h>

extern SDL_Window *win;
extern SDL_Renderer *rend;

int drawrays(RAYDATA *r, int rc);
int drawdots(RAYDATA *r, int rc);

int drawline(int x, int y, int w, int h);

#endif
