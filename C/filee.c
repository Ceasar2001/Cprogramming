#include <stdio.h>
#include <ctype.h>

int main() {

  FILE *fp = fopen("hello.txt", "r");

  int vowel= 0, consonant= 0, length = 0;

  char c = fgetc(fp);
  while (c != EOF) {

    putchar(c);//kani siya ang mag butang sa kada isa ka character output mo undang na siya kong ang 
               //while loop nato nga condtion kay mo stop na kibali ang while mo equal na sa EOF

    if (isalpha(c)) {//mao ni mag tanaw sa kada character kong vowel ba or dili
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
          c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        vowel++;//diri mag ihap kong pila ka vowel ang naa sa sentence
      } else {
        consonant++;//kong dili vowel syempre e consedir nga consonant simple
      }
      length++;//dire pod pag ihap kong pila ka character ang naa sa sentence way labot special sign og blank space
    }

    c = fgetc(fp);//kani mao ni mag kuha sa kaha character solod sa file
  }

  fclose(fp);

  printf("\nvowels: %d\n", vowel);
  printf("Consonants: %d\n", consonant);
  printf("Length: %d\n", length);

  return 0;
}