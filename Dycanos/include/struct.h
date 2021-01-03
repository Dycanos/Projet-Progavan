#ifndef STRUCT
#define STRUCT

typedef struct textures_s{
  SDL_Texture* Bg; //Background
  SDL_Texture* Cob; //Pierre
  SDL_Texture* Bed; // Bedrock
  SDL_Texture* Steve; // Personnage
  SDL_Texture* Zombie; // Ennemies
} textures_t;

struct sprite_s{
	int x;
	int y;
	int h;
	int w;
	int v;
  int is_visible;
};
typedef struct sprite_s sprite_t;

struct world_s{

  sprite_t Steve; /*correspond au Steve*/
  sprite_t enemies[NB_ENEMIES]; /*correspond aux ennemies*/
  sprite_t missile; /*correspond aux missile*/
};
typedef struct world_s world_t;
#endif 
