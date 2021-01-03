#include "hub.h"
/**
 * \brief La fonction permet d'initialiser un sprite
 * \param sprite données d'une texture
 * \param x valeur horizontale
 * \param y valeur verticale
 * \param w largeur
 * \param h hauteur
 * \param v vitesse
 */
void init_sprite(sprite_t *sprite,int x, int y, int w, int h, int v)
{
    sprite->x=x;
    sprite->y=y;
    sprite->w=w;
    sprite->h=h;
    sprite->v=v;
    sprite->is_visible=0;
}


/**
 * \brief La fonction permet d'initialiser les ennemies
 * \param world les données du monde
 */
void init_Zombie(world_t *world)
{
	int x;
 	int y;
  	for (int i = 0; i < NB_ENEMIES; i++)
  	{
  		if (i<25 || (i >75 && i<125))
  		{
  			x = 600 + (int)((float)rand() * (775-600+1)/ (RAND_MAX-1));//position x aléatoire
   		y = -S_WIDTH/2 - i*VERTICAL_DIST;//distance y égale entre les vaisseaux 
 	    init_sprite(&world->enemies[i],x,y, S_WIDTH, S_HEIGHT, 1);
  		}
 	    else if (i>75 ||(i>126 && i<175))
 		 {
 	 	x = -100-i*HORIZONTAL_DIST;//position x aléatoire
   		y = 350 + (int)((float)rand() * (500-350+1)/ (RAND_MAX-1));//distance y égale entre les vaisseaux 
 	    init_sprite(&world->enemies[i],x,y, S_WIDTH, S_HEIGHT, 1);
  		 }
 		else
 		{
    		x = 2*S_WIDTH + i*HORIZONTAL_DIST;//position x aléatoire
   			y = 350 + (int)((float)rand() * (500-350+1)/ (RAND_MAX-1));//distance y égale entre les vaisseaux 
 	 	   init_sprite(&world->enemies[i],x,y, S_WIDTH, S_HEIGHT, 1);
 	 	}
 	}
}

/**
 * \brief La fonction permet d'initialiser les données du monde du jeu
 * \param world les données du monde
 */
void init_data(world_t *world){

    init_sprite(&world->Steve,675,(W_HEIGHT-2*S_HEIGHT), S_WIDTH,S_HEIGHT, 2);
    init_Zombie(world);
} 
/**
 * \brief La fonction permet de faire avancer les Zombies
 * \param world les données du monde
 */
void update_Zombie(world_t *world){
  for (int i = 0; i < NB_ENEMIES; i++) {
  	if (world->Steve.x > world->enemies[i].x)
  	{
  		world->enemies[i].x += world->enemies[i].v;
  	}
  	else if (world->Steve.x < world->enemies[i].x)
  	{
  		world->enemies[i].x -= world->enemies[i].v;
  	}
  	if (world->Steve.y > world->enemies[i].y)
  	{
  		world->enemies[i].y += world->enemies[i].v;
  	}
  	else if (world->Steve.y < world->enemies[i].y)
  	{
  		world->enemies[i].y -= world->enemies[i].v;
  	}
    //world->enemies[i].y += world->enemies[i].v;//ajout de la vitesse à la position de l'élément
 	 }
}

