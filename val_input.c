//
// Created by Albert Mukhametov on 10/05/2020.
//
#include "functions.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define HEX_LEN 20
#define MAX_ITERATIONS 100
#define STR_LEN 5

void printString(char *str) {
    while (*str != '\0')
        printf("%c", *str++);
    printf("\n");
}

char *capitalise(char *hex) {
    char result[HEX_LEN];
    for (int i = 0; i < strlen(hex); i++) {
        result[i] = toupper(hex[i]);
    }

    char *str = malloc(HEX_LEN);
    for (int i = 0; i < strlen(result); i++) {
        str[i] = result[i];
    }
    return str;
}

char *removeZeros(char *str) {
    char nonZ[HEX_LEN];
    int k = 0;
    bool leading = true;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != '0') {
            nonZ[k] = str[i];
            k++;
            leading = false;
        }
        if (str[i] == '0' && !leading) {
            nonZ[k] = str[i];
            k++;
        }
    }
    char *p = malloc(HEX_LEN);
    for (int i = 0; i < strlen(nonZ); i++) {
        p[i] = nonZ[i];
    }
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
    char cap[HEX_LEN];
    char noZeros[HEX_LEN];
    char *str = malloc(HEX_LEN);

    printf("Enter a hexadecimal number:\n");
    fgets(hex, HEX_LEN, stdin);

    while (allZeros(hex)) {
        printf("Enter a hexadecimal number:\n");
        fgets(hex, HEX_LEN, stdin);
    }
    for (int i = 0; i < strlen(hex) - 1; i++) {
        str[i] = hex[i];
    }


    printString(hex);
    return str;
}

int main() {
//    char *hexadecimal = askForHexadecimal();
    char *f = removeZeros("0001aacs000");
    char *c = capitalise(f);
    printString(c);
}