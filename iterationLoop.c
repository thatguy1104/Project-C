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
    final[k] = '\0';
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
    return sum;
}

void iterationLoop(char *hex) {
    int iteration = 1, max_iterations = 100;
    char continue_key[2];
    int sum_of_squares = squaresum1(hex);
    bool start = true;
    printf("Starting...\n");
    fgets(continue_key, 1, stdin);

    while (start) {
        if (iteration != max_iterations && sum_of_squares != 1) {
            fgets(continue_key, 2, stdin);
            printf("%s\n", hex);
            printf("in decimal = %i\n", HexToDec(hex));
            printf("sum of squares = %i\n", squaresum1(hex));
            hex = DecToHex(squaresum1(hex));
            iteration++;
        } else {
            start = false;
            break;
        }
    }


//    while ((iteration != max_iterations) && (sum_of_squares != 1) && (continue_key[0] == ' ')) {
//        fgets(continue_key, 1, stdin);
//        printf("%s\n", hex);
//        printf("in decimal = %i\n", HexToDec(hex));
//        printf("sum of squares = %i\n", squaresum1(hex));
//        hex = DecToHex(squaresum1(hex));
//        iteration++;
//    }
}

int main() {
    iterationLoop("1A");
}