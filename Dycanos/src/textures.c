#include "hub.h"

void clean_textures(textures_t *textures){
  clean_texture(textures->Bg);
}

void init_textures(SDL_Renderer *renderer, textures_t *textures){
  textures->Bg = load_image("ressources/img/Bg_grass.bmp", renderer);
}

void apply_background(SDL_Renderer *renderer, textures_t *textures){
  apply_texture(textures->Bg, renderer, 0, 0);
}
