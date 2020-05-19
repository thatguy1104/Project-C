//
// Created by Albert Mukhametov on 19/05/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define HEX_LEN 20

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

bool isHex(char num[HEX_LEN]) {
    for (int i = 0; i < strlen(num) - 1; i++) {
        if (!isxdigit(num[i])) {
            printf("%c is not hex\n", num[i]);
            return false;
        }
    }
    return true;
}

int main() {
    char hex[HEX_LEN];

    printf("Enter a hexadecimal number:\n");
    fgets(hex, HEX_LEN, stdin);

    while (allZeros(hex) || !isHex(hex)) {
        printf("Enter a hexadecimal number:\n");
        fgets(hex, HEX_LEN, stdin);
    }

    printf("Accepted\n");
}