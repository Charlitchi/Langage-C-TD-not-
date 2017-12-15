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
