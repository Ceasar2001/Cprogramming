#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr;
    int size;

    printf("Enter the number of integers you want to allocate: ");
    scanf("%s", &size);

    // allocate memory dynamically using malloc()
    ptr = (char *) malloc(size * sizeof(char));

    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Memory allocated successfully\n");
    printf("Size of the allocated memory: %d bytes\n", size * sizeof(int));

    // free the allocated memory
    free(ptr);

    return 0;
}