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
    table.vecteur = malloc(table.size * sizeof(type_vector));
    for (int i = 0; i < table.size; i++)
    {
        table.vecteur[i].logic_size = 0;
        //table.vecteur[i].content = malloc(10*sizeof(civil_servant));
        table.vecteur[i].content = NULL;
        table.vecteur[i].physical_size = 0;
		//table.vecteur[i] = NULL;
    }   
    
}
type_vector * create_larger_vector(int index_to_create)
{
	type_vector * future_vector = malloc(sizeof(type_vector));
	future_vector->physical_size 	= table.vecteur[index_to_create].physical_size + 1;														// On rajoute 1 à la taille physique
	//printf("%i\n", future_vector->physical_size);
	int new_physical_size 			= future_vector->physical_size;								// Par souci de clareté, on utilise une nouvelle variable qui représente la nouvelle taille physique du vecteur à l'index 
	future_vector->logic_size 		= table.vecteur[index_to_create].logic_size + 1;														// On rajoute 1 à la taille logique
	//printf("%i\n", future_vector->logic_size);
	future_vector->content = malloc(new_physical_size * sizeof(civil_servant));			// On crée un nouvel espace mémoire pour la table de vecteur
	
	for(int i = 0; i < new_physical_size; i++)															// On parcourt le tableau pour l'initialiser
	{
		future_vector->content->name		= NULL;
		future_vector->content->surname		= NULL;
		future_vector->content->salary		= 0;
	}
	return future_vector;
}
bool civil_servant_is_in_the_table(civil_servant const * potential_civil_servant, int index_of_cs)
{
	bool same_name = -1;
	bool same_surname = -1;
	bool result = false;
	for (int i = 0; i < table.vecteur[index_of_cs].logic_size; i++)
	{
		same_name = strcoll(table.vecteur[index_of_cs].content[i].name, potential_civil_servant->name);
        same_surname= strcoll(table.vecteur[index_of_cs].content[i].surname, potential_civil_servant->surname);
		if(same_name == 0 && same_surname == 0)
		{
			result = true;
            break;
		}
		else
		{
			same_name = -1;
			same_surname = -1;
		}
	}
	return result;
}
int index_to_put_civil_servant(civil_servant const * new_civil_servant, int index_vector)
{
	int index_to_put_civil_servant;
	int result_of_sort = -1;
	for (int i = 0; i < table.vecteur[index_vector].logic_size; i++)
	{
		result_of_sort = civil_servant_sort(new_civil_servant, &(table.vecteur[index_vector].content[i]));
		if(result_of_sort < 0)
		{
			index_to_put_civil_servant = i;
		}
	}
	return index_to_put_civil_servant;
}
int add(char* name, char* surname, unsigned int salary)
{
    /*int index = index_calculator(name, surname);
    if (table.vecteur[index].content == NULL)
    {
        table.vecteur[index].content= malloc(sizeof(civil_servant));
        table.vecteur[index].content[0].name = name;
        table.vecteur[index].content[0].surname = surname;
        table.vecteur[index].content[0].salary = salary;
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
    }*/
	int index = index_calculator(name, surname);
    int effectue = 0;
	civil_servant * new_civil_servant = create_civil_servant(name, surname, salary);
	
	if (!civil_servant_is_in_the_table(new_civil_servant, index))
	{
		if (table.vecteur[index].physical_size == table.vecteur[index].logic_size)
		{
			type_vector vector_to_manipulate;
			if (table.vecteur[index].physical_size == 0)
			{
				type_vector * new_vect = create_larger_vector(index);
				new_vect->content->name = malloc(sizeof(name));
				new_vect->content->surname = malloc(sizeof(surname));
				strcpy(new_vect->content->name, name);
				strcpy(new_vect->content->surname, surname);
				new_vect->content->salary = salary;
				table.vecteur[index].content = new_vect->content;
				table.vecteur[index].logic_size = new_vect->logic_size;
				table.vecteur[index].physical_size = new_vect->physical_size;
                effectue =1;
			}
			else
			{
				type_vector *new_vec = create_larger_vector(index);
				/*printf("%i\n", new_vec->physical_size);
				int index_to_put = index_to_put_civil_servant(new_civil_servant, index);
				int time_to_shift = 0;
				for (int i = 0; i < table.vecteur[index].physical_size; i++)
				{
					if (i == index_to_put)
					{
						new_vec->content[i] = *new_civil_servant;
						time_to_shift++;
					}
					else new_vec->content[i + time_to_shift] = table.vecteur[index].content[i];
				}*/
				for (int i = 0; i < table.vecteur[index].physical_size; i++)
				{
					new_vec->content[i] = table.vecteur[index].content[i] ;
				}
				new_vec->content[table.vecteur[index].physical_size] = *new_civil_servant;
				//printf("%i\n", new_vec->physical_size);
				table.vecteur[index] = *new_vec;
				// CODER UNE FONCTION QUI RANGE PAR ORDRE ALPHABETIQUE
                effectue =1;
			}
		}
		else
		{
            type_vector *new_vec = create_larger_vector(index);
            for (int i = 0; i < table.vecteur[index].physical_size; i++)
				{
					new_vec->content[i] = table.vecteur[index].content[i] ;
				}
			new_vec->content[table.vecteur[index].physical_size] = *new_civil_servant;
				printf("%i\n", new_vec->physical_size);
				table.vecteur[index] = *new_vec;
                effectue =1;
		}
	}
    else
    {
        effectue = 0;
    }
    return effectue;
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
       // printf("\n%d\n", table.vecteur[index_value].logic_size);
        for (int i =0; i<table.vecteur[index_value].logic_size;i++)
        {
           value_name = strcoll(table.vecteur[index_value].content[i].name, name_test);
           value_surname= strcoll(table.vecteur[index_value].content[i].surname, surname_test);
           //printf(" \n ----- index n°%d -----\n ", i);
           //printf(" -- %i -- %i --  ", value_name, value_surname);
           //printf("-- salary : %d -- ",table.vecteur[index_value].content[i].salary);
           if (value_name == 0 && value_surname == 0)
            {
               salary_value = table.vecteur[index_value].content[i].salary;
               break;
            }
        }
    }
    return salary_value;
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
			if (tour < number_of_servant)
			{
    
				alloc_name = (char*) malloc(20);
				alloc_surname = (char*) malloc(20);
				civil_servant * new_civil = malloc(sizeof(civil_servant));
				//fscanf(fichier, "%s %s %d", name, surname, &new_civil->salary);
				fscanf(fichier, "%s %s %d", alloc_name, alloc_surname, &new_civil->salary);
				//fscanf(fichier, "%s %s %u", name, surname, &new_civil->salary);
				//printf("\ntour n°%d : %s", tour + 1, alloc_surname);
				//printf("\ntour n°%d : %d",tour+1, new_civil->salary);
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

void conflict()
{
-printf("\n\n-----Vous avez choisi conflict-----\n\n");
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
              else
          {
               printf("Il n'y a pas de conflit à l'index : %i car celui-ci n'existe pas \n", i);
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
    double number_of_conflict =0;
    double conflit_size =0;
    printf("\n\n-----Vous avez choisi nombre moyen de conflit-----\n\n");
  for (int i =0; i< table.size;i++)
  {
      if (table.vecteur[i].content!= NULL)
      {
          if (table.vecteur[i].logic_size>0)
          {
              printf("Il y a %i conflit(s) à l'index : %i\n", table.vecteur[i].logic_size, i);
               number_of_conflict ++;
              conflit_size = conflit_size + table.vecteur[i].logic_size;
          }
          else
          {
               printf("Il n'y a pas de conflit à l'index : %i\n", i);
          }

              }
              else
              {
               printf("Il n'y a pas de conflit à l'index %i car celui-ci n'existe pas.\n", i);
          }
          }
          double result = conflit_size/number_of_conflict;
          printf("Il y a donc %lf en moyenne par index", result);
    




/*
void load (int number_of_servant)
{
    char name[20]; // = malloc(20*sizeof(char));
        char* test = "carol"; 
        sprintf(name, "%s", test);
        printf("name test : %s", name);
        test = "v2";
             sprintf(name, "%s", test);
       printf("name test : %s", name);
}
*/
/*  
void load(int number_of_servant)
{
    int TAILLE_MAX = 30;
    FILE* fichier = NULL;
    char chaine[TAILLE_MAX];
    char *name = malloc(20* sizeof(char));
    char *surname = malloc(20*sizeof(char));
   // char surname[20]; //= malloc(sizeof(char));   
    fichier = fopen("chicago.txt", "r");
  //for (int i = 0; )
int tour = 0;
 
    if (fichier != NULL)
    {
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL)// On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
    {
        for (int i =0; i<1; i++)
        {
            
                civil_servant * new_civil = malloc(sizeof(civil_servant));
                fscanf(fichier, "%s %s %u", name, surname, &new_civil->salary);
                //new_civil->name = name;
                //new_civil->surname = surname;
                tour++;
                printf("%d : %s", i, name );
               // printf("%s ", new_civil->name);
               // printf("%s \n", new_civil->surname);
                //int i = index_calculator(name,surname);
                //printf("%d", i);
                
            }
        }
            
}    

  
        fclose(fichier);
    }
    */
/*
void load(int number_of_servant)
{
    char nom_fichier[] = "Chicago.txt";
	FILE* fichier = fopen(nom_fichier,"r"); // ouverture en lecture (read)
   char name[20]; //= malloc(sizeof(char));
    //char surname[20]; //= malloc(sizeof(char));
    //char* read_name;
  //  char* read_surname;
  char test[1];
    int tour =0;
	if( fichier != NULL )
	{
		char c = fgetc(fichier); // lecture du 1er caractère dans fichier, 
        printf(" le char est : %c", c);
             // puis fgetc se positionne sur le caractère suivant (pour la proichaine lecture)
		
		while( c != EOF && tour <1)   // tant que le caractère lu n'est pas la fin de fichier (End Of File)
		{
            int i =0;
            test[0] =c;
            while( test[0] =! ' ' )
            {
                
                name[i] = c;
                i++;
                c = fgetc(fichier);
                test[0] =c;
            }
            name[i+1] = '\0';
            tour++;
            printf("\nle nom est : %s",name);
            
			//printf("%c", c);
			c = fgetc(fichier); // lecture du caractère suivant
		}
		
		fclose(fichier); // fermeture du fichier
	}
	else
	{
		printf("Problème lors de l'ouverture du fichier %s\n", nom_fichier);
	}
}
*/

}