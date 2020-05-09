//
// Created by Albert Mukhametov on 09/05/2020.
//

#include "functions.h"
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

void questions() {
    char continueKey[2];
    printf("\nWelcome, press any key to start\n");
    fgets(continueKey, 2, stdin);
}

char* askForHexadecimal() {
    char hex[20];
    fflush(stdin);
    printf("Enter a hexadecimal number\n");
    fgets(hex, 20, stdin);
    char *str = hex;
    return str;
}

void printString(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        printf("%c", str[i]);
    }
}

void run() {
    questions();
    char *hexadecimal = askForHexadecimal();
    printString(hexadecimal);

}

int main() {
    run();
}