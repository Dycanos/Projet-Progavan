#ifndef HUB
#define HUB

// regroupement de ts les headers du projet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "sdl2-light.h"
#include "sdl2-ttf-light.h"
#include "struct.h"
#include "valeur.h"
#include "init.h"
#include "donnee.h"
#include "textures.h"
#include "collision.h"
#include "menus.h"

//fonctions du main
void handle_events(SDL_Event *, world_t *);
void refresh_graphics(SDL_Renderer *, world_t *, textures_t *);
void clean(SDL_Window *, SDL_Renderer *, textures_t *, world_t *);
void init(SDL_Window **, SDL_Renderer **, textures_t *, world_t *);
void boucle_jeu(SDL_Renderer *, SDL_Event *, textures_t *, world_t *);
#endif
