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
void add(char* name, char* surname, unsigned int salary);
void load(int number_of_servant);
int show_salary(char* name, char* surname);
int show_salary_between(int first_index, int end_index);
int conflict();
int average_conflict();
void delete_civil(char* name, char* surname);
void delete_civil_between(char* name, char* surname,int first_index, int end_index);
void leave();
civil_servant** create_table(unsigned int size_table, unsigned int base);







#endif
