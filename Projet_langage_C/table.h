#ifndef TABLE_H

#define TABLE_H

typedef struct _civil_servant 

{
    char *surname
    
	unsigned int salary;

	char * name;
    
    struct _civil_servant * next;

} civil_servant ;





int index(char* name, char* surname, unsigned int base, unsigned int N);
int power (int number, int power);
void add(char* name, char* surname, unsigned int salary);
void load();










#endif