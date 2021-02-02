#ifndef FANCY_ARRAY_H
#define FANCY_ARRAY_H

#include <stdint.h>

typedef struct element fancy_element;
typedef struct fancy_array fancy_array;

fancy_array * fancy_create();
int fancy_add(fancy_array * array, void * data, size_t size_bytes);
int fancy_delete_value(fancy_array * array, void * value);
int fancy_delete_index(fancy_array * array, unsigned long int index);
void fancy_dump(fancy_array * array);
void * fancy_get(fancy_array * array, unsigned long int index);
unsigned long int fancy_size(fancy_array * array);
int fancy_insert(fancy_array * array, void * data, unsigned long int afterIndex);
void fancy_free(fancy_array * array);

#endif