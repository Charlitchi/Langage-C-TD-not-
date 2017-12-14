#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "table.h"
int main(int argc, char **argv)
{
    table.size = 100;
    table.base = 83;
  //  int index = index_calculator("AARON", "Kimberlei");
    create_table();
  //  add("AARON", "Kimberlei", 1000);
// add("ADEBAYO", "Benjamin", 1000);
// add("ADEBAYO", "Benjamin", 1000);
  // printf("%s\n", table.vecteur[index].content[0].name);
  //printf("%s\n", table.vecteur[index].content[1].name);
 load(3);
  
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
  }
  
   //printf("%s\n", table.vecteur[index].content[table.vecteur[index].logic_size].surname);
   //printf("%d\n", table.vecteur[index].content[table.vecteur[index].logic_size].salary);
}
