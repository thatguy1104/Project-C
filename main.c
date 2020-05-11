#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define HEX_LEN 20
#define MAX_ITERATIONS 100
#define STR_LEN 5

void questions() {
    char continueKey[2];
    printf("Welcome, press any key to start\n");
    fgets(continueKey, 2, stdin);
}
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
    char *str = malloc(HEX_LEN);

    printf("Enter a hexadecimal number:\n");
    fgets(hex, HEX_LEN, stdin);

    while (allZeros(hex)) {
        printf("Enter a hexadecimal number:\n");
        fgets(hex, HEX_LEN, stdin);
    }
    for (int i = 0; i < strlen(hex); i++) {
        str[i] = hex[i];
    }

    char *f = removeZeros(str);
    char *c = capitalise(f);
    printString(c);
    return c;
}

void run() {
    questions();
    char *hexadecimal = askForHexadecimal();
}

int main() {
    run();
}