#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quicksort(char* str, int left, int right);

int main() {

    printf("Enter a string: ");
    char str[100];
    fgets(str, 100, stdin);

    int len = strlen(str) - 1;

    char* str_dyn = (char*) malloc((len + 1) * sizeof(char));
    memcpy(str_dyn, str, len + 1);
    quicksort(str_dyn, 0, len - 1);
    str_dyn[len] = '\0';

    printf("Sorted string: %s\n", str_dyn);

    free(str_dyn);

    return 0;
}

void quicksort(char* str, int left, int right) {
    if (left >= right) {
        return;
    }
    char pivot = str[right];
    int i = left - 1;
    int j;
    for (j = left; j < right; j++) {
        if (str[j] < pivot) {
            i++;
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
    }
    char temp = str[i + 1];
    str[i + 1] = str[right];
    str[right] = temp;
    int mid = i + 1;
    quicksort(str, left, mid - 1);
    quicksort(str, mid + 1, right);
}