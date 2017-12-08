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
	int result_power = 1;
	for (int i = 1; i <= power; i++)
	{
		result_power *= number;
	}
	return result_power;
}
int index(char* name, char* surname, unsigned int base, unsigned int N)
{
	int sum = 0;
	char* name_to_use = malloc(7*sizeof(char));
	name_to_use[6] = '\0';
	for (int i = 0; i < 4; i++)
	{
		if(name[i] != '_')	{ name_to_use[i] = name[i]; }
		else { name_to_use[i] = name[i+1]; }
	}
	for (int i = 0; i < 2; i++)
	{
		if(surname[i] != '_')	{ name_to_use[i] = surname[i]; }
		else { name_to_use[4+i] = surname[i+1]; }
	}
	printf("%s\n", name_to_use);
	for (int i = 0; name_to_use[i] != '\0'; i++)
	{
		sum += name_to_use[i]*power(base, i);
	}
	sum %= N;
	return sum;
}
int main(int argc, char **argv)
{
	index("DUSSE","JEANCLAUDE", 25, 25);
	return 0;
}


