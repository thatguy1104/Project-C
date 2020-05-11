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
#define MAX_ITERATIONS 100
#define STR_LEN 5

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

int HexToDecSUM(char hex) {
    int base = 1, dec_val = 0;
    if (hex >= '0' && hex <= '9') {
        dec_val += (hex - 48) * base;
        base = base * 16;
    }
    else if (hex >= 'A' && hex <= 'F') {
        dec_val += (hex - 55) * base;
        base = base * 16;
    }
    return dec_val;
}

int squaresum1(char *hex) {
    int sum = 0;

    for (int i = 0; i < strlen(hex); i++) {
        int digit = HexToDecSUM(hex[i]);
        int square = digit * digit;
        sum += square;
    }
//
//
//    int Dec2sum = HexToDec(hex);
//    int remainder = 0, sum = 0;
//    while (Dec2sum > 0) {
//        remainder = Dec2sum % 10;
//        sum += remainder * remainder;
//        Dec2sum = Dec2sum / 10;
//    }
    return sum;
}

void printMatrix(char matrix[MAX_ITERATIONS][STR_LEN]) {
    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", matrix[i]);
    }
}

void iterationLoop(char *hex) {
    int iteration = 0;
    char continue_key[2];
    int sum_of_squares = squaresum1(hex);
    bool start = true;
    printf("Starting...\n");
    fgets(continue_key, 1, stdin);

    char matrix[MAX_ITERATIONS][STR_LEN];

    while (start) {
        if (iteration != MAX_ITERATIONS && sum_of_squares != 1) {
            fgets(continue_key, 2, stdin);
            printString(hex);
            strcpy(matrix[iteration], hex);
            printf("in decimal = %i\n", HexToDec(hex));
            printf("sum of squares = %i\n", squaresum1(hex));
            sum_of_squares = squaresum1(hex);
            hex = DecToHex(sum_of_squares);

            printString(hex);
            iteration++;
        } else if (continue_key[0] == ' ') {
            break;
        } else if (sum_of_squares == 1) {
            strcpy(matrix[iteration], "1");
            break;
        } else {
            start = false;
            break;
        }
    }
    printMatrix(matrix);
}

int main() {
    // correct
    int dec = HexToDec("A9");
    printf("%i\n", dec);
    // correct
    char *hex = DecToHex(dec);
    printf("%s\n", hex);

    int sqrsum = squaresum1(hex);
    printf("square sum = %i\n", sqrsum);

    char *final = DecToHex(sqrsum);
    printf("hex of the square sum = %s\n", final);

}