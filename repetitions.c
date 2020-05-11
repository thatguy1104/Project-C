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
    hexadecimal[i] = '\0';

    // Reverse hexadecimal array to get the final result
    for (int j = i - 1; j >= 0; j--) {
        final[k] = hexadecimal[j];
        k++;
    }
    final[k + 1] = '\0';

    // For dynamic allocation of memory, copy contents of the final array to the heap
    for (int i = 0; i < strlen(final); i++) {
        str[i] = final[i];
    }
    return str;
}

int search(char matrix[MAX_ITERATIONS][STR_LEN], char str[STR_LEN], int reps) {
    int counter = 0;

    for (int i = 0; i < MAX_ITERATIONS; i++) {
        if (strcmp(matrix[i], str) == 0) {
            counter++;
        }
    }
    return counter;
}

void repeats(char string[STR_LEN]) {
    int freq[256] = {0};
    for (int i = 0; string[i] != '\0'; i++) {
        freq[string[i]]++;
    }
    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            printf("%c %d\n", i, freq[i]);
        }
    }
}

void repeatChar(char matrix[MAX_ITERATIONS][STR_LEN], int iterations) {
    char repetitions[MAX_ITERATIONS];
    int n = 0;
    repeats(matrix[0]);
}

int main() {
    char matrix[MAX_ITERATIONS][STR_LEN] = {
            {"001A"},
            {"01"},
            {"01A"},
            {"1"},
            {"01C"},
            {"A"},
            {"01B"},
            {"1E"},
            {"001E"},
            {"1C"},
            {"C"}
    };
    repeatChar(matrix, 12);
}