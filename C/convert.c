#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimalToBinary(int decimal, char *binary) {
    int index = 0;
    while(decimal > 0) {
        binary[index++] = decimal % 2 + '0';
        decimal /= 2;
    }
    binary[index] = '\0';
    strrev(binary);
}

void binaryToHexadecimal(char *binary, char *hexadecimal) {
    int binaryLength = strlen(binary);
    int i, j = 0, decimal = 0, temp;

    for(i = binaryLength - 1; i >= 0; i -= 4) {
        temp = 0;
        if(binary[i] == '1') {
            temp += 1;
        }
        if(i - 1 >= 0 && binary[i - 1] == '1') {
            temp += 2;
        }
        if(i - 2 >= 0 && binary[i - 2] == '1') {
            temp += 4;
        }
        if(i - 3 >= 0 && binary[i - 3] == '1') {
            temp += 8;
        }
        if(temp < 10) {
            hexadecimal[j++] = temp + '0';
        } else {
            hexadecimal[j++] = temp - 10 + 'A';
        }
    }
    hexadecimal[j] = '\0';
    strrev(hexadecimal);
}

void hexadecimalToOctal(char *hexadecimal, char *octal) {
    int hexadecimalLength = strlen(hexadecimal);
    int i, j = 0, decimal = 0, temp;

    for(i = 0; i < hexadecimalLength; i++) {
        if(hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            temp = hexadecimal[i] - '0';
        } else if(hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            temp = hexadecimal[i] - 'A' + 10;
        }
        decimal = decimal * 16 + temp;
    }

    while(decimal != 0) {
        temp = decimal % 8;
        octal[j++] = temp + '0';
        decimal /= 8;
    }
    octal[j] = '\0';
    strrev(octal);
}

int main() {
    int decimal = 125;
    char binary[32], hexadecimal[32], octal[32];

    decimalToBinary(decimal, binary);
    printf("Decimal: %d\nBinary: %s\n", decimal, binary);

    binaryToHexadecimal(binary, hexadecimal);
    printf("Hexadecimal: %s\n", hexadecimal);

    hexadecimalToOctal(hexadecimal, octal);
    printf("Octal: %s\n", octal);

    return 0;
}