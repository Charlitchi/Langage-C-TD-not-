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
	new_civil_servant->name = malloc(sizeof(name));
	strcpy(new_civil_servant->name, name);
	new_civil_servant->surname = malloc(sizeof(surname));
	strcpy(new_civil_servant->surname, surname);
	new_civil_servant->salary = salary;
	return new_civil_servant;
}

void put_civil_servant(civil_servant * new_civil_servant, int index_table, int index_vecteur)
{
	printf("%p\n", table.vecteur[index_table].content[index_vecteur].name);
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
    table.vecteur = malloc(table.size * sizeof(type_vector));
    for (int i = 0; i < table.size; i++)
    {
        table.vecteur[i].logic_size = 0;
        table.vecteur[i].content = NULL;//malloc(sizeof(civil_servant));
        table.vecteur[i].physical_size = 0;
    }
    
}

int show_salary(char* name_test, char* surname_test)
{
    int index_value = index_calculator(name_test, surname_test);
    int value_name = -1;  
    int value_surname =-1;
    unsigned int salary_value = 0;
    if (table.vecteur[index_value].content == NULL)
    {
        return salary_value;
    }
    else
    {
        printf("\n%d\n", table.vecteur[index_value].logic_size);
        for (int i =0; i<table.vecteur[index_value].logic_size;i++)        {

           value_name = strcoll(table.vecteur[index_value].content[i].name, name_test);
         
           value_surname= strcoll(table.vecteur[index_value].content[i].surname, surname_test);
            printf(" \n ----- index n°%d -----\n ", i);
           printf(" -- %i -- %i --  ", value_name, value_surname);
           printf("-- salary : %d -- ",table.vecteur[index_value].content[i].salary);
           if (value_name == 0 && value_surname == 0)
           {
               salary_value = table.vecteur[index_value].content[i].salary;
               break;
           }
            /*
            if (table.vecteur[index_value].content[i].name == name_test && table.vecteur[index_value].content[i].surname == surname_test )
            {
                salary_value = table.vecteur[index_value].content[i].salary;
            }
             */
        }
    }

    return salary_value;
        
        
        
       // table.vecteur[index].content[table.vecteur[index].logic_size].name
} 


void show_salary_between(int first_index, int end_index)
{
    if (first_index<0 || first_index >end_index)
    {
        first_index = 0;
    }
    if (end_index >=100)
    {
        end_index =99;
    }
    for (int i =first_index; i< end_index;i++)
    {
      if (table.vecteur[i].content!= NULL)
      {
          printf("\n -------- index n°%d --------  \n ", i);
          for (int j=0; j<table.vecteur[i].logic_size;j++)
          {
              if( table.vecteur[i].content[j].name != NULL)
              {
                  printf("Le salaire de %s %s est de : %u $ \n",table.vecteur[i].content[j].name, table.vecteur[i].content[j].surname,table.vecteur[i].content[j].salary );
              }
          }
          
          }
 }
 }

void add(char* name, char* surname, unsigned int salary)
{
    int index = index_calculator(name, surname);
	//printf("%i\n", index);
    //table.vecteur[index].content = malloc(sizeof(civil_servant));
	
	
	//bool name_are_the_same = strcoll()
	//for(int i = 0; i < table.vecteur[index].logic_size, i++)

	if(table.vecteur[index].logic_size == 0)
	{
		//printf("1\n");
		civil_servant * new_civil = create_civil_servant(name, surname, salary);
		table.vecteur[index].content = malloc(sizeof(civil_servant));
		/*table.vecteur[index].content->name = NULL;
		table.vecteur[index].content->surname = NULL;
		table.vecteur[index].content->salary = 0;*/
		//table.vecteur[index].content = new_civil;
		//put_civil_servant(new_civil, index, 0);
        table.vecteur[index].content[table.vecteur[index].logic_size].name = new_civil->name;
        table.vecteur[index].content[table.vecteur[index].logic_size].surname = new_civil->surname;
        table.vecteur[index].content[table.vecteur[index].logic_size].salary = new_civil->salary;
		table.vecteur[index].physical_size++;
		table.vecteur[index].logic_size++;
	}
	else 
    {
        if (table.vecteur[index].logic_size == table.vecteur[index].physical_size)
	{
		civil_servant * new_civil = create_civil_servant(name, surname, salary);
        table.vecteur[index].content[table.vecteur[index].logic_size].name = new_civil->name;
        table.vecteur[index].content[table.vecteur[index].logic_size].surname = new_civil->surname;
        table.vecteur[index].content[table.vecteur[index].logic_size].salary = new_civil->salary;
        table.vecteur[index].physical_size++;
		table.vecteur[index].logic_size++;
         
	}
	if(table.vecteur[index].logic_size < table.vecteur[index].physical_size)
		{
            
		civil_servant * new_civil = create_civil_servant(name, surname, salary);
        table.vecteur[index].content[table.vecteur[index].logic_size].name = new_civil->name;
        table.vecteur[index].content[table.vecteur[index].logic_size].surname = new_civil->surname;
        table.vecteur[index].content[table.vecteur[index].logic_size].salary = new_civil->salary;
		table.vecteur[index].logic_size++;
         
		}
        }
    }
//	printf("%s\n", table.vecteur[index].content[0].name);
		/*
    table.vecteur[index].content->name = name;
    table.vecteur[index].content->surname = surname;
    table.vecteur[index].content->salary = salary;
	*/
    //logic size
    // physical size
	  
	  
void conflict()
{
printf("\n\n-----Vous avez choisi conflict-----\n\n");
    int number_of_conflict =0;
  for (int i =0; i< table.size;i++)
  {
      if (table.vecteur[i].content!= NULL)
      {
          if (table.vecteur[i].logic_size>0)
          {
              printf("Il y a un conflit à l'index : %i\n", i);
              number_of_conflict++;
              
          }
          else
          {
               printf("Il n'y a pas de conflit à l'index : %i\n", i);
          }

              }
          }
        if (number_of_conflict == table.size)
        {
            printf("Il y a des conflits dans toute la table");
            
        }   
else
    {
    
  
      printf("Il y a %i conflit dans la table\n", number_of_conflict);
     }
     } 
  
  

void average_conflict()
{
    printf("\n\n-----Vous avez choisi nombre moyen de conflit-----\n\n");
  for (int i =0; i< table.size;i++)
  {
      if (table.vecteur[i].content!= NULL)
      {
          if (table.vecteur[i].logic_size>0)
          {
              printf("Il y a %i conflit(s) à l'index : %i\n", table.vecteur[i].logic_size, i);
          }
          else
          {
               printf("Il n'y a pas de conflit à l'index : %i\n", i);
          }

              }
          }
    
    
    
}


void load(int number_of_servant)
{
    int TAILLE_MAX = 1000;
    FILE* fichier = NULL;
    char chaine[TAILLE_MAX];
    char* alloc_name;// = (char*) malloc(20);
    char* alloc_surname;// = (char*) malloc(20);
 //   char * alloc_surname = malloc(20*sizeof(char));
   // int salary;

    fichier = fopen("chicago.txt", "r");
  //for (int i = 0; )
int tour = 0;
 
    if (fichier != NULL)
    {
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL)  // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
if (tour <number_of_servant)
{
    
            alloc_name = (char*) malloc(20);
            alloc_surname = (char*) malloc(20);
            civil_servant * new_civil = malloc(sizeof(civil_servant));
            //fscanf(fichier, "%s %s %d", name, surname, &new_civil->salary);
            fscanf(fichier, "%s %s %d", alloc_name, alloc_surname, &new_civil->salary);
       //     fscanf(fichier, "%s %s %u", name, surname, &new_civil->salary);
            printf("\ntour n°%d : %s",tour+1, alloc_name);
           // printf("\ntour n°%d : %s",tour+1, alloc_surname);
            //printf("\ntour n°%d : %d",tour+1, new_civil->salary);
            printf("\ntour n°%d - index  %d",tour+1, index_calculator(alloc_name, alloc_surname));
            new_civil->name = alloc_name;
            new_civil->surname = alloc_surname;
            add(new_civil->name, new_civil->surname, new_civil->salary);
            
            //alloc_surname =  malloc(20*sizeof(char));
          //  add(name, surname,new_civil->salary);
            tour++;
            //free(name); free(surname);
           // name = ( char *) malloc(20* sizeof(char));
        //   name = malloc(20*sizeof(char));
         //   surname = malloc(20*sizeof(char));
        }
        else
        {
            break;
    }
    }
    }  
        fclose(fichier);
}

