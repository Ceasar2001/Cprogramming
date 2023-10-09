#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble_sort(char *arr, int n);

int main(){
    // Allocate memory for input string
    char *str = (char *)malloc(sizeof(char) * 100);
    
    // Get user input string
    printf("Enter a string: ");
    scanf("%s", &str);
    //fgets(str, 100, stdin);
    
    // Remove spaces from string
    int j;
    for (int i = 0, j = 0; i < strlen(str); i++) {
        if(str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
    
    bubble_sort(str, strlen(str));
    
    printf("Sorted string: %s", str);
    
    free(str);
    return 0;
}

void bubble_sort(char *arr, int n){
    char temp;

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}