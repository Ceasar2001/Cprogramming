#include <stdio.h>
#include <stdbool.h>

int main(){

    FILE *fh;

    fh = fopen("files.txt", "w");

    int input = 0;
    while(true){
        printf("Enter : ");
        scanf("%d", &input);

        if(input == -1)break;
        else fprintf(fh, "%d\n", input);
    }

/*
    for(int i = 0; i < 10; i++){
        fprintf(fh, "%d\n", i);
    }
*/
    fclose(fh);

   // FILE *fh;
    fh = fopen("files.txt", "r");

    int finput = 0;
    int lines = 0;
    int number[100];

    while(fscanf(fh, "%d", &finput) != EOF){
        number[lines] = fh;
        printf("file line %d: %d\n", lines+1, finput);
        lines++;
    }

    int total = 0;
    for(int i = 0; i < lines; i++)
        total += number[i];
        printf("Average: %d\n", total / lines);

    fclose(fh);    

    fh = fopen("hello.txt", "r");

    char buffer[256];

    fgets(buffer, 256, fh);
    printf("buffer: %s\n", buffer);

    fclose(fh);

    return 0;
}