
#include <stdbool.h>
#ifndef TABLE_H

#define TABLE_H

typedef struct _civil_servant 

{
	char * surname;
    
	unsigned int salary;

	char * name;
} civil_servant ;

typedef struct _type_vector
{
    unsigned int logic_size;
    unsigned int physical_size;
    civil_servant * content;
    
}type_vector;


typedef struct _type_table
{
    unsigned int size;
    unsigned int base;
    type_vector * vecteur;
    
}type_table;

type_table table;
 
 

//int index_calculator(char* name, char* surname, unsigned int base,unsigned int N);	     // OK
int index_calculator(char* name, char* surname);	     
unsigned long long power (int number, int power);									        
void add(char* name, char* surname, unsigned int salary); //OK
void load(int number_of_servant);  //OK
int show_salary(char* name, char* surname);                     // OK
void show_salary_between(int first_index, int end_index);      // OK
void salary(civil_servant * civil);                                                  // OK
int* civil_servant_number_by_index(civil_servant ** table); 						    // OK
int conflict(civil_servant ** table);  												
float average_conflict(civil_servant ** table);  									   
void delete_civil(char* name, char* surname,civil_servant ** table, unsigned int N); 
void delete_civil_between(char* name, char* surname,int first_index, int end_index);
void leave();
//civil_servant** create_table(unsigned int size_table, unsigned int base);
void create_table();
civil_servant* insert_end(civil_servant * civil, char* name, char* surname, unsigned int salary);// ok





civil_servant * create_civil_servant(char* name, char* surname, unsigned int salary);
civil_servant * civil_servant_sort(civil_servant * civil1, civil_servant * civil2);
void put_civil_servant(civil_servant * new_civil_servant, int index_table, int index_vecteur);
void civil_servant_tri(type_table * table_civil);
#endif
