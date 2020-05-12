//
// Created by Albert Mukhametov on 12/05/2020.
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
    return dec_val;
}
char *DecToHex(int decimal) {
    char hexadecimal[5];
    char final[5];

    // Dynamically allocate memory for the final string - it will be used to update it each iteration
    char *str = malloc(5);
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
    // Reverse hexadecimal array to get the final result
    for (int j = i - 1; j >= 0; j--) {
        final[k] = hexadecimal[j];
        k++;
    }
    // For dynamic allocation of memory, copy contents of the final array to the heap
    for (int i = 0; i < strlen(final); i++) {
        str[i] = final[i];
    }
    str[i] = '\0';
    return str;
}

void minMax(char matrix[MAX_ITERATIONS][STR_LEN], int iterations) {
    int arrInt[MAX_ITERATIONS];
    // fill the integer matrix with values of the hexadecimal matrix
    for (int i = 0; i < iterations; i++) {
        arrInt[i] = HexToDec(matrix[i]);
    }

    // Find the min and max values of the integer array
    int min = arrInt[0], max = arrInt[0];
    for (int i = 0; i < iterations; i++) {
        if (arrInt[i] < min) min = arrInt[i];
        if (arrInt[i] > max) max = arrInt[i];
    }
    // Print min and max values in their hexadecimal representation
    printf("Lowest number is %s\nBiggest number is %s\n", DecToHex(min),  DecToHex(max));
}


int main() {
    char matrix[MAX_ITERATIONS][STR_LEN] = {
            {"001A"},
            {"A"},
            {"C"},
            {"01"},
            {"01A"},
            {"1"},
            {"01C"},
            {"A0"},
            {"01B"},
            {"1E"},
            {"001E"},
            {"1C"},
            {"C"}
    };
    minMax(matrix, 13);
}