#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "table.h"

/*exo1()
{
	char nom_fichier[] = "chicago.txt";
	FILE* fichier = fopen(nom_fichier,"r"); // ouverture en lecture (read)
	if( fichier != NULL )
	{
		char c = fgetc(fichier); // lecture du 1er caractère dans fichier, 
             // puis fgetc se positionne sur le caractère suivant (pour la proichaine lecture)
		
		while( c != EOF )   // tant que le caractère lu n'est pas la fin de fichier (End Of File)
		{
			printf("%c", c);
			c = fgetc(fichier); // lecture du caractère suivant
		}
		
		fclose(fichier); // fermeture du fichier
	}
	else
	{
		printf("Problème lors de l'ouverture du fichier %s\n", nom_fichier);
	}
}*/



int main(int argc, char **argv)
{
	index_calculator("DUSSE","JEANCLAUDE", 25, 25);
	return 0;
}


