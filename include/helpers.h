#ifndef HELPERS_H
#define HELPERS_H

#include <string.h>
#include <assert.h>
#include<stdlib.h>

typedef struct Person
{
    int age;
    char* name;
} Person;

char** str_split(char* a_str, const char a_delim);
Person* create_person_array(int size);

#endif // !HELPERS_H

