#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selection_sort(char *arr, int n);

int main() {
    char *str;
    int n;

    printf("Enter a string: ");
    scanf("%m[^\n]", &str); // Using %m to allocate memory dynamically for the string

    n = strlen(str);
    char *new_str = (char *) malloc((n+1) * sizeof(char)); // Allocating memory for the sorted string

    strcpy(new_str, str); // Copying the original string to the new string
    free(str); // Freeing the dynamically allocated memory for the original string

    selection_sort(new_str, n);

    printf("Sorted string: %s\n", new_str);

    free(new_str);// Freeing the dynamically allocated memory for the sorted string

    return 0;
}

void selection_sort(char *arr, int n) {
    int i, j, min_idx;

    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (*(arr+j) < *(arr+min_idx))
                min_idx = j;
        }
        if (min_idx != i) {
            char temp = *(arr+i);
            *(arr+i) = *(arr+min_idx);
            *(arr+min_idx) = temp;
        }
    }
}

/*The code sorts the input string "ceasar ian" using selection sort algorithm. Here's how the sorting process works:

The user is prompted to enter a string. The input is stored in the variable str as a dynamically allocated string using %m in the scanf() function.

The length of the input string is obtained using strlen() function and stored in the variable n.

A new dynamically allocated character array new_str is created with a size of n+1 to store the sorted string.

The original string str is copied to new_str using strcpy() function.

The dynamically allocated memory for the original string str is freed using free() function.

The selection_sort() function is called with parameters new_str and n.

The selection_sort() function implements selection sort algorithm to sort the characters in the new_str array. Selection sort works by selecting the minimum element from the unsorted part of the array and swapping it with the first element of the unsorted part.

After the sorting process is complete, the sorted string is printed on the screen using printf() function.

The dynamically allocated memory for the sorted string new_str is freed using free() function.

The program terminates.*/




/*
This is a C program that takes input of a string from the user, sorts it in lexicographical order using selection sort algorithm and then prints the sorted string.

Let's go through the code line by line:

#include <stdio.h> - This line includes the standard input/output library.
#include <stdlib.h> - This line includes the standard library, which includes functions for memory allocation, conversion, and other general purpose functions.
#include <string.h> - This line includes the string library, which includes functions for string manipulation.
void selection_sort(char *arr, int n); - This line declares the function selection_sort, which takes a char array pointer arr and an integer n as arguments, and returns nothing (void).
int main() { - This line starts the main function of the program.
char *str; - This line declares a character pointer str.
int n; - This line declares an integer variable n.
printf("Enter a string: "); - This line prints the message "Enter a string: " to the console.
scanf("%m[^\n]", &str); - This line reads a string from the user and stores it in the memory allocated by the system. %m[^\n] is used to read the string from the user and allocate memory dynamically. The & operator is used to get the address of the pointer variable str.
n = strlen(str); - This line calculates the length of the string str and stores it in the variable n.
char *new_str = (char *) malloc((n+1) * sizeof(char)); - This line dynamically allocates memory of size n+1 to the pointer new_str, which is used to store the sorted string. sizeof(char) is used to get the size of the character data type.
strcpy(new_str, str); - This line copies the contents of str to new_str.
free(str); - This line frees the memory allocated to str.
selection_sort(new_str, n); - This line calls the selection_sort function to sort the string new_str.
printf("Sorted string: %s\n", new_str); - This line prints the sorted string to the console.
free(new_str); - This line frees the memory allocated to new_str.
return 0; - This line ends the main function and returns 0 to indicate successful execution of the program.
void selection_sort(char *arr, int n) { - This line starts the definition of the selection_sort function, which takes a char array pointer arr and an integer n as arguments and returns nothing (void).
int i, j, min_idx; - This line declares three integer variables i, j, and min_idx.
for (i = 0; i < n-1; i++) { - This line starts a for loop which runs n-1 times, where n is the length of the string.
min_idx = i; - This line sets the value of min_idx to i.
for (j = i+1; j < n; j++) { - This line starts a nested for loop which runs from i+1 to n-1.
`if (*(arr+j) <
*/