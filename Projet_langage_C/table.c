#include "table.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int power(int number, int power)
{
	int result_power = 1;
	for (int i = 1; i <= power; i++)
	{
		result_power *= number;
	}
	return result_power;
}

int index_calculator(char* name, char* surname, unsigned int base, unsigned int N)
{
	unsigned long long sum = 0;
	char* name_to_use = malloc(7*sizeof(char));
	name_to_use[6] = '\0';
	int misc = 0;
	for (int i = 0; i < 4; i++)
	{
		if(name[i] != '_')	{ name_to_use[i] = name[i]; }
		else { misc++; name_to_use[i] = name[i+misc]; }
		printf("%s\n", name_to_use);
	}
	misc = 0;
	for (int i = 0; i < 2; i++)
	{
		if(surname[i] != '_')	{ name_to_use[4+i] = surname[i]; }
		else { misc++; name_to_use[4+i] = surname[i + misc]; }
		printf("%s\n", name_to_use);
	}
	printf("%s\n", name_to_use);
	for (int i = 0; name_to_use[i] != '\0'; i++)
	{
		sum += name_to_use[i]*power(base, i);
	}
	sum %= N;
	free(name_to_use);
	name_to_use = NULL;
	return (int) sum;
}

civil_servant** create_table(unsigned int size_table, unsigned int base)
{
	civil_servant * * const table = malloc(size_table*sizeof(civil_servant));
	for(int i = 0; i < size_table; i++) { table[i] = NULL; }
	return table;
}
