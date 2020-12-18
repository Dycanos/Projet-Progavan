#include "hub.h"

void refresh_graphics(SDL_Renderer *renderer, textures_t *textures,char** tab){
  clear_renderer(renderer);
  apply_background(renderer, textures);
  apply_sprite(renderer,textures,tab);
  update_screen(renderer);
  
}

int handle_events(SDL_Event *event){
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
    }
  }
  return(1);
}

void init(SDL_Window **window, SDL_Renderer **renderer, textures_t *textures,char** tab){
  init_sdl(window, renderer,  W_WIDTH, W_HEIGHT);
  init_textures(*renderer, textures);
  refresh_graphics(*renderer, textures,tab);
}


int main() {
  SDL_Event event;
  textures_t textures;
  SDL_Renderer *renderer;
  SDL_Window *window;
  char ** tableau = lire_fichier();
  afficher_tableau(tableau,T_HEIGHT,T_WIDTH);
  init(&window, &renderer, &textures,tableau);
  while(handle_events(&event)){
    //rien
    // mais genre vraiment rien
    // du tout du tout
    // même pas un twix
    pause(2);
  }
  clean_textures(&textures);
  clean_sdl(renderer, window);
  return(0);
}
