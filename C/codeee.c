#include <stdio.h>
#include <conio.h>
#include <string.h>

int main() {
   
    FILE *fp;
    //fputc(character, file_pointer);- write character by character to a file
    //fputs(string, file_pointer); - write a string to a file
    //fprintf(file_pointer, "format specifier", list of variables); - 
    //fgetc(file_pointer); - use to print all the data inside the file
    //fscanf(file_pointer, "format string", list of address of variables); - used to read the input from the file
    int age;

    fp = fopen("files.txt", "r");

    if(fp == NULL){
        printf("file empty");
    }else{
        fscanf(fp, "%d", age);
        printf("data inside file: %d", age);
    }

    fclose(fp);

    return 0;
}
//

//write string to a files
/*
char input[25];


    fp = fopen("files.txt", "w");

    if(fp == NULL){
        printf("file error");
    }else{
        printf("enter a string: ");
        gets(input);
        fputs(input, fp);
        printf("data has entered\n");
    }
*/


//write data to a file
/*
char name[50];
    int age;

    printf("enter name: ");
    scanf("%[^\n]s", &name);
    //gets(name);

    printf("enter age: ");
    scanf("%d", &age);

    fp = fopen("files.txt", "w");

    if(fp == NULL){
        printf("file error");
    }else{
        fprintf(fp, "%s\t%d", name, age);
        printf("data is good");
    }
*/ 

//to print the data inside the file into the terminal
/*
char ch;

    fp = fopen("files.txt", "r");

    if(fp == NULL){
        printf("file empty");
    }else{
        while(!feof(fp)){
            ch = fgetc(fp);
            printf("%c", ch);
        }
        printf("\ndata is good");
    }
*/ 

