#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selectionSort(char *str, int len) {
    int min_idx;

    for (int i = 0; i < len - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < len; j++) {
            if (str[j] < str[min_idx]) {
                min_idx = j;
            }
        }
        if(min_idx != i) {
            char temp = str[i];
            str[i] = str[min_idx];
            str[min_idx] = temp;
        }
    }
}

int main() {
    char *str;
    int len;

    printf("Enter a string: ");
    scanf("%m[^\n]", &str); // %m[^\n] tells scanf to allocate memory for the string and include spaces in it

    len = strlen(str);
    selectionSort(str, len);

    printf("Sorted string: %s\n", str);

    free(str); // free the allocated memory

    return 0;
}

/*
Explanation:

We include necessary header files: stdio.h for input/output operations, stdlib.h for dynamic memory allocation, 
and string.h for string manipulation functions.

We define the selectionSort() function that takes a character array and its length as input, and sorts it using 
selection sort algorithm.

In the main() function, we declare a pointer variable str to hold the input string and an integer variable len to hold its length.

We prompt the user to enter a string using printf() and read it using scanf() with the %m[^\n] format specifier, 
which tells scanf() to allocate memory dynamically for the string and include spaces in it.

We get the length of the string using strlen() function.

We call the selectionSort() function with str and len as arguments to sort the string.

We print the sorted string using printf().

We free the memory allocated for the string using free() function to avoid memory leaks.

Note: The %m[^\n] format specifier is used to ensure that we allocate only the required amount of memory for the input string, 
and include spaces in it if any. It's important to free the allocated memory to avoid memory leaks.
*/