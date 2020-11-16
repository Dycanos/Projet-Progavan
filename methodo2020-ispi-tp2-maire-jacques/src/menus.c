#include "hub.h"
/**
 * \file menus.c
 * \brief fichier qui gère chacun des menus proposé dans le jeu et leurs interactions
 * \author Maire L. & Jacques L.
 * \version 6.66
 * \date 29 mai 2020
 */

/**
 * \brief la fonction qui détermine le type de réponse en fonction des coordonnée données (d'un clic de souris)
 * \param x coordonnée horizontale
 * \param y coordonnée verticale
 */
int options(int x, int y) {
  if (x >= 80 && x <= 225){
    if (y >= 135 && y <= 200)
      return(1);
    if (y >= 235 && y <= 275)
      return(2);
    if (y >= 310 && y <= 355)
      return(3);
  }
  return(0);
}

/**
 * \brief la fonction qui gère le comportement du menu explicatif des "commandes"
 * \param window la fenètre de jeu
 * \param renderer le renderer
 * \param textures les textures
 * \param event les events
 * \param world les données du monde
 */

void commande_menu(SDL_Window *window, SDL_Renderer *renderer, textures_t *textures, SDL_Event *event, world_t *world) {
  int x, y, k;
  clear_renderer(renderer);
  apply_background(renderer, textures, 3);
  update_screen(renderer);
  k = 0;
  while(k == 0){
    while(SDL_PollEvent(event)){
      if (event->type == SDL_QUIT){
        clean(window, renderer, textures, world);
        exit(0);
      }
      if(event->type == SDL_KEYDOWN){
        if(event->key.keysym.sym == SDLK_ESCAPE){
          clean(window, renderer, textures, world);
          exit(0);
        }
      }
      if (event->type == SDL_MOUSEBUTTONDOWN){
        SDL_GetMouseState(&x, &y); //récupération des coordonnées x et y lors du clic
        if(x >= 45 && x <= 255 && y >= 340 && y <= 415){ //comparaison à la zone definie des coordonnées
          k = 1;
          game_menu(window, renderer, textures, event, world);
        }
      }
    }
  }
}

void endgame_menu(SDL_Window *window, SDL_Renderer *renderer, textures_t *textures, SDL_Event *event, world_t *world){
  int x, y, k;
  clear_renderer(renderer);
  apply_background(renderer, textures, 2);
  char string[20] = {'\0'};
  apply_text(renderer, 80, 80, 145, 40, scoring(string, world), textures->font); //affichage du scoe après gameover
  update_screen(renderer);
  k = 0;
  while (k == 0){
    while (SDL_PollEvent(event)){
      if (event->type == SDL_QUIT){
        clean(window, renderer, textures, world);
        exit(0);
      }
      if(event->type == SDL_KEYDOWN){
        if(event->key.keysym.sym == SDLK_ESCAPE){
          clean(window, renderer, textures, world);
          exit(0);
        }
      }
      if (event->type == SDL_MOUSEBUTTONDOWN){
        SDL_GetMouseState(&x, &y);
        k = options(x, y);
      }
    }
  }
  if (k == 1){ //bouton pour rejouer
    clean(window, renderer, textures, world);
    init(&window, &renderer, textures, world);
    boucle_jeu(renderer, event, textures, world);
    endgame_menu(window, renderer, textures, event, world);
  }
  if (k == 2){//bouton pour menu principal
    clean(window, renderer, textures, world);
    init(&window, &renderer, textures, world);
    game_menu(window, renderer, textures, event, world);
  }
  // si k == 3 fin de la boucle et du programme par défaut
}

void game_menu(SDL_Window *window, SDL_Renderer *renderer, textures_t *textures, SDL_Event *event, world_t *world){
  int x, y, k;
  clear_renderer(renderer);
  apply_background(renderer, textures, 1);
  update_screen(renderer);
  k = 0;
  while (k == 0){
    while (SDL_PollEvent(event)){
      if (event->type == SDL_QUIT){
        clean(window, renderer, textures, world);
        exit(0);
      }
      if(event->type == SDL_KEYDOWN){
        if(event->key.keysym.sym == SDLK_ESCAPE){
          clean(window, renderer, textures, world);
          exit(0);
        }
      }
      if (event->type == SDL_MOUSEBUTTONDOWN){
        SDL_GetMouseState(&x, &y);
        k = options(x, y);//définition de la zone des options
      }
    }
  }
  if(k == 1){//bouton jouer
    boucle_jeu(renderer, event, textures, world);
    endgame_menu(window, renderer, textures, event, world);
  }
  if(k == 2){//bouton commandes
    commande_menu(window, renderer, textures, event, world);
  }
}

