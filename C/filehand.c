#include <stdio.h>
#include <ctype.h>

int main(){


    FILE *fh;

    fh = fopen("hello.txt", "r");

    int vowel = 0;
    int Consonant = 0;

    char c = fgetc(fh);

    while(c != EOF){

        putchar(c);

        if(isalpha(c)){
            if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U'){
                vowel++;
            }else{
                Consonant++;
            }
        }
       c = fgetc(fh);
    }
    fclose(fh);

    printf("\nVowel: %d\n", vowel);
    printf("Consunant: %d\n", Consonant);

    return 0;
}