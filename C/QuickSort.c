#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char arr[], int low, int high) {
    char pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(char arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    char *str = (char *)malloc(sizeof(char) * 100);
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }
    quicksort(str, 0, len - 1);
    printf("Sorted string: %s\n", str);
    free(str);
    return 0;
}

/*
Here's an explanation of the code:

swap function swaps two characters in the array
partition function selects a pivot element from the array and partitions the array around the pivot such that all the elements before the pivot
are smaller than it and all the elements after it are greater than it quicksort function is a recursive function that calls partition to partition 
the array and then calls itself on the left and right sub-arrays In the main function, we first allocate memory for the string using malloc. 
We then read the string from the user using fgets, remove the newline character from the end (if it exists), call quicksort on the string to sort it, 
and finally print the sorted string. We also free the memory allocated for the string using free.

Note that this program assumes that the input string is a null-terminated character array with a maximum length of 100 characters. 
If you need to handle longer strings, you will need to adjust the code accordingly.
*/

