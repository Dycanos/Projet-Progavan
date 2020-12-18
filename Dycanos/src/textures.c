#include "hub.h"

void clean_textures(textures_t *textures){
  clean_texture(textures->Bg);
}

void init_textures(SDL_Renderer *renderer, textures_t *textures){
  textures->Bg = load_image("ressources/img/Bg_grass.bmp", renderer);
  textures->Cob = load_image("ressources/img/cobblestone.bmp",renderer);
  textures->Bed = load_image("ressources/img/bedrock.bmp",renderer);
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
			if(tab[i][j] == 49)
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