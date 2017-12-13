#include "table.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char * alphabetical_arrange(char * word1, char * word2)
{
	for(int i = 0; word1[i] != '\0' && word2[i] != '\0'; i++)
	{
		if (word1[i] > word2[i]) 
		{
			return word1;
		}
		if (word2[i] > word1[i]) 
		{
			return word2;
		}
	}
	int i = 0;
	while(1)
	{
		if (word1[i] == '\0') 
		{
			return word1;
		}
		if (word2[i] == '\0') 
		{
			return word2;
		}
		i++;
	}
	return word1;
}

civil_servant * civil_servant_alphabetical_arrange(civil_servant * civil_servant1, civil_servant * civil_servant2) // à vérifier
{
	//bool name
	//if(civil_servant1->name == alphabetical_arrange(civil_servant1->name, civil_servant2->name &&)
	// Calcul du 1er selon l'ordre alphabétique des NOMS
	char * first_name1 = alphabetical_arrange(&(civil_servant1->name), &(civil_servant2->name));
	char * first_name2 = alphabetical_arrange((&civil_servant2->name), &(civil_servant1->name));
	bool name_are_the_same = (first_name1 != first_name2);
	if(name_are_the_same == false) // teste si les noms sont les memes
	{ // si les noms ne sont pas les memes
		
		if (&(civil_servant1->name) == alphabetical_arrange(&civil_servant1, &civil_servant2))
		{
			return civil_servant1;
		}
		if (&(civil_servant2->name) == alphabetical_arrange(&civil_servant1, &civil_servant2))
		{
			return civil_servant2;
		}
	}
	else // si les noms sont les mêmes
	{
		char * first_surname1 = alphabetical_arrange(&(civil_servant1->surname), &(civil_servant2->surname));
		char * first_surname2 = alphabetical_arrange(&(civil_servant2->surname), &(civil_servant1->surname));
		
		bool surname_are_the_same = (first_surname1 != first_surname2);
		if (surname_are_the_same == false) // teste si les prénoms sont les memes
		{ // si les prénoms sont différents
			if (&(civil_servant1->name) == first_name1)
			{
				return civil_servant1;
			}
			if (&(civil_servant2->name) == first_name1)
			{
				return civil_servant2;
			}
		}
		return civil_servant1;
	}
}

unsigned long long power(int number, int power)
{
unsigned long long resultat = 1;
for (int i =1; i<=power; i++)
    {
    resultat = resultat * number;
    }
    return resultat;
}

//int index_calculator(char* name, char* surname, unsigned int base, unsigned int N)
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
		sum += name_to_use[i] * power(table_base, i);
    }
    //printf("%lu", sum);
	//sum %= N;
	sum %= table_size;
	free(name_to_use);
	name_to_use = NULL;
	return (int) sum;
}

void create_table()
{
	table = malloc(table_size * sizeof(civil_servant*));
	table_index_size = malloc(table_size * sizeof(civil_servant*));
	for(int i = 0; i < table_size; i++) { table[i] = NULL; table_index_size[i] = 0; }
    
    /*
    civil_servant * new_civil = malloc(sizeof(civil_servant));
    new_civil->name = "carol";
    printf("%s", new_civil->name);
    table[1] = new_civil;
    printf("%s", table[1]->name);
     * 
     */ //Ceci est un essai pour voir comment cela marche
    //return table;

}

/*
civil_servant ** create_table(unsigned int size_table, unsigned int base, int i)
{
	civil_servant ** the_table = malloc(size_table*sizeof(int*));
	for (int i = 0; i < size_table; i++)
	{
		the_table[i] = NULL;
	}
	return the_table;
}*/

void add(char* name, char* surname, unsigned int salary, civil_servant* civil){
	/*if(civil->next == NULL)
	{
		civil_servant * new_civil = malloc(sizeof(civil_servant));
		civil->next = new_civil;
		new_civil->next = NULL;
		new_civil->surname = surname;
		new_civil->name = name;
		new_civil->salary = salary;
	}
	else 
	{
		add(name, surname, salary,  civil->next);
	}*/
	//int civil_servant_index = 
}

civil_servant * create_civil_servant(char* name, char* surname, unsigned int salary)
{
	civil_servant * new_civil_servant = malloc(sizeof(civil_servant));
	new_civil_servant->name = name ;
	new_civil_servant->surname = surname ;
	new_civil_servant->salary = salary ;
}

void add_new(char* name, char* surname, unsigned int salary) // A PUTAIN DE VERIFIER
{
	int civil_servant_index = index_calculator(name, surname);
	civil_servant * new_civil_servant = create_civil_servant(name, surname, salary);
	
	if (table[civil_servant_index] == NULL)
	{
		table[civil_servant_index] = new_civil_servant;
	}
	else
	{
		civil_servant * ptr_temp = table[civil_servant_index];																// création d'un tableau de fonctionnaire temporaire qui est 
		table[civil_servant_index] = malloc((table_index_size[civil_servant_index] + 1) * sizeof(civil_servant));			// création d'un nouveau tableau de fonctionnaire
		table_index_size[civil_servant_index]++;																			// la taille du tableau est mise à jour
		
		/*for (int i = 0; i < table_index_size[civil_servant_index] - 1 ; i++)												// parcourt le tableau de fonctionnaire
		{*/
			bool new_civil_is_still_unplaced = true;
			for (int i = 0; new_civil_is_still_unplaced && (i < table_index_size[civil_servant_index] - 1); i++)
			{
				if (( new_civil_servant == civil_servant_alphabetical_arrange(new_civil_servant, ptr_temp[i]) ) && new_civil_is_still_unplaced) // VERIFIER SI ON COMPARE DES CHOSES COMPARABLES
				{
					table[civil_servant_index][i] = new_civil_servant;
					new_civil_is_still_unplaced = false;
				}
				else
				{
					table[civil_servant_index][i] = ptr_temp[i];
				}
			}
	}
}


int show_salary(char* name, char* surname, civil_servant * civil) // il faudra faire une boucle et dans l'appel de la fonction, écrire : show_salary(.. , .., table[i])
{
	if( civil-> next != NULL)
	{
		if (civil->name == name && civil->surname == surname)
		{
			return civil->salary;
		}
		else
		{
			return show_salary(name, surname, civil->next);
		}
	}
	else
    {
		return -1;
    }
        // Il manque des returns 
}


int show_salary_between(int first_index, int end_index,civil_servant ** table)
{
	for (int i = first_index; i <= end_index; i++)
	{
		salary(table[i]);
	}
	// il manque un return
}
void salary(civil_servant * civil)
{
    if (civil->next != NULL)
    {
        printf("le salaire de %s %s est de %d",civil->name, civil->surname, civil->salary);
        salary(civil->next);
    }
}


int* civil_servant_number_by_index(civil_servant ** table)
// Crée un tableau contenant le nombre de fonctionnaire par index
{
	//int N = 12; // Récuperer N
	//int * civil_servant_number_by_index = malloc(N * sizeof(int)); 
	int * civil_servant_number_by_index = malloc(table_size * sizeof(int)); 
	// crée un tableau de la même taille que la table
	for (int i = 0; i < table_size; i++)
	{
		civil_servant_number_by_index[i] = 0;
	}
	//initialise le tableau à 0
	for (int i = 0; i < table_size; i++) // parcourt le tableau sur tous les indices
	{
		if (table[i] != NULL)
		// teste s'il y a un fonctionnaire à l'index 'i'
		{
			civil_servant_number_by_index[i]++; 	// si oui, ajoute '1' au tableau à l'index correspondant
			civil_servant* some_civil = table[i]; 	// pour simplifier l'écriture, on nomme 'some_civil' un pointeur vers un fonctionnaire
			while (some_civil->next != NULL) 		// teste si le fonctionnaire à un suivant
			{
				civil_servant_number_by_index[i]++;	// si oui, ajoute '1' au tableau à l'index correspondant
				some_civil = some_civil->next;		// passe au fonctionnaire suivant
			}
		}
	}
	return civil_servant_number_by_index;			// retourne le tableau avec le nombre de fonctionnaire rangé par index
}

int conflict(civil_servant ** table)
// Calcule le nombre de conflit 
{
	int N = 12; // il faut récupere N
	int * civil_servant_tab = civil_servant_number_by_index(table);	// récupère le tableau du nombre de fonctionnaire par index
	int conflict_number = 0; 										// crée 'conflict_number', le nombre de conflit et l'initialise à 0
	for (int i = 0; i < N; i++)										// parcourt le tableau
	{
		if (civil_servant_tab[i] >= 2)								// teste s'il y a 2 ou plus de fonctionnaire à l'index 'i'
		{
			conflict_number++;										// si oui, on ajoute 1 au nombre de conflit
		}
	}
	free(civil_servant_tab);										
	civil_servant_tab = NULL;
	return conflict_number;											// retourne le nombre de conflit
}

float average_conflict(civil_servant ** table)
// Calcule le nombre moyen de conflit : nombre de conflit divisé par la taille de la table 
{
	int N = 12; 			// il faut récupere N
	int * civil_servant_tab = civil_servant_number_by_index(table);	// récupère le tableau du nombre de fonctionnaire par index
	int conflict_number = 0; 										// crée 'conflict_number', le nombre de conflit et l'initialise à 0
	for (int i = 0; i < N; i++)										// parcourt le tableau
	{
		if (civil_servant_tab[i] >= 2)								// teste s'il y a 2 ou plus de fonctionnaire à l'index 'i'
		{
			conflict_number += civil_servant_tab[i];					// si oui, on ajoute le nombre de fonctionnaire à l'index 'i' au nombre de conflit
		}
	}
	free(civil_servant_tab);										
	civil_servant_tab = NULL;
	return (float) conflict_number / (float) N;											// retourne le nombre de conflit
}

void delete_civil(char* name, char* surname,civil_servant ** table, unsigned int N)
{
	for (int i = 0; i<=N; i++) // index de la table à modifier
	{
		while(table[i]->name != NULL) 
		{
			if (table[i]->name == name && table[i]->surname == surname)
			{
				if (table[i]->next == NULL)
				{
					free(table[i]);
				}
				else
				{
					civil_servant * index = table[i];
					while(index->next->next != NULL)
					{
						index = index->next;
					}
					free(table[i]->next);
					table[i]->next = NULL;
				}
			}
		}
	}
}

void delete_civil_between(char* name, char* surname,int first_index, int end_index){
    
    
    
}

civil_servant* insert_end(civil_servant * civil, char* name, char* surname, unsigned int salary)
  {
      if(civil->next == NULL)
      {
          civil_servant* new_civil = malloc(sizeof(civil_servant));
          civil->next = new_civil;
          new_civil->next = NULL;
          new_civil->name = name;
          new_civil->surname = surname;
          new_civil->salary = salary;
          return new_civil;
      }
      else
      {
           insert_end(civil->next, name, surname, salary);
      }
	}

void load(int number_of_servant)
{
    int TAILLE_MAX = 1000;
    FILE* fichier = NULL;
    char chaine[TAILLE_MAX];
    char name[20] = {0};
    char surname[20] = {0};
    //civil_servant** table = create_table(100,83);
    
	
    fichier = fopen("chicago.txt", "r");
  //for (int i = 0; )
int tour = 0;
 
    if (fichier != NULL)
    {
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL && tour <3)  // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
                civil_servant * new_civil = malloc(sizeof(civil_servant));
                fscanf(fichier, "%s %s %u", name, surname, &new_civil->salary);
                new_civil->name = name;
                new_civil->surname = surname;
                new_civil->next = NULL;
               // printf("%s ", new_civil->name);
                //printf("%s \n", new_civil->surname);
                tour++;
printf("%d ", tour);
                //int i = index_calculator(name,surname, 83,100);
                int i = index_calculator(name, surname);
                printf(" %d \n", i);
                if (table[i] == NULL)
                {
                    table[i] = new_civil;
                }
                else
                {
                    table[i] = insert_end(table[i], name, surname, new_civil->salary);
                    
                }
                

        
                
            }
        }
  
        fclose(fichier);
                        for (int i =0; i<100; i++)
                {
                    if (table[i] == NULL)
                    {
                        
                    }
                    else
                    {
                        printf("%d ", i);
                         printf("%s %u \n", table[i]->name, table[i]->salary);
                    }
                   
                }
    }
    
    /*
     *  civil_servant * new_civil = malloc(sizeof(civil_servant));
    fichier = fopen("chicago.txt", "r");
 fscanf(fichier, "%s %s %u", name, surname, &new_civil->salary);
 new_civil->name = name;
 new_civil->surname = surname;
  printf("%s \n", new_civil->name);
  printf("%s \n", new_civil->surname);*/



