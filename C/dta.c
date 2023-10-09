#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cutName();
void printName();

int main(){

    char Name[] = "CEASAR IAN I. ECLEO";

    cutName(Name);
}

void cutName(char *Name){
    int fullNameLength = strlen(Name);
    char *firstName = (char *)malloc(fullNameLength * sizeof(char));
    char *space = strchr(Name, ' ');

    if (space != NULL){
        int fNameLenght = space - Name;
        firstName = (char *)realloc(firstName, (fNameLenght) * sizeof(char));
        strncpy(firstName, Name, fNameLenght);
        firstName[fNameLenght] = '\0';
    }

    printName(firstName);
}

void printName(char *firstName){
    printf("%s", firstName);
}