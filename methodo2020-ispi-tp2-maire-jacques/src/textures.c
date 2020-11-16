#include "hub.h"
/**
 * \file main.c
 * \brief fichier comportant les fonctions qui gèrent la création et l'utilisation des textures
 * \author Maire L. & Jacques L.
 * \version 12
 * \date 29 mai 2020
 */

/**
 * \brief La fonction nettoie les textures
 * \param textures les textures
*/

void clean_textures(textures_t *textures){
  for (int i = 0; i < 4; i++) {
    clean_texture(textures->background[i]);
  }
  clean_texture(textures->spaceship[0]);
  clean_texture(textures->spaceship[1]);
  for (int j = 0; j < 5; j++) {
    clean_texture(textures->ennemi[j]);
  }
  clean_texture(textures->missile[0]);
  clean_texture(textures->missile[1]);
  clean_texture(textures->boost[0]);
  clean_texture(textures->boost[1]);
  clean_font(textures->font);
}

/**
 * \brief La fonction initialise les textures à partir de ressources images
 * \param renderer la surface correspondant à l'écran de jeu
 * \param textures la structure qui contient les textures du jeu
 */

void init_textures(SDL_Renderer *renderer, textures_t *textures){
    textures->background[0] = load_image( "ressources/space-background.bmp",renderer);
    textures->background[1] = load_image( "ressources/space-background-menu.bmp",renderer);
    textures->background[2] = load_image( "ressources/space-background-fin.bmp",renderer);
    textures->background[3] = load_image( "ressources/commandes.bmp",renderer);
    textures->spaceship[0] = load_image( "ressources/spaceship.bmp",renderer);
    textures->spaceship[1] = load_image( "ressources/spaceship2.bmp",renderer);
    textures->ennemi[0] = load_image( "ressources/ennemy.bmp",renderer);
    textures->ennemi[1] = load_image( "ressources/ennemy2.bmp",renderer);
    textures->ennemi[2] = load_image( "ressources/ennemy3.bmp",renderer);
    textures->ennemi[3] = load_image( "ressources/ennemy4.bmp",renderer);
    textures->ennemi[4] = load_image( "ressources/ennemy5.bmp",renderer);
    textures->missile[0] = load_image( "ressources/missile.bmp",renderer);
    textures->missile[1] = load_image( "ressources/missile1.bmp",renderer);
    textures->boost[0] = load_image( "ressources/missile_tir.bmp",renderer);
    textures->boost[1] = load_image( "ressources/missile_pv.bmp",renderer);
    textures->font = load_font("ressources/arial.ttf",14);
}

/**
 * \brief La fonction applique la texture du fond sur le renderer lié à l'écran de jeu
 * \param renderer le renderer
 * \param textures les textures du jeu
 * \param i le numéro du fond que l'on utilisera
 */

void apply_background(SDL_Renderer *renderer, textures_t *textures, int i){
    if(textures->background[i] != NULL){
      apply_texture(textures->background[i], renderer, 0, 0);
    }
}

/**
 * \brief la fonction applique les textures des power-up sur le renderer
 * \param renderer le renderer
 * \param textures les textures
 * \param world les données du monde
 */
void apply_boost(SDL_Renderer *renderer, textures_t *textures, world_t *world){
  apply_sprite(renderer, textures->boost[0], &world->boost[0]);
  apply_sprite(renderer, textures->boost[1], &world->boost[1]);
}

/**
 * \brief la fonction applique les textures des ennemis en fonction de leur niveau
 * \param renderer le renderer
 * \param texture les textures
 * \param world le monde
 */

void apply_enemies(SDL_Renderer *renderer,textures_t *texture,world_t *world){
    for(int i = 0; i< NB_ENEMIES ; i++)
      apply_sprite(renderer, texture->ennemi[world->niveau], &world->enemies[i]);
}


/**
 * \brief La fonction permet a une texture d'être visible
 * \param renderer le renderer
 * \param texture texture du sprite
 * \param sprite données d'une texture
 */

void apply_sprite(SDL_Renderer *renderer,SDL_Texture *texture,sprite_t *sprite){
    if(sprite->is_visible == 0) {
      SDL_Rect dst = {0, 0, 0, 0};//création de la zone comportant la texture
      SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);//ajutement à la taille de la texture
      dst.x = sprite->x; 
      dst.y = sprite->y;
      SDL_RenderCopy(renderer, texture, NULL, &dst);
    }
}
