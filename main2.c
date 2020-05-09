//
// Created by Albert Mukhametov on 09/05/2020.
//

#include "functions.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HEX_LEN 20

void questions() {
    char continueKey[2];
    printf("\nWelcome, press any key to start\n");
    fgets(continueKey, 2, stdin);
}

char *askForHexadecimal() {
    char hex[HEX_LEN];
    fflush(stdin);
    printf("Enter a hexadecimal number\n");
    fgets(hex, HEX_LEN, stdin);
    char *str = hex;
    return str;
}

void printString(char *str) {
    while(*str!='\0')
        printf("%c",*str++);
    printf("\n");
}

int HexToDec(char *hex) {

    return 0;
}

char* DecToHex(int decimal) {
    char hexadecimal[100];
    char final[100];
    char *str = final;
    int i = 0, k = 0;

    while (decimal != 0) {
        int temp = 0;

        temp = decimal % 16;

        if (temp < 10) {
            hexadecimal[i] = (char) (temp + 48);
            i++;
        } else {
            hexadecimal[i] = (char) (temp + 55);
            i++;
        }
        decimal = decimal / 16;
    }
    hexadecimal[i]='\0';

    // Reverse hexadecimal array to get the final result
    for(int j = i - 1; j >= 0; j--) {
        final[k] = hexadecimal[j];
        k++;
    }
    printString(final);
    return str;
}

void run() {
//    questions();
//    char *hexadecimal = askForHexadecimal();
//    printString(hexadecimal);
    DecToHex(2545);
}

int main() {
    run();
}