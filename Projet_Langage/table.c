#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "table.h"
#include <stdlib.h>


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
        //table.vecteur[i].content = malloc(10*sizeof(civil_servant));
        table.vecteur[i].content = NULL;
        table.vecteur[i].physical_size = 0;
    }   
    
}

void add(char* name, char* surname, unsigned int salary)
{
    int index = index_calculator(name, surname);
    if (table.vecteur[index].content == NULL)
    {
        table.vecteur[index].content= malloc(sizeof(civil_servant));
        table.vecteur[index].content[table.vecteur[index].logic_size].name = name;
        table.vecteur[index].content[table.vecteur[index].logic_size].surname = surname;
        table.vecteur[index].content[table.vecteur[index].logic_size].salary = salary;
        table.vecteur[index].physical_size++;
        table.vecteur[index].logic_size++;
    }
    
    else
    {
        for (int i =0; i<=table.vecteur[index].logic_size;i++)
        {
            if (table.vecteur[index].content[i].name == name && table.vecteur[index].content[i].surname == surname)
            {
                break;
            }
        }
        if (table.vecteur[index].physical_size == table.vecteur[index].logic_size)
        {
        table.vecteur[index].content[table.vecteur[index].logic_size].name = name;
        table.vecteur[index].content[table.vecteur[index].logic_size].surname = surname;
        table.vecteur[index].content[table.vecteur[index].logic_size].salary = salary;
        table.vecteur[index].physical_size++;
        table.vecteur[index].logic_size++;
        }
        if (table.vecteur[index].physical_size > table.vecteur[index].logic_size)        
        {

        table.vecteur[index].content[table.vecteur[index].logic_size].name = name;
        table.vecteur[index].content[table.vecteur[index].logic_size].surname = surname;
        table.vecteur[index].content[table.vecteur[index].logic_size].salary = salary;
        table.vecteur[index].logic_size++;
            
            
            
        }
        
    }
       
    
}
int show_salary(char* name, char* surname)
{
    int index_value = index_calculator(name, surname);
    int salary = 0;
    for(int i=1; i<=table.vecteur[index_value].physical_size; i++)
    {
        if (name == table.vecteur[index_value].content[i].name && surname == table.vecteur[index_value].content[i].surname )
        {
            salary = table.vecteur[index_value].content[i].salary;
        }
    }
    return salary;
}

void load(int number_of_servant)
{
    int TAILLE_MAX = 1000;
    FILE* fichier = NULL;
    char chaine[TAILLE_MAX];
    char* name;// = ( char *) malloc(20* sizeof(char));
    char * surname;// = ( char *)malloc(20*sizeof(char));
   // int salary;

    fichier = fopen("chicago.txt", "r");
  //for (int i = 0; )
int tour = 0;
 
    if (fichier != NULL)
    {
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL && tour <1)  // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
                      //  name = ( char *) malloc(20* sizeof(char));
                    //   surname = ( char *) malloc(20* sizeof(char));
            civil_servant * new_civil = malloc(sizeof(civil_servant));
            //fscanf(fichier, "%s %s %d", name, surname, &new_civil->salary);
            fscanf(fichier, "%s %s %d", name, surname, &new_civil->salary);
       //     fscanf(fichier, "%s %s %u", name, surname, &new_civil->salary);
            //printf("%s",name);
            add(name, surname,new_civil->salary);
            tour++;
            //free(name); free(surname);
            name = ( char *) malloc(20* sizeof(char));
           // name = ( char *) malloc(20* sizeof(char));
        }
    }  
        fclose(fichier);

}

