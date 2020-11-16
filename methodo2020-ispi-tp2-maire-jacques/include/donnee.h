#ifndef DONNEE
#define DONNEE

void recup(world_t *);
char* scoring(char *, world_t *);
void clean_data(world_t *);
int is_game_over(world_t *);
void update_enemies(world_t *);
int end_enemies(world_t *);
void compute_game(world_t *);
void update_data(world_t *);

#endif
