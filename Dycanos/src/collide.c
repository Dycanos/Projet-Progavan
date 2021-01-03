#include "hub.h"

/**
 * \brief La fonction gère la collison de deux sprite
 * \param sp1 données d'un élément
 * \param sp2 données d'un élément
 * \return 1 si il y a une collison et 0 si il n'y en a pas
 */
int sprites_collide(sprite_t *sp1, sprite_t *sp2)
{
  //application des formules de collision
  int x1 = sp1->x + (sp1->w / 2);
  int x2 = sp2->x + (sp2->w / 2);
  int y1 = sp1->y + (sp1->h / 2);
  int y2 = sp2->y + (sp2->h / 2);
  double d = sqrt((pow((x1 - x2), 2) + pow((y1 - y2), 2)));
  double s = (sp1->w + sp2->w) / 2;
  if (d <= s){
      return(1);
  } else {
    return(0);
  }
}

/**
 * \brief La fonction gère la disparition des sprites lors d'une collison
 * \param sp1 données d'une texture
 * \param sp2 données d'une texture
 * \return 1 si un ennemi a été éliminé et 0 sinon
 */

void handle_sprites_collision(world_t *world)
{
  sprite_t *sp1, *sp2;
  sp1 = &world->Steve;
  for (int i = 0; i< NB_ENEMIES; i++) {
    sp2 = &world->enemies[i];
    if (sp1->is_visible == 0 && sp2->is_visible == 0 && sprites_collide(sp1, sp2) == 1){
      sp1->is_visible = 1;
      sp1->v = 0;
      sp2->is_visible = 1;
      sp2->v = 0;
       }
     }
}

/**
 * \brief La fonction gère que le Steve reste dans les bordures du jeu
 * \param sprite données d'une texture
 */

void bordure(sprite_t *sprite)
{
  if(sprite->x < 50)//dépasse à droite
        sprite->x = 50;
  if(sprite->x + S_WIDTH > W_WIDTH-50)//dépasse à gauche
        sprite->x = W_WIDTH - S_WIDTH - 50;
  if(sprite->y < 50)//dépasse en haut
        sprite->y = 50;
  if(sprite->y + S_HEIGHT > W_HEIGHT-50)//dépasse en bas
        sprite->y = W_HEIGHT- S_HEIGHT - 50;

}

void bordureMur(sprite_t *sprite)
{
  // MUR EN HAUT A GAUCHE
  if (sprite->x > 125 && sprite->x < 350 && sprite->y > 100 && sprite->y < 350)
  {
    if (sprite->x > 100 && sprite->x < 150)
    {
      sprite->x = 125;
    }
    if (sprite->x > 340 && sprite->x < 351)
    {
      sprite->x = 350;
    }
    if (sprite->y < 125 && sprite->y > 75)
    {
      sprite->y = 100;
    }
    if (sprite->y > 344 && sprite->y < 350)
    {
      sprite->y = 350;
    }
  }
  // MUR EN HAUT A DROITE
  if (sprite->x > 1025 && sprite->x < 1250 && sprite->y > 100 && sprite->y < 350)
  {
    if (sprite->x > 1000 && sprite->x < 1050)
    {
      sprite->x = 1025;
    }
    if (sprite->x > 1225 && sprite->x < 1250)
    {
      sprite->x = 1250;
    }
    if (sprite->y < 125 && sprite->y > 75)
    {
      sprite->y = 100;
    }
    if (sprite->y > 344 && sprite->y < 350)
    {
      sprite->y = 350;
    }
  }
  // MUR EN BAS A GAUCHE
  if (sprite->x > 125 && sprite->x < 350 && sprite->y > 450 && sprite->y < 700)
  {
    if (sprite->x > 100 && sprite->x < 150)
    {
      sprite->x = 125;
    }
    if (sprite->x > 344 && sprite->x < 351)
    {
      sprite->x = 350;
    }
    if (sprite->y < 475 && sprite->y > 425)
    {
      sprite->y = 450;
    }
    if (sprite->y > 689 && sprite->y < 700)
    {
      sprite->y = 700;
    }
  }
  // MUR EN BAS A DROITE
  if (sprite->x > 1025 && sprite->x < 1250 && sprite->y > 450 && sprite->y < 700)
  {
    if (sprite->x > 1000 && sprite->x < 1050)
    {
      sprite->x = 1025;
    }
    if (sprite->x > 1225 && sprite->x < 1250)
    {
      sprite->x = 1250;
    }
    if (sprite->y < 475 && sprite->y > 425)
    {
      sprite->y = 450;
    }
    if (sprite->y > 689 && sprite->y < 700)
    {
      sprite->y = 700;
    }
  }
  // MUR DU MILIEU
  if (sprite->x > 475 && sprite->x < 900 && sprite->y > 300 && sprite->y < 500)
  {
    if (sprite->x > 450 && sprite->x < 500)
    {
      sprite->x = 475;
    }
    if (sprite->x > 875 && sprite->x < 925)
    {
      sprite->x = 900;
    }
    if (sprite->y < 325 && sprite->y > 275)
    {
      sprite->y = 300;
    }
    if (sprite->y > 489 && sprite->y < 525)
    {
      sprite->y = 500;
    }
  }
}
