#ifndef COLLIDE
#define COLLIDE


int sprites_collide(sprite_t *sp1, sprite_t *sp2);
void handle_sprites_collision(world_t *world);
void bordure(sprite_t *sprite);
void bordureMur(sprite_t *sprite);
#endif