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
    load(3);
for (int i =0; i< table.size;i++)
  {
      if (table.vecteur[i].content!= NULL)
      {
          printf("\n %d : %s", i, table.vecteur[i].content[0].name);
      }
      else
      {
        printf("\n Rien à l'index : %d", i);

      }
  
    }
return 0; 
 }
  

