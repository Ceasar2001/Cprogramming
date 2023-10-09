#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quicksort(char* str, int left, int right);

int main() {
    // Read input string from user
    printf("Enter a string: ");
    char str[100];
    fgets(str, 100, stdin);

    // Compute length of input string (excluding newline character)
    int len = strlen(str) - 1;

    // Remove newline character from input string
    if (str[len] == '\n') {
        str[len] = '\0';
        len--;
    }

    // Allocate memory dynamically for the string
    char* str_dyn = (char*) malloc((len + 1) * sizeof(char));

    // Copy input string to dynamically allocated memory (including space characters)
    memcpy(str_dyn, str, len + 1);

    // Sort the string using quicksort
    quicksort(str_dyn, 0, len - 1);

    // Print the sorted string
    printf("Sorted string: %s\n", str_dyn);

    // Free dynamically allocated memory
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

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quicksort(char* str, int left, int right);

int main() {
    // Read input string from user
    printf("Enter a string: ");
    char str[100];
    fgets(str, 100, stdin);

    // Compute length of input string (excluding newline character)
    int len = strlen(str) - 1;

    // Remove newline character from input string
    if (str[len] == '\n') {
        str[len] = '\0';
        len--;
    }

    // Allocate memory dynamically for the string
    char* str_dyn = (char*) malloc((len + 1) * sizeof(char));

    // Copy input string to dynamically allocated memory (including space characters)
    memcpy(str_dyn, str, len + 1);

    // Sort the string using quicksort
    quicksort(str_dyn, 0, len - 1);

    // Print the sorted string
    printf("Sorted string: %s\n", str_dyn);

    // Free dynamically allocated memory
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
*/


/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quicksort(char* str, int left, int right);

int main() {
    // Read input string from user
    printf("Enter a string: ");
    char str[100];
    fgets(str, 100, stdin);

    // Compute length of input string (excluding newline character)
    int len = strlen(str) - 1;

    // Allocate memory dynamically for the string
    char* str_dyn = (char*) malloc((len + 1) * sizeof(char));

    // Copy input string to dynamically allocated memory (including space characters)
    memcpy(str_dyn, str, len + 1);

    // Sort the string using quicksort
    quicksort(str_dyn, 0, len - 1);

    // Print the sorted string
    printf("Sorted string: %s", str_dyn);

    // Free dynamically allocated memory
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
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quickSort(char *arr, int low, int high);

int main() {
    char *string;
    int n;

    // Get the input string from the user
    printf("Enter a string: ");
    fgets("%[^\n]%*c", string);

    // Calculate the length of the string
    n = strlen(string);

    // Allocate memory for the string
    string = (char *) malloc((n + 1) * sizeof(char));

    // Get the input string again, this time using fgets to include spaces
    printf("Enter a string: ");
    fgets(string, n+1, stdin);

    // Sort the string using quick sort
    quickSort(string, 0, n-1);

    // Print the sorted string
    printf("Sorted string: %s\n", string);

    // Free the memory allocated for the string
    free(string);

    return 0;
}

void quickSort(char *arr, int low, int high) {
    if (low < high) {
        // Choose pivot as the last element of the array
        char pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] <= pivot) {
                i++;
                // Swap arr[i] and arr[j]
                char temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        // Swap arr[i+1] and arr[high]
        char temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;

        // Recursively sort the partitions
        quickSort(arr, low, i);
        quickSort(arr, i+2, high);
    }
}
*/