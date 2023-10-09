#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cutname();
void printName();

int main(){

    char name[] = "Ceasar Ian I. Ecleo";
   
    cutname(name);

    return 0;
}

void cutname(char *name){
    int fullname = strlen(name);
    char *firstname = (char *)malloc(fullname * sizeof(char));
    char *space = strchr(name, ' ');

    if(space != NULL){
        int fnameSize = space - name;
        firstname = (char *)realloc(firstname, (fnameSize) * sizeof(char));
        strncpy(firstname, name, fnameSize);
        firstname[fnameSize] = '\0';
    }
    printName(firstname);
}

void printName(char * firstname){
    printf("%s", firstname);
}

