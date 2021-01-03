#include "hub.h"

/**
 * \brief La fonction rafraichit l'écran en fonction de l'état des données du monde
 * \param renderer la surface de l'écran de jeu
 * \param world les données du monde
 * \param textures les textures
 */
void refresh_graphics(SDL_Renderer *renderer, textures_t *textures,char** tab,world_t *world){
  clear_renderer(renderer);
  apply_background(renderer, textures);
  apply_sprite(renderer,textures,tab);
  apply_Steve(renderer,textures->Steve,&world->Steve);
  apply_enemies(renderer,textures,world);
  update_screen(renderer);
  
}
/**
 * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
 * \param event paramètre qui contient les événements
 * \param world les données du monde
 */
int handle_events(SDL_Event *event,world_t *world){
  while( SDL_PollEvent( event ) ) {
    //Si l'utilisateur a cliqué sur le X de la fenêtre                                                            
    if( event->type == SDL_QUIT ) {
      //On indique la fin du jeu
      exit(0);
    }
    if(event->type == SDL_KEYDOWN){
      if(event->key.keysym.sym == SDLK_ESCAPE){
        return(0);
      }
      if(event->key.keysym.sym == SDLK_d){
            world->Steve.x += 5;
      }
      if(event->key.keysym.sym == SDLK_q){
        world->Steve.x -= 5;
      }
      if(event->key.keysym.sym == SDLK_s){
        world->Steve.y += 5;
      }
      if(event->key.keysym.sym == SDLK_z){
        world->Steve.y -= 5;
      }
      if(event->key.keysym.sym == SDLK_c){
            world->Steve.x += 5;
            world->Steve.y += 5;
      }
      if(event->key.keysym.sym == SDLK_e){
            world->Steve.x += 5;
            world->Steve.y -= 5;
      }
      if(event->key.keysym.sym == SDLK_w){
            world->Steve.x -= 5;
            world->Steve.y += 5;
      }
      if(event->key.keysym.sym == SDLK_a){
            world->Steve.x -= 5;
            world->Steve.y -= 5;
      }
    }

  }
  return(1);
}

/**
 * \brief fonction qui initialise le jeu: initialisation de la partie graphique (SDL), chargement des textures, initialisation des données
 * \param window la fenêtre du jeu
 * \param renderer le renderer
 * \param textures les textures
 * \param world le monde
  * \param tab le tableau du .txt
 */
void init(SDL_Window **window, SDL_Renderer **renderer, textures_t *textures,char** tab,world_t *world){
  init_sdl(window, renderer,  W_WIDTH, W_HEIGHT);
  init_textures(*renderer, textures);
  init_data(world);
  refresh_graphics(*renderer, textures,tab,world);
}

/**
 * \brief La fonction met à jour les données en tenant compte de la physique du monde
 * \param world les données du monde
 */
void update_data(world_t *world){
  update_Zombie(world);
  handle_sprites_collision(world);
  bordure(&world->Steve);
  bordureMur(&world->Steve);
  for (int i = 0; i < NB_ENEMIES; ++i)
  {
    //bordure(&world->enemies[i]);
    bordureMur(&world->enemies[i]);
  }

} 

/**
 * \brief fonction qui fait avancer le jeu dans le temps, itération par itération, au moyen d'un boucle
 * \param renderer le renderer
 * \param event les évènements
 * \param textures les textures
 * \param world les données du monde
 * \param tab le tableau du .txt
 */
void boucle_jeu(SDL_Renderer *renderer, SDL_Event *event, textures_t *textures, world_t *world,char** tab){
  clock_t temps;
  srand(time(NULL));
  while(world->Steve.is_visible == 0){ //tant que le jeu n'est pas fini
    //gestion des évènements
    handle_events(event,world);
    // update pour collisions
    update_data(world);
    //rafraichissement de l'écran
    refresh_graphics(renderer,textures,tab,world);
    // pause de 10 ms pour controler la vitesse de rafraichissement
    pause(10);
  }
  temps=clock();
  printf("Vous avez tenu %f secondes !\n", ((double)temps/CLOCKS_PER_SEC)*10 );
}

int main() {
  SDL_Event event;
  textures_t textures;
  SDL_Renderer *renderer;
  SDL_Window *window;
  world_t world;
  char ** tableau = lire_fichier();
  afficher_tableau(tableau,T_HEIGHT,T_WIDTH);
  init(&window, &renderer, &textures,tableau,&world);
  boucle_jeu(renderer,&event,&textures,&world,tableau);
  clean_textures(&textures);
  clean_sdl(renderer, window);
  return(0);
}
