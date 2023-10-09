#include <stdio.h>
#include <stdlib.h>
#include <string.h>


   typedef struct{
        float f;
        char name[10]; 
    }Wombat;


int main(){

    Wombat p = {2.13, "the doctor"};

    printf("%s", p.name);
    printf("\n%.2f", p.f);

    return 0;
}