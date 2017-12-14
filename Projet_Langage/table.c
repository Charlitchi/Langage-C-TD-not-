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
if (tour <10)
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