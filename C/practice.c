#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
 
  FILE *fp;
  char name[100];

  printf("enter name: ");
  gets(name);

  fp = fopen("files.txt", "w+");

  fputs(name, fp);


  fclose(fp);


  fp = fopen("files.txt", "r");

  int vowel_count = 0, consonant_count = 0;
  char sentence[256];
  
  fgets(sentence, 256, fp);
 
  int length = strlen(sentence);
  
  for (int i = 0; i < length; i++) {
    char c = tolower(sentence[i]);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
       vowel_count++;
     }else if (isalpha(c)) {
      consonant_count++;
    }
  }
  
  printf("Sentence  : %s\n", sentence);
  printf("Vowels    : %d\n", vowel_count);
  printf("Consonants: %d\n", consonant_count);
  printf("Length    : %d\n", length);

  fclose(fp);
  
  return 0;
}