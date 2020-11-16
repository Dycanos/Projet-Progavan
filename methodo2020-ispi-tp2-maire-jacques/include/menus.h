#ifndef MENUS
#define MENUS

#include "hub.h"
int options(int, int);
void commande_menu(SDL_Window *, SDL_Renderer *, textures_t *, SDL_Event *, world_t *);
void endgame_menu(SDL_Window *, SDL_Renderer *, textures_t *, SDL_Event *, world_t *);
void game_menu(SDL_Window *, SDL_Renderer *, textures_t *, SDL_Event *, world_t *);

#endif
