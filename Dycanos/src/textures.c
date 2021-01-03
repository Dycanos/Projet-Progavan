#include "hub.h"
/**
 * \brief La fonction nettoie les textures
 * \param textures les textures
*/
void clean_textures(textures_t *textures){
  clean_texture(textures->Bg);
  clean_texture(textures->Cob);
  clean_texture(textures->Bed);
  clean_texture(textures->Steve);
  clean_texture(textures->Zombie);
}

/**
 * \brief La fonction initialise les textures à partir de ressources images
 * \param renderer la surface correspondant à l'écran de jeu
 * \param textures la structure qui contient les textures du jeu
 */

void init_textures(SDL_Renderer *renderer, textures_t *textures){
  textures->Bg = load_image("ressources/img/Bg_grass.bmp", renderer);
  textures->Cob = load_image("ressources/img/cobblestone.bmp",renderer);
  textures->Bed = load_image("ressources/img/bedrock.bmp",renderer);
  textures->Steve = load_image("ressources/img/Steve2.bmp",renderer);
  textures->Zombie = load_image("ressources/img/ZOMBIE.bmp",renderer);
}

/**
 * \brief La fonction applique la texture du fond sur le renderer lié à l'écran de jeu
 * \param renderer le renderer
 * \param textures les textures du jeu
 */
void apply_background(SDL_Renderer *renderer, textures_t *textures){
  apply_texture(textures->Bg, renderer, 0, 0);
}
/**
 * \brief La fonction applique la texture du fond sur le renderer lié à l'écran de jeu par rapport aux tableau.txt
 * \param renderer le renderer
 * \param textures les textures du jeu
 */
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

/**
 * \brief La fonction permet a une texture d'être visible
 * \param renderer le renderer
 * \param texture texture du sprite
 * \param sprite données d'une texture
 */

void apply_Steve(SDL_Renderer *renderer,SDL_Texture *texture,sprite_t *sprite){
	if(sprite->is_visible == 0) {
      SDL_Rect dst = {0, 0, 0, 0};//création de la zone comportant la texture
      SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);//ajutement à la taille de la texture
      dst.x = sprite->x; 
      dst.y = sprite->y;
      SDL_RenderCopy(renderer, texture, NULL, &dst);
  }
}


/**
 * \brief la fonction applique les textures des ennemis en fonction de leur niveau
 * \param renderer le renderer
 * \param texture les textures
 * \param world le monde
 */
void apply_enemies(SDL_Renderer *renderer,textures_t *textures,world_t *world){
    for(int i = 0; i< NB_ENEMIES ; i++)
      apply_Steve(renderer,textures->Zombie, &world->enemies[i]);
}