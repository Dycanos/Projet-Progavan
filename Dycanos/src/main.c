#include "hub.h"

int oui(SDL_Event *event)
{
    if(event->type == SDL_QUIT){
        exit(0);
        return 1;
    }
    return 0;
}
int handle_events(SDL_Event *event){
    while( SDL_PollEvent( event ) ) {
        
        //Si l'utilisateur a cliqué sur le X de la fenêtre
        if( event->type == SDL_QUIT ) {
            //On indique la fin du jeu
          exit(0);
        }
        if(event->type == SDL_KEYDOWN)
        {
        if(event->key.keysym.sym == SDLK_ESCAPE)
        {
            return 1;
        }
      }

    }
    return 0;
}

void refresh_graphics(SDL_Renderer *renderer){
    //on vide le renderer
    clear_renderer(renderer);
    update_screen(renderer);
} 


void init(SDL_Window **window, SDL_Renderer ** renderer){
    init_sdl(window,renderer,500,500);   
} 

void clean(SDL_Window *window, SDL_Renderer * renderer){
    clean_sdl(renderer,window);
}

void boucle_jeu(SDL_Renderer *renderer, SDL_Event *event){
  while(handle_events(event) == 0){ //tant que le jeu n'est pas fini
    //gestion des évènements
    handle_events(event);
    //rafraichissement de l'écran
    refresh_graphics(renderer);
    // pause de 10 ms pour controler la vitesse de rafraichissement
    pause(10);
  }
}
int main(int argc, char const *argv[])
{
       srand(time(NULL));
      SDL_Renderer *renderer;
      SDL_Window *window;
        SDL_Event event;
         //initialisation du jeu
     init(&window,&renderer);
     boucle_jeu(renderer,&event);
      //nettoyage final
      clean(window,renderer);    
     return 0;
}
