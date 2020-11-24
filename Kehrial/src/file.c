#include "hub.h"

void printtab(char **tab, int h, int l){
  for(int i = 0; i < h; i++){
    for(int j = 0; j < l; j++)
      printf("%c", tab[i][j]);
    putchar('\n');
  }  
}

void filltab(char ** tab, char *str){
  int j = 0, k = 0;
  for(int i = 0; i < 30; i++) {
    if(str[i] ==  '\n' || str[i] == 0){
      k = 0; j++;
    } else {
      tab[j][k] = str[i];
      k++;
    }
  }
}

void maketab(char * str, int h, int l){
  char **tab = malloc(sizeof(*tab) * h);
  for(int i = 0; i < h; i++)
    tab[i] = malloc(sizeof(**tab) * l);
  
}

void loadmap(){
  int i = 0;
  char chaine[6] = "";
  char res[30] = "";
  FILE *fp = fopen("ressources/map.txt", "r");
  while (fgets(chaine, 6, fp) != NULL) {
    for (int j = 0; chaine[j] != 0; j++, i++) {
      res[i] = chaine[j];
    }
  }
  fclose(fp);
  char** tab = NULL;
  maketab(res, 5, 5);
  filltab(tab, res);
  printtab(tab, 5, 5);
}

