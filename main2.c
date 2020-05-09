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

// Supplementary Functions

int int_len(int value) {
    int l = !value;
    while (value) {
        l++;
        value /= 10;
    }
    return l;
}

void printString(char *str) {
    while (*str != '\n')
        printf("%c", *str++);
    printf("\n");
}


// Main Program Functions

void questions() {
    char continueKey[2];
    printf("Welcome, press any key to start\n");
    fgets(continueKey, 2, stdin);
}

bool check(char *hex) {
    int allZeros = false;
    for (int i = 0; i < strlen(hex) - 1; i++) {
        if ((hex[i] != '0')) {
            allZeros = false;
        } else {
            allZeros = true;
        }
    }
    return allZeros;
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

int HexToDec(char *hex) {
    int len = strlen(hex);
    int base = 1;
    int dec_val = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec_val += (hex[i] - 48) * base;
            base *= 16;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec_val += (hex[i] - 55) * base;
            base *= 16;
        }
    }
    printf("%i\n", dec_val);
    return dec_val;
}

char *DecToHex(int decimal) {
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
    hexadecimal[i] = '\0';

    // Reverse hexadecimal array to get the final result
    for (int j = i - 1; j >= 0; j--) {
        final[k] = hexadecimal[j];
        k++;
    }
    printString(final);
    return str;
}

int squaresum1(char *hex) {
    int Dec2sum = HexToDec(hex);
    int remainder = 0, sum = 0;
    while (Dec2sum > 0) {
        remainder = Dec2sum % 10;
        sum += remainder * remainder;
        Dec2sum = Dec2sum / 10;
    }
    printf("the sum of %s is %d \n", hex, sum);
    return sum;
}

void iterationLoop(char *hex) {

}

void run() {
    questions();
    char *hexadecimal = askForHexadecimal();
    iterationLoop(hexadecimal);
}

int main() {
    run();
}