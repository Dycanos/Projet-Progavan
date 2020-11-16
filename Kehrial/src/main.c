#include "hub.h"

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

void init(SDL_Window **window, SDL_Renderer ** renderer){
  init_sdl(window, renderer, 100, 100);
}


int main() {
  SDL_Event event;
  SDL_Renderer *renderer;
  SDL_Window *window;
  init(&window, &renderer);
  while(handle_events(&event)){
    //rien
    // mais genre vraiment rien
    // du tout du tout
    // même pas un twix
  }
  clean_sdl(renderer, window);
  return(0);
}
