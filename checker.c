//
// Created by Albert Mukhametov on 09/05/2020.
//

#include "functions.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define HEX_LEN 20

void printString(char *str) {
    while (*str != '\n')
        printf("%c", *str++);
    printf("\n");
}

char *capitalise(char *hex) {
    char result[HEX_LEN];
    for (int i = 0; i < strlen(hex) + 1; i++) {
        result[i] = toupper(hex[i]);
    }
    char *str = result;
    return str;
}

char *removeZeros(char *str) {
    char nonZ[HEX_LEN];
    int k = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != '0') {
            nonZ[k] = str[i];
            k++;
        }
    }
    char *p = nonZ;
    return p;
}

bool allZeros(char *str) {
    bool zeros = false;
    while (*str != '\n') {
        if (*str != '0') {
            return false;
        }
        str++;
    }
    return true;
}

char *askForHexadecimal() {
    char hex[HEX_LEN];
    bool zeros = true;

    printf("Enter a hexadecimal number:\n");
    fgets(hex, HEX_LEN, stdin);

    while (allZeros(hex)) {
        printf("Enter a hexadecimal number:\n");
        fgets(hex, HEX_LEN, stdin);
    }

    char *str = hex;
    printString(hex);
    return str;
}

int main() {
    char *hexadecimal = askForHexadecimal();
//    allZeros("0000q");
}