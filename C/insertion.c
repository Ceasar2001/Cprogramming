#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void insertion_sort(char* str, int len)
{
    int i, j;
    char key;

    for (i = 1; i < len; i++) {
        key = str[i];
        j = i - 1;

        while (j >= 0 && str[j] > key) {
            str[j+1] = str[j];
            j--;
        }

        str[j+1] = key;
    }
}

int main(){
    char *str, *new_str;
    int len, i, j;

    // Allocate memory for the string
    printf("Enter a string: ");
    scanf("%m[^\n]", &str);
    len = strlen(str);

    // Remove spaces from the string
    new_str = (char*)malloc((len+1) * sizeof(char));
    j = 0;
    for (i = 0; i < len; i++) {
        if (!isspace(str[i])) {
            new_str[j] = str[i];
            j++;
        }
    }
    new_str[j] = '\0';
    free(str); // Free the memory allocated for the original string

    // Sort the string using insertion sort
    insertion_sort(new_str, strlen(new_str));
    printf("Sorted string: %s\n", new_str);

    // Free the memory allocated for the new string
    free(new_str);

    return 0;
}
