#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "table.h"
int main(int argc, char **argv)
{
	
    /*table.size = 100;
    table.base = 83;
    int index = index_calculator("AARON", "Katrina");
    create_table();
add("AARON", "Katrina", 100);
printf("\n%d", table.vecteur[index].content->salary);
printf("\n%s", table.vecteur[index].content->name);*/

/*civil_servant * c = create_civil_servant("JAJA", "Guigui", 2500);
civil_servant * c2 = create_civil_servant("JAJA", "Angeline", 659);
civil_servant * c3 = civil_servant_sort(c, c2);
printf("Le premier fonctionnaire est  : %s %s de salaire : %i, son pointeur vaut : %p\n", c->name, c->surname, c->salary, c);
printf("Le premier fonctionnaire est  : %s %s de salaire : %i, son pointeur vaut : %p\n", c2->name, c2->surname, c2->salary, c2);
printf("\nAlphabetiquement parlant, le permier fonctionnaire est : %s %s\n", c3->name, c3->surname);

free(c);
free(c2);*/

	table.size = 100;
	//printf("La taille	de la table est : %i\n", table.size);
	table.base = 83;
	//printf("La base	 de la table est : %i\n", table.size);
	create_table();
	//add("AARON","Katrina", 1500);
	//printf("Bonjour\n");
    load(1000);
for (int i =0; i< table.size;i++)
  {
      
      if (table.vecteur[i].content!= NULL)
      {
          printf("\n ------------------ %d : ", i);
          for (int j=0; j<table.vecteur[i].logic_size;j++)
          {
              if( table.vecteur[i].content[j].name != NULL)
              {
            printf("\n %d : %s", j, table.vecteur[i].content[j].name); 
            printf("\n %d : %s", j, table.vecteur[i].content[j].surname); 
            printf("\n %d : %d", j, table.vecteur[i].content[j].salary); 
              }
          }

      }
      else
      {
        printf("\n Rien à l'index : %d", i);

      }
  
    }
    
    printf("\n ------------------------------------ \n");
    char* name_test = "BROWNRIDGE";
    char* surname_test = "John_M";
    
 int salary_value = show_salary(name_test,surname_test);
 printf("\n \n \nVoici le salaire de BROWNRIDGE John_M(il est de 98016 dans le fichier) : %u", salary_value);
    
    show_salary_between(-332, 10);
    conflict();
    average_conflict();
return 0; 
 }
  

