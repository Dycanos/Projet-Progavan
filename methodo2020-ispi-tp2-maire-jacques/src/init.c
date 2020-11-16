#include "hub.h"
/**
 * \file menus.c
 * \brief fichier qui gère les initialisations de tous les sprites
 * \author Maire L. & Jacques L.
 * \version 0.0
 * \date 29 mai 2020
 */
/**
 * \brief La fonction permet a une texture d'être visible
 * \param sprite données d'une texture
 */

void set_visible(sprite_t *sprite){
    sprite->is_visible =0;
}

/**
 * \brief La fonction permet a une texture d'être invisible
 * \param sprite données d'une texture
 */

void set_invisible(sprite_t *sprite){
    sprite->is_visible =1;
}

/**
 * \brief La fonction permet d'initialiser un sprite
 * \param sprite données d'une texture
 * \param x valeur horizontale
 * \param y valeur verticale
 * \param w largeur
 * \param h hauteur
 * \param v vitesse
 */

void init_sprite(sprite_t *sprite,int pv,int x, int y, int w, int h, int v, int d)
{
    sprite->pv=pv;
    sprite->x=x;
    sprite->y=y;
    sprite->w=w;
    sprite->h=h;
    sprite->v=v;
    sprite->d=d;
    sprite->is_visible=0;
}
/**
 * \brief La fonction permet d'initialiser un boost
 * \param world les données du monde
 */
void init_boosts(world_t *world){
  init_sprite(&world->boost[0], 1, (rand() % (SCREEN_WIDTH - SHIP_SIZE)), (- rand() % ((SCREEN_HEIGHT * 5) - (2 * SCREEN_HEIGHT))), BOOSTER_SIZE, BOOSTER_SIZE, ENNEMY_SPEED, 1);
  init_sprite(&world->boost[1], 1, (rand() % (SCREEN_WIDTH - SHIP_SIZE)), (- rand() % ((SCREEN_HEIGHT * 7) - (3 * SCREEN_HEIGHT))), BOOSTER_SIZE, BOOSTER_SIZE, ENNEMY_SPEED, 1);
}

/**
 * \brief La fonction permet d'initialiser les ennemies
 * \param world les données du monde
 */

void init_enemies(world_t *world){
  int x;
  int y;
  for (int i = 0; i < NB_ENEMIES; i++){
    x = rand() % (SCREEN_WIDTH - SHIP_SIZE);//position x aléatoire
    y = -SHIP_SIZE/2 - i*VERTICAL_DIST;//distance y égale entre les vaisseaux 
    init_sprite(&world->enemies[i],1,x,y, SHIP_SIZE, SHIP_SIZE, ENNEMY_SPEED, 1);
  }
}

/**
 * \brief La fonction permet d'initialiser les données du monde du jeu
 * \param world les données du monde
 */
void init_data(world_t *world){

    //on n'est pas à la fin du jeu 
    world->gameover = 0;
    world->score = 0;//aucun ennemi tué
    world->niveau = 0;//ennemis à 1pv
    init_sprite(&world->vaisseau,1, ((SCREEN_WIDTH / 2)-(SHIP_SIZE / 2)), (SCREEN_HEIGHT-SHIP_SIZE), SHIP_SIZE, SHIP_SIZE, 0, 1);
    init_sprite(&world->missile,1, world->vaisseau.x+SHIP_SIZE/2-MISSILE_SIZE/2, SCREEN_HEIGHT-SHIP_SIZE-MISSILE_SIZE, MISSILE_SIZE, MISSILE_SIZE, MISSILE_SPEED, 1);
    set_invisible(&world->missile);//missile invisible tant que non tiré
    init_boosts(world);
    init_enemies(world);
}
