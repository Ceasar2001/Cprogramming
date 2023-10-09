#include <stdio.h>

void decimalToBinary(int decimal) {
    int binary[32];
    int i = 0;

    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }

    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

void decimalToHexadecimal(int decimal) {
    char hex[32];
    int i = 0;

    while (decimal > 0) {
        int remainder = decimal % 16;

        if (remainder < 10) {
            hex[i] = remainder + '0';
        } else {
            hex[i] = remainder + 'A' - 10;
        }

        decimal = decimal / 16;
        i++;
    }

    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n");
}

void decimalToOctal(int decimal) {
    int octal[32];
    int i = 0;

    while (decimal > 0) {
        octal[i] = decimal % 8;
        decimal = decimal / 8;
        i++;
    }

    printf("Octal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
    printf("\n");
}

int main() {
    int decimal;
    char choose;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    printf("(B for binary, H for hexadecimal, O for octal)\nChoose a converter: ");
    scanf(" %c", &choose);//dapat naa nay space sa " %c"

    if (choose == 'B') {
        decimalToBinary(decimal);
    } else if (choose == 'H') {
        decimalToHexadecimal(decimal);
    } else if (choose == 'O') {
        decimalToOctal(decimal);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}

//java rmi server side?




