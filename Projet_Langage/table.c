#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "table.h"


unsigned long long power(int number, int power) // Calcul d'une valeur number à la puissance power
{
unsigned long long resultat = 1;
for (int i =1; i<=power; i++)
    {
    resultat = resultat * number;
    }
    return resultat;
}

int index_calculator(char* name, char* surname)
{
	unsigned long long sum = 0;
	char* name_to_use = malloc(7*sizeof(char));
	name_to_use[6] = '\0';
	int misc = 0;
	for (int i = 0; i < 4; i++)
	{
		if(name[i] != '_')	{ name_to_use[i] = name[i]; }
		else { misc++; name_to_use[i] = name[i + misc]; }
		//printf("%s\n", name_to_use);
	}
	misc = 0;
	for (int i = 0; i < 2; i++)
	{
		if(surname[i] != '_')	{ name_to_use[4 + i] = surname[i]; }
		else { misc++; name_to_use[4+i] = surname[i + misc]; }
		//printf("%s\n", name_to_use);
	}
	//printf("%s\n", name_to_use);
	for (int i = 0; name_to_use[i] != '\0'; i++)
	{
		sum += name_to_use[i] * power(table.base, i);
    }
    //printf("%lu", sum);
	//sum %= N;
	sum %= table.size;
	free(name_to_use);
	name_to_use = NULL;
	return (int) sum;
}

void create_table()
{
    table.vecteur = malloc(table.size*sizeof(type_vector*));
    for (int i =0; i<table.size;i++)
    {
        table.vecteur[i].logic_size = 0;
        table.vecteur[i].content = malloc(sizeof(civil_servant));
        table.vecteur[i].physical_size = 0;
    }
    
}

void add(char* name, char* surname, unsigned int salary)
{
    int index = index_calculator(name, surname);
    //table.vecteur[index].content = malloc(sizeof(civil_servant));
    table.vecteur[index].content->name = name;
    table.vecteur[index].content->surname = surname;
    table.vecteur[index].content->salary = salary;
    //logic size
    // physical size
}