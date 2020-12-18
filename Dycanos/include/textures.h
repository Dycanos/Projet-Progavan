#ifndef TEXTURES
#define TEXTURES

void clean_textures(textures_t*);
void init_textures(SDL_Renderer*, textures_t*);
void apply_background(SDL_Renderer*, textures_t*);
void apply_sprite(SDL_Renderer *renderer, textures_t *textures,char** tab);
#endif
