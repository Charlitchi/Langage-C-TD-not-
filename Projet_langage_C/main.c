#include <stdio.h>
#include <stdbool.h>
#include <string.h>

exo1()
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
}

int power(int number, int power)
{
	for (int i = 0; i < power; i++)
	{
		number *= number;
	}
	return number;
}
int index(char* s, unsigned int base, unsigned int N)
{
	int sum = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		sum += s[i]*power(base, i);
	}
	sum %= N;
	return sum;
}
int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
