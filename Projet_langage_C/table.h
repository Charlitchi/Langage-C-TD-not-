
#include <stdbool.h>
#ifndef TABLE_H

#define TABLE_H

typedef struct _civil_servant 

{
    char *surname;
    
	unsigned int salary;

	char * name ;
    

} civil_servant ;

typedef struct _type_vector
{
    unsigned int logic_size;
    unsigned int physical_size;
    civil_servant *content;
    
}type_vector;


typedef struct _type_table
{
    unsigned int size;
    unsigned int base;
    type_vector * vecteur;
    
}type_table;

type_table table;
 
 

int index_calculator(char* name, char* surname);	     
unsigned long long power (int number, int power);									        
int add(char* name, char* surname, unsigned int salary); // Il faut calculer l'index en dehors et chercher le dernier civil_servant associé à cet index.
void load(int number_of_servant);
int show_salary(char* name, char* surname); // OK
void show_salary_between(int first_index, int end_index);      // OK
void salary(civil_servant * civil);                                                  // OK
int* civil_servant_number_by_index(civil_servant ** table); 						    // OK
void conflict();  												// OK
void average_conflict();  									   // OK
bool delete_civil(char* value_name, char* value_surname); 
void delete_civil_between(unsigned int first_index, unsigned int end_index);
void leave();
//civil_servant** create_table(unsigned int size_table, unsigned int base);
void create_table();
civil_servant* insert_end(civil_servant * civil, char* name, char* surname, unsigned int salary);// ok


#endif
