#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertion_sort(char *arr, int n) {
    int j, i;
    char temp;

    for(i = 1; i < n; i++) {
        temp = *(arr + i);
        j = i - 1;
        while (j >= 0 && *(arr + j) > temp) {
            *(arr + j + 1) = *(arr + j);
            j = j - 1;
        }
        *(arr + j + 1) = temp;
    }
}

int main() {
    char *str, *sorted_str;
    int len;

    printf("Enter a string: ");
    scanf("%[^\n]%*c", str);//"%[^\n]%*c" pangpa tangal sa space

    len = strlen(str);//length sa string
    sorted_str = (char *)malloc((len + 1) * sizeof(char));//malloc 

    if (sorted_str == NULL) {
        printf("Failed to allocate memory.\n");
        return 1;
    }
    
    strcpy(sorted_str, str);//copy sa string

    insertion_sort(sorted_str, len);//function sa taas

    printf("Sorted string: %s\n", sorted_str);//e print

    free(sorted_str);//e free ang memory

    return 0;
}