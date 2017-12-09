#ifndef TABLE_H

#define TABLE_H

typedef struct _civil_servant 

{
    char *surname;
    
	unsigned int salary;

	char * name;
    
    struct _civil_servant * next;

} civil_servant ;




int index_calculator(char* name, char* surname, unsigned int base,unsigned int N);
unsigned long long power (int number, int power);
void add(char* name, char* surname, unsigned int salary, civil_servant* civil); // Il faut calculer l'index en dehors et chercher le dernier civil_servant associé à cet index.
void load(int number_of_servant);
int show_salary(char* name, char* surname, civil_servant * civil);
int show_salary_between(int first_index, int end_index, civil_servant ** table);
int conflict();
int average_conflict();
void delete_civil(char* name, char* surname,civil_servant ** table );
void delete_civil_between(char* name, char* surname,int first_index, int end_index);
void leave();
civil_servant** create_table(unsigned int size_table, unsigned int base);







#endif
