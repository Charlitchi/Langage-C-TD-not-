#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "table.h"
int main(int argc, char **argv)
{
	table.size = 100;
    table.base = 83;
    /*int index = index_calculator("AARON", "Kimberlei");
    int index2 = index_calculator("AARON", "Katrina");
	printf("%i\n", index);
	printf("%i\n", index2);*/
	
    create_table();
    
	add("AARON", "Katrina", 1000);
	add("AARON", "Katrinay", 1000);
	add("AARON", "Katrinayjaja", 1000);
// add("ADEBAYO", "Benjamin", 1000);
// add("ADEBAYO", "Benjamin", 1000);
	printf("%s\n", table.vecteur[77].content[0].surname);
	printf("%s\n", table.vecteur[77].content[1].surname);
	printf("%s\n", table.vecteur[77].content[2].surname);
  //printf("%s\n", table.vecteur[index].content[1].name);
	
	//load(3);
  /*
	for (int i =0; i< table.size;i++)
	{
		if (table.vecteur[i].content != NULL)
		{
			if (table.vecteur[i].content[0].name == NULL)
			{
              
			}
			else
			{
            
				printf("\n %d : %s \n", i, table.vecteur[i].content[0].name);
			}
	}
	}*/
  
   //printf("%s\n", table.vecteur[index].content[table.vecteur[index].logic_size].surname);
   //printf("%d\n", table.vecteur[index].content[table.vecteur[index].logic_size].salary);
}
