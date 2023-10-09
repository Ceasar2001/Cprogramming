#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quicksort(char *arr, int low, int high);

int main()
{
    char *str = NULL;
    int len = 0;
    printf("Enter a string: ");
    scanf("%m[^\n]", &str);
    len = strlen(str);
    quicksort(str, 0, len - 1);
    printf("Sorted string: %s\n", str);
    free(str);
    return 0;
}

void quicksort(char *arr, int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                char temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        char temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int pi = i + 1;
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
