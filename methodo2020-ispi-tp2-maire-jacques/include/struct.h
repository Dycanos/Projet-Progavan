#ifndef STRUCT
#define STRUCT

#include "valeur.h"
/**
 * \brief Représentation pour stocker les textures nécessaires à l'affichage graphique
*/
struct sprite_s{
  int pv;/*nombre de coups encaissables*/
  int x;/*coordonées du sprite en x*/
  int y;/*coordonées du sprite en y*/
  int h;/* sa hauteur*/
  int w;/* sa largeur*/
  int v;/* sa vitesse verticale*/
  int d;/* les dégats qu'il inflige(seulement pour le vaisseau, les ennemis à 0)*/
  int is_visible;
};

/**
 * \brief Type qui correspond aux textures necessaires du jeu
*/
typedef struct sprite_s sprite_t;


/**
 * \brief Prend le stockage des textures
*/

struct textures_s{
  SDL_Texture* background[4]; /*!< Texture liée à l'image du fond l'écran. */
  SDL_Texture* spaceship[2];
  SDL_Texture* ennemi[5];
  SDL_Texture* missile[2];
  SDL_Texture* boost[2]; /*!< Textures des power-up*/
  TTF_Font *font;
  /* A COMPLETER */
};


/**
 * \brief Type qui correspond aux textures du jeu
*/

typedef struct textures_s textures_t;


/**
 * \brief Représentation du monde du jeu
*/

struct world_s{
    /*
      A COMPLETER
     */
  int score;
  int niveau; /*!< correspond au niveau de difficultée actuel du jeu*/
  sprite_t enemies[NB_ENEMIES];
  sprite_t missile;
  sprite_t boost[2];
  sprite_t vaisseau; /*correspond au vaisseau*/
  int gameover; /*!< Champ indiquant si l'on est  la fin du jeu */

};

/**
 * \brief Type qui correspond aux données du monde
 */

typedef struct world_s world_t;
#endif
