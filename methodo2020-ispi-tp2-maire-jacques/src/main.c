#include "hub.h"
/**
 * \file main.c
 * \brief fichier main du programme de spacebattle
 * \author Maire L. & Jacques L.
 * \version 42.0
 * \date 29 mai 2020
 */

/**
 * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
 * \param event paramètre qui contient les événements
 * \param world les données du monde
 */

void handle_events(SDL_Event *event,world_t *world){
    while( SDL_PollEvent( event ) ) {
        
        //Si l'utilisateur a cliqué sur le X de la fenêtre
        if( event->type == SDL_QUIT ) {
            //On indique la fin du jeu
          exit(0);
        }
       
        //si une touche est appuyée
        if(event->type == SDL_KEYDOWN){
          //si la touche appuyée est 'D'
          if(event->key.keysym.sym == SDLK_d){
            printf("La touche D est appuyée\n");
          }
          if(event->key.keysym.sym == SDLK_RIGHT){
            world->vaisseau.x += 5;
          }
          if(event->key.keysym.sym == SDLK_LEFT){
            world->vaisseau.x -= 5;
          }
          //touche "espace"
          if(event->key.keysym.sym == SDLK_SPACE)
            {
              if(world->vaisseau.is_visible == 0)
                {//placement du missile au niveau du vaisseau et reset de ses valeurs
                  world->missile.x = world->vaisseau.x + SHIP_SIZE/2 - MISSILE_SIZE/2;
                  world->missile.y = SCREEN_HEIGHT-SHIP_SIZE-MISSILE_SIZE;
                  world->missile.pv = 1;
                  world->missile.d = world->vaisseau.d;
                  set_visible(&world->missile);
                  world->missile.v = MISSILE_SPEED;
                }
            }
          if(event->key.keysym.sym == SDLK_ESCAPE){
            exit(0);
          }
        }
    }
}

/**
 * \brief La fonction rafraichit l'écran en fonction de l'état des données du monde
 * \param renderer la surface de l'écran de jeu
 * \param world les données du monde
 * \param textures les textures
 */

void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //on vide le renderer
    clear_renderer(renderer);
    //application des textures dans le renderer
    apply_background(renderer, textures, 0);
    //texture du vaisseau différente en fonction de ses pv
    if (world->vaisseau.pv == 2){
      apply_sprite(renderer,textures->spaceship[1],&world->vaisseau);
    } else {
      apply_sprite(renderer,textures->spaceship[0],&world->vaisseau);
    }
    apply_boost(renderer, textures, world);
    //texture missile différente en fonction des dégats
    if (world->vaisseau.d == 2){
      apply_sprite(renderer, textures->missile[1],&world->missile);
    } else {
      apply_sprite(renderer, textures->missile[0],&world->missile);
    }
    apply_enemies(renderer,textures,world);
    char string[40] = {'\0'}; //création du char* contenant le score
    //affichage du score
    apply_text(renderer, 0, 0, 100, 30, scoring(string, world), textures->font);
    update_screen(renderer);
}

/**
* \brief fonction qui nettoie le jeu: nettoyage de la partie graphique (SDL), nettoyage des textures, nettoyage des données
* \param window la fenêtre du jeu
* \param renderer le renderer
* \param textures les textures
* \param world le monde
*/

void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world){
    clean_data(world);
    clean_textures(textures);
    clean_sdl(renderer,window);
}

/**
 * \brief fonction qui initialise le jeu: initialisation de la partie graphique (SDL), chargement des textures, initialisation des données
 * \param window la fenêtre du jeu
 * \param renderer le renderer
 * \param textures les textures
 * \param world le monde
 */

void init(SDL_Window **window, SDL_Renderer ** renderer, textures_t *textures, world_t * world){
    init_sdl(window,renderer,SCREEN_WIDTH, SCREEN_HEIGHT);
    init_ttf();
    init_data(world);
    init_textures(*renderer,textures);
    
}

/**
 * \brief fonction qui fait avancer le jeu dans le temps, itération par itération, au moyen d'un boucle
 * \param renderer le renderer
 * \param event les évènements
 * \param textures les textures
 * \param world les données du monde
 */
void boucle_jeu(SDL_Renderer *renderer, SDL_Event *event, textures_t *textures, world_t *world){
  while(!is_game_over(world)){ //tant que le jeu n'est pas fini
    //gestion des évènements
    handle_events(event,world);
    //mise à jour des données liée à la physique du monde
    update_data(world);
    //rafraichissement de l'écran
    refresh_graphics(renderer,world,textures);
    // pause de 10 ms pour controler la vitesse de rafraichissement
    pause(10);
  }
}

int main( int argc, char* args[] )
{
    srand(time(NULL));
    SDL_Event event;
    world_t world;
    textures_t textures;
    SDL_Renderer *renderer;
    SDL_Window *window;
    //initialisation du jeu
    init(&window,&renderer,&textures,&world);
    //menu_principal
    game_menu(window, renderer, &textures, &event, &world);
    //nettoyage final
    clean(window,renderer,&textures,&world);    
    return 0;
}
