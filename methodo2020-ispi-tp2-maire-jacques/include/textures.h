#ifndef TEXTURES
#define TEXTURES

void clean_textures(textures_t *);
void init_textures(SDL_Renderer *, textures_t *);
void apply_background(SDL_Renderer *, textures_t *, int);
void apply_boost(SDL_Renderer *, textures_t *, world_t *);
void apply_enemies(SDL_Renderer *, textures_t *, world_t *);
void apply_sprite(SDL_Renderer *, SDL_Texture *, sprite_t *);
#endif
