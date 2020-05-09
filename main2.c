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

void questions() {
    char continueKey[2];
    printf("\nWelcome, press any key to start\n");
    fgets(continueKey, 2, stdin);
}

bool check(char *hex) {
    int numOfZeros = 0;
    for (int i = 0; i < strlen(hex); i++) {
        if (hex[i] == '0') {
            numOfZeros++;
        }
    }
    return numOfZeros > 2;
}

char *askForHexadecimal() {
    char hex[HEX_LEN];
    bool zeros = true;
    
    fflush(stdin);
    printf("Enter a hexadecimal number\n");
    scanf("%[1-9A-Z]", hex);

    // Loop to get correct input. Loops if more than 2 zeros's are entered
    while (zeros) {
        fflush(stdin);
        printf("Enter a hexadecimal number\n");
        scanf("%[1-9A-Z]", hex);
        if(check(hex)) {
            continue;
        } else {
            zeros = false;
            break;
        }
    }
    char *str = hex;
    printString(hex); // For debugging purposes. May remove this after.

    return str;
}

void printString(char *str) {
    while (*str != '\0')
        printf("%c", *str++);
    printf("\n");
}

int HexToDec(char *hex) {
    int len = strlen(hex);
    int base = 1;
    int dec_val = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec_val += (hex[i] - 48) * base;
            base *= 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec_val += (hex[i] - 55) * base;
            base *= 16;
        }
    }
    printf("%i\n", dec_val);
    return dec_val;
}

int int_len(int value){
    int l = !value;
    while (value) {
        l++;
        value/=10;
    }
    return l;
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
    int sum = 0;
    int dec = HexToDec(hex);

    for (int i = 0; i < int_len(dec); i++) {
        while (dec > 0) {
            dec = dec / 10;
            sum += pow(dec, 2);
        }
    }
    return sum;
}

void run() {
    questions();
    char *hexadecimal = askForHexadecimal();
//    printString(hexadecimal);
//    DecToHex(2545);
//    HexToDec("1A");

}

int main() {
    run();
}