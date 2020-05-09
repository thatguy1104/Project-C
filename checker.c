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
    while (*str != '\0')
        printf("%c", *str++);
    printf("\n");
}

char *capitalise(char *hex) {
    char result[HEX_LEN];
    for (int i = 0; i < strlen(hex) + 1; i++) {
        result[i] = toupper(hex[i]);
    }
    printString(result);
    char *str = result;
    return str;
}

char *askForHexadecimal() {
    char hex[HEX_LEN];
    bool zeros = true;
    fflush(stdin);

    printf("Enter a hexadecimal number\n");
    scanf("%s", hex);

    char *str = capitalise(hex);
    return str;
}

int main() {
    char *hexadecimal = askForHexadecimal();
}