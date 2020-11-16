#include "hub.h"
/**
 * \file main.c
 * \brief fichier dont les fonction gèrent les collisions dans le jeu
 * \author Maire L. Jacques L.
 * \version 6.9
 * \date 29 mai 2020
 */

/**
 * \brief la fonction gère les collisions et l'application des power-up
 * \param world les données du monde
 * \param t le choix du booster
 */

void get_boost(world_t *world, int t) {
  sprite_t *sp1, *sp2;
  sp1 = &world->vaisseau;
  sp2 = &world->boost[t];//power-up différent en fonction de t
  if(sp1->is_visible == 0 && sp2->is_visible == 0 && sprites_collide(sp1, sp2) == 1) {
    if(t == 1) {
      sp1->pv = 2;
      sp2->pv -= 1;
    }
    if(t == 0) {
      sp1->d += 1;
      sp2->pv -= 1;
    }
  }
}

/**
 * \brief La fonction gère que le vaisseau reste dans les bordures du jeu
 * \param sprite données d'une texture
 */

void bordures(sprite_t *sprite)
{
  if(sprite->x < 0)//dépasse à droite
        sprite->x = 0;
  if(sprite->x + SHIP_SIZE > SCREEN_WIDTH)//dépasse à gauche
        sprite->x = SCREEN_WIDTH - SHIP_SIZE;
}

/**
 * \brief la fonction efface le missile s'il sort de la fenêtre de jeu
 * \param world les données du monde
 */

void missilebord(world_t *world) {
  if (world->missile.y <= 0){//dépasse en haut
    world->missile.is_visible = 1;
  }
}

/**
 * \brief La fonction qui efface les ennemis s'il sortent en bas de l'écran
 * \param world les données du monde
 */

void ennemibord(world_t *world)
{
  for (int i = 0; i < NB_ENEMIES; i++){
    if (world->enemies[i].is_visible == 0)
      if (world->enemies[i].y > SCREEN_HEIGHT) {//dépasse en bas
        world->enemies[i].is_visible = 1;
      }
  }
}

/**
 * \brief La fonction gère la collison de deux sprite
 * \param sp1 données d'un élément
 * \param sp2 données d'un élément
 * \return 1 si il y a une collison et 0 si il n'y en a pas
 */

int sprites_collide(sprite_t *sp1, sprite_t *sp2)
{
  //application des formules de collision
  int x1 = sp1->x + (sp1->w / 2);
  int x2 = sp2->x + (sp2->w / 2);
  int y1 = sp1->y + (sp1->h / 2);
  int y2 = sp2->y + (sp2->h / 2);
  double d = sqrt((pow((x1 - x2), 2) + pow((y1 - y2), 2)));
  double s = (sp1->w + sp2->w) / 2;
  if (d <= s){
      return(1);
  } else {
    return(0);
  }
}

/**
 * \brief La fonction gère la disparition des sprites lors d'une collison
 * \param sp1 données d'une texture
 * \param sp2 données d'une texture
 * \return 1 si un ennemi a été éliminé et 0 sinon
 */

int handle_sprites_collision(world_t *world,int t)
{
  sprite_t *sp1, *sp2;
  if( t == 0) {
    sp1 = &world->vaisseau;
  } else {
    sp1 = &world->missile;
  }
  for (int i = 0; i< NB_ENEMIES; i++) {
    sp2 = &world->enemies[i];
    if (sp1->is_visible == 0 && sp2->is_visible == 0 && sprites_collide(sp1, sp2) == 1){
        if(sp2->pv >= 1) {
            sp1->pv -= 1;
            sp2->pv -= sp1->d;
            if(t == 0)
              sp2->pv = 0;//mort de l'élément si non-ennemi ET collision
            if(t == 1 && sp2->pv <= 0) {//score +1 si ennemi tué
                world->score += 1;
                return 1;
            }
        }
    }
  }
  return 0;
}
