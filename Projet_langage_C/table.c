#include "table.h"

int power(int number, int power)
{
	int result_power = 1;
	for (int i = 1; i <= power; i++)
	{
		result_power *= number;
	}
	return result_power;
}

int index(char* name, char* surname, unsigned int base, unsigned int N)
{
	int sum = 0;
	char* name_to_use = malloc(7*sizeof(char));
	name_to_use[6] = '\0';
	for (int i = 0; i < 4; i++)
	{
		if(name[i] != '_')	{ name_to_use[i] = name[i]; }
		else { name_to_use[i] = name[i+1]; }
	}
	for (int i = 0; i < 2; i++)
	{
		if(surname[i] != '_')	{ name_to_use[i] = surname[i]; }
		else { name_to_use[4+i] = surname[i+1]; }
	}
	printf("%s\n", name_to_use);
	for (int i = 0; name_to_use[i] != '\0'; i++)
	{
		sum += name_to_use[i]*power(base, i);
	}
	sum %= N;
	return sum;
}