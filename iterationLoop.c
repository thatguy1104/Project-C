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

void iterationLoop(char *hex) {
    
}

int main() {
    iterationLoop(hexadecimal);
}