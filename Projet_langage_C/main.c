#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "table.h"

void menu()
{

    printf("\n\n---Menu---\n\n");
     printf("1.Index\n");
     printf("2.Ajout\n");
     printf("3.Charger\n");
     printf("4.Afficher Salaire\n");
     printf("5.Afficher Salaire Entre\n");
     printf("6.Nombre de conflits\n");
     printf("7.Conflits moyen \n");
     printf("8.supprimer\n");
     printf("9.Supprimer entre\n");
     printf("10.Quitter\n");
     printf("\nVotre choix?\n\n");
 
}

void affichage()
{
            for (int i =0; i< table.size;i++)
	{
        printf("------------ %d -------------\n", i);
		if (table.vecteur[i].content != NULL)
		{
			if (table.vecteur[i].content[0].name == NULL)
			{
              printf("rien à voir ici \n");
			}
			else
			{
            for (int j=0; j<table.vecteur[i].logic_size; j++)
            {
				printf("Name : %s ", table.vecteur[i].content[j].name);
				printf(" surname : %s ", table.vecteur[i].content[j].surname);
				printf(" salary : %d $ \n", table.vecteur[i].content[j].salary);
			}
            }
            }
            else
            {
                printf("Rien à l'index : %d\n", i);
            }
    
            }
    
}

int main(int argc, char **argv)
{
    table.size = 100;
    table.base = 83; 
    create_table();
    char nom[20] = {0};
    char prenom[20] = {0};
    int value;
    int salaire; 
    int choix;
    int first_index;
    int end_index;
    do
    {  
  
     printf("\n\n---Menu---\n\n");
     printf("1.Index\n");
     printf("2.Ajout\n");
     printf("3.Charger\n");
     printf("4.Afficher Salaire\n");
     printf("5.Afficher Salaire Entre\n");
     printf("6.Nombre de conflits\n");
     printf("7.Conflits moyen \n");
     printf("8.supprimer\n");
     printf("9.Supprimer entre\n");
     printf("10.Quitter\n");
     printf("\nVotre choix?\n\n");
    scanf("%d\n", &choix);
    switch(choix)
    {
        case 1:
           printf("1.Index\n");
           scanf("%d", &value);
            printf("Quel est votre nom ? ");
            scanf("%s", nom);
        printf("Quel est votre prenom ? ");
        scanf("%s", prenom);
        printf("le nom est %s et le prénom est %s\n", nom, prenom);
           int index_value = index_calculator(nom, prenom);
           printf("L'index vaut = %d", index_value);
            break;
        
        case 2:
             printf("2.Ajout\n");
        scanf("%d", &value);
        printf("Quel est votre nom ? ");
        scanf("%s", nom);
        printf("Quel est votre prenom ? ");
        scanf("%s", prenom);
        printf("Quel est votre salaire ? ");
        scanf("%d", &salaire);
        int eff = add(nom, prenom, salaire);
        if (eff == 1)
        {
              printf("Succès de l'ajout");
        }
        else
        {
            printf("Echec de l'ajout");
        }
        
            break;
        case 3:
            printf("3.Charger\n");
            scanf("%d", &value);
            printf("Quel est le nombre de fonctionnaire voulu ? ");
        scanf("%d", &value);
            load(value);
            break;
        case 4:
            printf("4.Afficher Salaire\n");
            scanf("%d", &value);
            printf("Quel est votre nom ? ");
            scanf("%s", nom);
            printf("Quel est votre prenom ? ");
            scanf("%s", prenom);
            show_salary(nom, prenom);
     printf("\n\nle salaire de %s %s est de %d $",prenom, nom, show_salary(nom, prenom));
            break;
        case 5:
            printf("5.Afficher Salaire Entre\n");
               scanf("%d", &value);
printf("Quel est l'index de début voulu ? ");
        scanf("%d", &first_index);
        printf("Quel est l'index de fin voulu ? ");
        scanf("%d", &end_index);
        show_salary_between(first_index, end_index);
            break;
            
        case 6:
              printf("6.Nombre de conflits\n");
   conflict();
            break;
        case 7 :
              printf("7.Conflits moyen \n");
average_conflict();
            break;
        case 8 : 
            printf("8.supprimer\n");
            scanf("%d", &value);
            printf("Quel est votre nom ? \n");
            scanf("%s", nom);
            printf("Quel est votre prenom ? \n");
            scanf("%s", prenom);
 bool effectue = delete_civil(nom, prenom);
 if (effectue == true)
 {
     printf("La suppression à bien eu lieu\n");
 }
 else
 {
     printf("La suppression n'a pas pu se faire\n");
 }
            break;
        case 9 : 
       
            printf("9.Supprimer entre\n");
              scanf("%d", &value);
        printf("Quel est l'index de début voulu ? ");
        scanf("%d", &first_index);
        printf("Quel est l'index de fin voulu ? ");
        scanf("%d", &end_index);
        delete_civil_between(first_index, end_index);
        break;
        case 10 :
         printf("10.Quitter\n");
         exit(-1);
        break;
        default: printf("ce choix n'existe pas !\n");
    } 
    } while(choix != 10);

    
    
	
    /*int index = index_calculator("AARON", "Kimberlei");
    int index2 = index_calculator("AARON", "Katrina");
	printf("%i\n", index);
	printf("%i\n", index2);*/
	
   
	//add("AARON", "Katrina", 10000);
//	add("AARON", "Katrinay", 12330);
//	add("AARON", "Katrinayjaja", 1300);
     
// add("ADEBAYO", "Benjamin", 1000);
// add("ADEBAYO", "Benjamin", 1000);
	//printf("%d\n", table.vecteur[77].content[0].salary);
//	printf("%d\n", table.vecteur[77].content[1].salary);
//	printf("%d\n", table.vecteur[77].content[2].salary);
  //printf("%s\n", table.vecteur[index].content[1].name);

    
	load(100000);
  
	for (int i =0; i< table.size;i++)
	{
        printf("------------ %d -------------\n", i);
		if (table.vecteur[i].content != NULL)
		{
			if (table.vecteur[i].content[0].name == NULL)
			{
              printf("rien à voir ici \n");
			}
			else
			{
            for (int j=0; j<table.vecteur[i].logic_size; j++)
            {
				printf("Name : %s ", table.vecteur[i].content[j].name);
				printf(" surname : %s ", table.vecteur[i].content[j].surname);
				printf(" salary : %d $ \n", table.vecteur[i].content[j].salary);
			}
            }
            }
            else
            {
                printf("Rien à l'index : %d\n", i);
            }
	
	}
    char * salary_name = "PROCHOT";
    char * salary_surname = "Kevin_B";
    
    printf("\n\nName : PROCHOT  surname : Kevin_B  (salary : 87384 $) : %d $", show_salary(salary_name, salary_surname)); 
  show_salary_between(90, 10000);
   //printf("%s\n", table.vecteur[index].content[table.vecteur[index].logic_size].surname);
   //printf("%d\n", table.vecteur[index].content[table.vecteur[index].logic_size].salary);
   conflict();
   average_conflict();
}
