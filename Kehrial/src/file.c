#include "hub.h"

void printtab(char **tab, int h){
  for(int i = 0; i < h; i++){
      printf("%s\n", tab[i]);
  }  
}

char**  maketab(int h, int l){
  char **tab = malloc(sizeof(*tab) * h);
  for(int i = 0; i < h; i++) {
    tab[i] = malloc(sizeof(**tab) * l);
    for(int j = 0; j < l; j++)
      tab[i][j] = 0;
  }
  return(tab);
}

char**  loadmap(){
  char** tab = maketab(5, 5);
  FILE *fp = fopen("ressources/map.txt", "r");
  char c;
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 6; j++){
      c = fgetc(fp);
      if (c != '\n' && c != 0)
        tab[i][j] = c;
    }
  fclose(fp);
  return (tab);
}
