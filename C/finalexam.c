#include <stdio.h>
#include <string.h>

    struct wombat{
        float f;
        char name[10];
    };


int main(){

    struct wombat manroa = {7, "ceasar ian"};
    
    printf("float value: %.2f\n", manroa.f);
    printf("name value: %s\n", manroa.name);


    return 0;
}
