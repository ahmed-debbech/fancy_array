#include <stdlib.h>
#include <stdio.h>
#include "fancy_array.h"
#include "fancy_array.c" 

int main(){
    fancy_array * arr = fancy_create();
    FILE * f = fopen("in.txt", "r");
    if(f != NULL){
        char str[100];
        while (fgets(str, 100, f) != NULL){
            int k= atoi(str);
            printf("ll : %d\n", k);
            fancy_add(arr, &k, sizeof(int));
        }
        fclose(f);
    }
    fancy_dump(arr);
    return 0;
}