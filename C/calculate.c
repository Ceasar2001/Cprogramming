#include <stdio.h>

int main(){

    int num1, num2;
    int operator;

    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);

    printf("Choose the operator to be used: \n1: ADDITION\n2: SUBSTRACTION\n3: MULTIPLY\n4: DIVISION\n");

    printf("ENTER YOUR CHOICE: (1-4)\n");
    scanf("%d", &operator);
switch(operator){
    case 1:{
       int sum = num1 + num2;
       printf("The sum of %d and %d is %d", num1, num2, sum);
    };break;
    case 2:{
       int subtract = num1 - num2;
       printf("The subtract of %d and %d is %d", num1, num2, subtract);
    };break;
    case 3:{
       int multiply = num1 * num2;
       printf("The multiplacation of %d and %d is %d", num1, num2, multiply);
    };break;
    case 4:{
       int div = num1 / num2;
       printf("The division of %d and %d is %d", num1, num2, div);
    };break;
}
    return 0;
}