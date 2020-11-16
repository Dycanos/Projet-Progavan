#include "hub.h"

/**
 * \file donnes.c
 * \brief fichier qui gère toutes les données du jeu
 * \author Maire L. & Jacques L.
 * \version 713705
 * \date 29 mai 2020
 */ 


/**
 * \brief La fonction permet d'effacer la textures d'un ennemi si ce dernier tombe à 0HP
 * \param world les données du monde
 */
void recup(world_t *world)
{
  for(int i = 0; i< NB_ENEMIES; i++) {//visibilitée des ennemis
    if(world->enemies[i].is_visible == 0 && world->enemies[i].pv <= 0) {
      world->enemies[i].is_visible = 1;
      world->enemies[i].v = 0;
    }
  }
  if(world->missile.is_visible == 0 && world->missile.pv <= 0) {//du missile
    world->missile.v = 0;
    world->missile.is_visible = 1;
  }
  if(world->vaisseau.is_visible == 0 && world->vaisseau.pv <= 0) {//du vaisseau
    world->vaisseau.is_visible = 1;
  }
  for (int j = 0; j < 2; j++)//des power-up
    if(world->boost[j].is_visible == 0 && world->boost[j].pv <= 0){
      world->boost[j].v = 0;
      world->boost[j].is_visible = 1;
    }
}  

/**
 * \brief La fonction permet a une texture d'être visible
 * \param string une chaine de caractère
 * \param world les données du monde
 * \return la chaine de caractère
 */

char* scoring(char *string, world_t *world) {
  sprintf(string, "Score: %i", world->score);//enregistrement du score dans un char * grâce à sprintf
  return(string);
}

/**
 * \brief La fonction nettoie les données du monde
 * \param world les données du monde
 */

void clean_data(world_t *world){
    /* utile uniquement si vous avez fait de l'allocation dynamique (malloc); la fonction ici doit permettre de libérer la mémoire (free) */    
}

/**
 * \brief La fonction indique si le jeu est fini en fonction des données du monde
 * \param world les données du monde
 * \return 1 si le jeu est fini, 0 sinon
 */

int is_game_over(world_t *world){
    return world->gameover;
}

/**
 * \brief La fonction met à jour les elements en tenant compte de leur vitesse
 * \param world les données du monde
 */

void update_enemies(world_t *world){
  for (int i = 0; i < NB_ENEMIES; i++) {
    world->enemies[i].y += world->enemies[i].v;//ajout de la vitesse à la position de l'élément
  }
  world->boost[0].y += world->boost[0].v;
  world->boost[1].y += world->boost[1].v;
}

/**
 * \brief La fonction permet de voir si tous les ennemies sont invisible
 * \param world les données du monde
 * \return 0 si il reste un ou plusieurs ennemi visible et 1 si ils sont tous invisible
 */

int end_enemies(world_t *world) {
    for(int i = 0; i< NB_ENEMIES; i++) {//si un au moins des ennemis est encore visible
      if(world->enemies[i].is_visible == 0) {
            return (0);
        }
    }
    return(1);
}

/**
 * \brief La fonction detecte le moment où la partie est fini
 * \param world les données du monde
 */
void compute_game(world_t *world)
{
  if(world->vaisseau.is_visible == 1) { //si le vaisseau est détruit
    world->gameover = 1;
  }
  else if(world->score == NB_ENEMIES) {// si tous les ennemis sont tués
    world->gameover = 1;
  }
  else if(end_enemies(world) == 1) {//s'il n'y a plus d'ennemis à tuer
    world->gameover = 1;
  }
  else {//si la partie n'est pas finie
    world->gameover = 0;
  }
}

/**
 * \brief La fonction met à jour les données en tenant compte de la physique du monde
 * \param world les données du monde
 */
void update_data(world_t *world){
  int b;
  update_enemies(world);
  b = handle_sprites_collision(world,0);//collision vaisseau/ennemis
  b = handle_sprites_collision(world,1);//collision missile/ennemis
  recup(world);
  if(b == 1 && world->score%5 == 0){
    world->niveau += 1;
    for (int i = 0; i < NB_ENEMIES; i++){
        world->enemies[i].pv += 1;
      }
  }
  get_boost(world, 0);//collision vaisseau/power-up de dégats
  get_boost(world, 1);//collision vaisseau/power-up de vie
  bordures(&world->vaisseau);
  ennemibord(world);
  missilebord(world);
  if(world->missile.is_visible == 0){
    world->missile.y -= world->missile.v;
  }
  compute_game(world);//règles de fin du jeu
}
