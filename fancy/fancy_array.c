#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fancy_array.h"

struct element{
    void * data;
};
struct fancy_array{
    fancy_element * head;
    unsigned long int size;
};
/**
 * @brief creates an array and a reference to it
 * 
 * @return fancy_array* a pointer to the structure created contains all the data to hold the array
 */
fancy_array * fancy_create(){
    fancy_array * ar = (fancy_array *) malloc(sizeof(fancy_array));
    ar->head = NULL;
    ar->size = 0;
    return ar;
}
/**
 * @brief adds an element to the end of the array
 * 
 * @param array : array to add to it
 * @param data : a void poitner to thedata that can be casted to any type
 * @param size_bytes : number of size bytes of the data passed in
 * @return int : 1 if succeeded else 0
 */
int fancy_add(fancy_array * array, void * data, size_t size_bytes){

    if(array->head == NULL && array->size == 0){
        array->head = (fancy_element*) malloc(sizeof(fancy_element)); 
        if(array->head == NULL){
            printf("first Malloc: failed!\n");
            return 0;
        }
        array->size++;
        array->head->data = malloc(size_bytes); // we allocate the new memory before dest
        memcpy(array->head->data, data, size_bytes); //copy the memory
        return 1;
    }
    array->size++;
    array->head = (fancy_element*) realloc(array->head, sizeof(fancy_element) * array->size);
    (array->head+array->size-1)->data = malloc(size_bytes);
    (array->head+array->size-1)->data = memcpy((array->head+array->size-1)->data, data, size_bytes);
    if(array->head == NULL) {
        return 0; //detect if realloc failed
        printf("Realloc: failed!\n");
    }
    return 1;
}
/**
 * @brief this function is used only for debugging
 * initaially dump function will show a pointer of 
    * arrays so if u want to see your actual data 
    * just modify the code by casting it to your appropriate
    * type like: *(type*)p 
 * @param array : the array to show 
 */
void fancy_dump(fancy_array * array){
    int i=0;
    printf("*************************\n");
    printf("SIZE: %ld\n", array->size);
    for(i =0; i<=array->size-1; i++){
        void *  p = (array->head+i)->data;
        printf("index: %d, value: %p\n", i, p);
    }
}

void * fancy_get(fancy_array * array, unsigned long int index){
    if(index >= array->size){
        return NULL;
    }
    return array->head[index].data;
}