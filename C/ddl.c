#include <stdio.h>

int main(){
    char sorted[10];
    char *sort = sorted;

    printf("enter string: ");
    scanf("%s", sorted);

    printf("sorted string: %s", sort);

    return 0;
}