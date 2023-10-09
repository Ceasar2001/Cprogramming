#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){


    FILE *file;

    file = fopen("hello.txt", "r");

    char c = fgetc(file);

    while(c != EOF){
        putchar(c);
        c = fgetc(file);
    }

    fclose(file);


//this code down here will write and read on different file name
    char str[100];
    printf("\nenter a string: ");
    scanf("%[^\n]s", str);


    file = fopen("files.txt", "w+");

    fprintf(file, "%s", str);

    fclose(file);

    file = fopen("files.txt", "r");

    char s = fgetc(file);

    while(s != EOF){
        putchar(s);
        s = fgetc(file);
    }

    fclose(file);

    rename("files.txt", "file1.txt");

   return 0;
}
    /*
    
    char str[100];
    printf("enter a string: ");
    scanf("%[^\n]s", str);

    FILE *file;

    file = fopen("hello.txt", "w");

    fprintf(file, "%s", str);

    fclose(file);

    printf("\n");

    file = fopen("hello.txt", "r");

    char c = fgetc(file);

    while(c != EOF){
        putchar(c);
        c = fgetc(file);
    }

    fclose(file);

    */