#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "table.h"
int main(int argc, char **argv)
{
    table.size = 100;
    table.base = 83;
    int index = index_calculator("AARON", "Katrina");
    create_table();
add("AARON", "Katrina", 100);
printf("\n%d", table.vecteur[index].content->salary);
printf("\n%s", table.vecteur[index].content->name);
	return 0;
}
