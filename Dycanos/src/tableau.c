#include "hub.h"


char** allouer_tab_2D(int n,int m)
{
   char** table = malloc(n*sizeof(char*));
   for(int i = 0;i<n;i++)
   {
   		table[i] = malloc(m*sizeof(char));
   }
   for(int j = 0; j<n;j++)
  	 {
  	 	
  	 	for(int k = 0; k<m;k++)
  	 		{	
  	 		table[j][k] = "";
	}
}
	return table;
}
void afficher_tableau(char** tab,int n,int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf("%c ",tab[i][j]);
		}
		printf("\n");
	}
}

char** lire_fichier()
{
	FILE* pFile = fopen("ressources/tableau.txt","r");
	char** tableau = allouer_tab_2D(6,6);
	int test;
	for(int i =0;i<5;i++){
		for(int j = 0;j<6;j++){
			test = fgetc(pFile);
			tableau[i][j] = test;
		}
	}
	fclose(pFile);
	return tableau;
}
	