#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "table.h"

civil_servant * civil_servant_sort(civil_servant * civil1, civil_servant * civil2)
{
	int first_or_second_name = strcoll(civil1->name, civil2->name);
	if (first_or_second_name == 0)
	{
		int first_or_second_surname = strcoll(civil1->surname, civil2->surname);
		if (first_or_second_surname == 0) { return civil1; }
		else if(first_or_second_surname > 0) { return civil2; }
		else return civil1;
	}
	else if (first_or_second_name < 0) { return civil1; }
	else return civil2;
}

civil_servant * create_civil_servant(char* name, char* surname, unsigned int salary)
{
	civil_servant * new_civil_servant = malloc(sizeof(civil_servant));
	strcpy(new_civil_servant->name, name);
	strcpy(new_civil_servant->surname, surname);
	new_civil_servant->salary = salary;
	return new_civil_servant;
}

void put_civil_servant(civil_servant * new_civil_servant, int index_table, int index_vecteur)
{
	strcpy(table.vecteur[index_table].content[index_vecteur].name , new_civil_servant->name);
	strcpy(table.vecteur[index_table].content[index_vecteur].surname , new_civil_servant->surname);
	table.vecteur[index_table].content[index_vecteur].salary = new_civil_servant->salary;
	/*table.vecteur[index_table].content[index_vecteur].name = new_civil_servant->name;
	table.vecteur[index_table].content[index_vecteur].surname = new_civil_servant->surname;
	table.vecteur[index_table].content[index_vecteur].salary = new_civil_servant->salary;*/
}

unsigned long long power(int number, int power) // Calcul d'une valeur number à la puissance power
{
	unsigned long long resultat = 1;
	for (int i = 1; i <= power; i++)
    {
		resultat = resultat * number;
    }
    return resultat;
}

int index_calculator(char* name, char* surname)
{
	unsigned long long sum = 0;
	char* name_to_use = malloc(7 * sizeof(char));
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
		else { misc++; name_to_use[4 + i] = surname[i + misc]; }
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
    table.vecteur = malloc(table.size * sizeof(type_vector*));
    for (int i = 0; i < table.size; i++)
    {
        table.vecteur[i].logic_size = 0;
        table.vecteur[i].content = NULL;//malloc(sizeof(civil_servant));
        table.vecteur[i].physical_size = 0;
    }
    
}

void add(char* name, char* surname, unsigned int salary)
{
    int index = index_calculator(name, surname);
	printf("%i\n", index);
    //table.vecteur[index].content = malloc(sizeof(civil_servant));
	
	
	//bool name_are_the_same = strcoll()
	//for(int i = 0; i < table.vecteur[index].logic_size, i++)

	if(table.vecteur[index].physical_size == 0)
	{
		//printf("1\n");
		civil_servant * new_civil = create_civil_servant(name, surname, salary);
		table.vecteur[index].content = malloc(sizeof(civil_servant));
		put_civil_servant(new_civil, index, 0);
		table.vecteur[index].physical_size++;
		table.vecteur[index].logic_size++;
	}
	else if (table.vecteur[index].logic_size == table.vecteur[index].physical_size)
	{
		int i = 1;
		i++;
	}
	else 
		{
			int j = 1 ; j++;
		}
	printf("%s\n", table.vecteur[index].content[0].name);
		/*
    table.vecteur[index].content->name = name;
    table.vecteur[index].content->surname = surname;
    table.vecteur[index].content->salary = salary;
	*/
    //logic size
    // physical size
	  
	  
}