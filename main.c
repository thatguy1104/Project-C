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
    final[k + 1] = '\0';

    // For dynamic allocation of memory, copy contents of the final array to the heap
    for (int i = 0; i < strlen(final); i++) {
        str[i] = final[i];
    }
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
    int iteration = 0;
    char continue_key[2];
    int sum_of_squares = squaresum1(hex);
    printf("Starting...\n");
    fgets(continue_key, 1, stdin);

    char matrix[MAX_ITERATIONS][STR_LEN];

    while (true) {
        if (iteration != MAX_ITERATIONS && sum_of_squares != 1) {
            fgets(continue_key, 2, stdin);
            strcpy(matrix[iteration], hex);
            printString(hex);
            printf("decimal = %i\n", HexToDec(hex));
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
            break;
        }
    }
//    char key[2];
//    printf("\nPress any key to show the iterations matrix:");
//    fgets(key, 2, stdin);
//    printMatrix(matrix, iteration);
//    printf("\nPress any key to show the repetitions:\n");
//    fgets(key, 2, stdin);
//    repeatedStrings(matrix, iteration);
}

char *askForHexadecimal() {
    char hex[HEX_LEN];
    char *str = malloc(HEX_LEN);
    int i;

    printf("Enter a hexadecimal number:\n");
    fgets(hex, HEX_LEN, stdin);

    while (allZeros(hex)) {
        printf("Enter a hexadecimal number:\n");
        fgets(hex, HEX_LEN, stdin);
    }
    for (i = 0; i < strlen(hex); i++) {
        str[i] = hex[i];
    }
    str[strlen(hex)] = '\0';

    char *f = removeZeros(str);
    char *c = capitalise(f);
    printString(c);
    return c;
}

void run() {
    questions();
    char *hexadecimal = askForHexadecimal();
    iterationLoop(hexadecimal);
}

int main() {
    run();
}