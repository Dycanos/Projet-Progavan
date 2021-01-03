#include "hub.h"

void clean_textures(textures_t *textures){
  clean_texture(textures->Bg);
}

void init_textures(SDL_Renderer *renderer, textures_t *textures){
  textures->Bg = load_image("ressources/img/Bg_grass.bmp", renderer);
  textures->Cob = load_image("ressources/img/cobblestone.bmp",renderer);
  textures->Bed = load_image("ressources/img/bedrock.bmp",renderer);
  textures->Steve = load_image("ressources/img/Steve2.bmp",renderer);
  textures->Zombie = load_image("ressources/img/ZOMBIE.bmp",renderer);
}

void apply_background(SDL_Renderer *renderer, textures_t *textures){
  apply_texture(textures->Bg, renderer, 0, 0);
}

void apply_sprite(SDL_Renderer *renderer, textures_t *textures,char** tab)
{
	int x = 0;
	int y = 0;
	for (int i = 0; i < T_WIDTH; i++)
	{
		for (int j = 0; j < T_HEIGHT; j++)
		{
			if(tab[i][j] == 51)
			{
				apply_texture(textures->Cob, renderer, x,y);
			}
			if(tab[i][j] == 50)
			{
				apply_texture(textures->Bed, renderer, x,y);
			}
			x += 50;
		}
		x = 0;
		y += 50;
	}
}

void apply_Steve(SDL_Renderer *renderer,SDL_Texture *texture,sprite_t *sprite){
	if(sprite->is_visible == 0) {
      SDL_Rect dst = {0, 0, 0, 0};//création de la zone comportant la texture
      SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);//ajutement à la taille de la texture
      dst.x = sprite->x; 
      dst.y = sprite->y;
      SDL_RenderCopy(renderer, texture, NULL, &dst);
  }
}

void apply_enemies(SDL_Renderer *renderer,textures_t *textures,world_t *world){
    for(int i = 0; i< NB_ENEMIES ; i++)
      apply_Steve(renderer,textures->Zombie, &world->enemies[i]);
}