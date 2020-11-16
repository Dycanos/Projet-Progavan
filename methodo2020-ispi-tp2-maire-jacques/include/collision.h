#ifndef COLLISION
#define COLLISION

void get_boost(world_t *, int);
void bordures(sprite_t *);
void missilebord(world_t *);
void ennemibord(world_t *);
int sprites_collide(sprite_t *, sprite_t *);
int handle_sprites_collision(world_t *,int t);

#endif
