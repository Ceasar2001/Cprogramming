#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cutname();
void printname();

int main() {
    char name[] = "ceasar ian ecleo";
    
    cutname(name);

    return 0;
}

void cutname(char *name){
    int fullname = strlen(name);
    char *firstname = (char *)malloc(fullname * sizeof(char));
    char *space = strchr(name, ' ');

    if(space != NULL){
        int fname = space - name;
        firstname = (char *)realloc(firstname, (fname) * sizeof(char));
        strncpy(firstname, name, fname);
        firstname[fname] = '\0';

    }
    printname(firstname);
}

void printname(char *name){
    printf("%s", name);
}