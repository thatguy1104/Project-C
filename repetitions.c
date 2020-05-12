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

int countLeadingZeros(char matrix[MAX_ITERATIONS][STR_LEN], int iterations) {
    int zeros = 0;
    bool leading = true;

    for (int i = 0; i < iterations; i++) {
        if (strlen(matrix[i]) != 4) {
            zeros += 4 - strlen(matrix[i]);
        }
    }
    return zeros;
}
void charReps(char string[STR_LEN], int leading_zeros) {
    int freq[256] = {0};
    for (int i = 0; string[i] != '\0'; i++) {
        freq[string[i]]++;
    }
    printf("%lu symbols, %i leading on the left\n", strlen(string), leading_zeros);
    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            printf("%d symbols %c\n", freq[i], i);
        }
    }
}
void repeatChar(char matrix[MAX_ITERATIONS][STR_LEN], int iterations) {
    char repetitions[MAX_ITERATIONS];
    int n = 0;
    char *new_str;
    // Dynamically allocate memory of size STR_LEN * iterations + 1
    if ((new_str = malloc((STR_LEN * iterations) + 1)) != NULL) {
        new_str[0] = '\0';
        for (int i = 0; i < iterations; i++) {
            strcat(new_str, matrix[i]);
        }
    }
    int lead = countLeadingZeros(matrix, iterations);
    charReps(new_str, lead);
}

void printMatrix(char matrix[MAX_ITERATIONS][STR_LEN], int inter_used) {
    for (int i = 0; i < inter_used; i++) {
        if (strlen(matrix[i]) != 4) {
            for (int j = 0; j < 4 - strlen(matrix[i]); j++) {
                printf("0");
            }
        }
        printf("%s\n", matrix[i]);
    }
}

//void addZeros(char matrix[MAX_ITERATIONS][STR_LEN], int iterations) {
//    int zeros = 0;
//    bool leading = true;
//
//    for (int i = 0; i < iterations; i++) {
//        leading = true;
//
//        for (int j = 0; j < strlen(matrix[i]); j++) {
//            if (matrix[i][j] != '0') {
//                leading = false;
//            }
//            if (matrix[i][j] == '0' && leading) {
//                zeros++;
//            }
//        }
//    }
//
//    for (int i = 0; i < iterations; i++) {
//        for (int j = 0; j < STR_LEN; j++) {
//            p[i][j] = new[i][j];
//        }
//    }
//}

int main() {
    char matrix[MAX_ITERATIONS][STR_LEN] = {
            {"172"},
            {"0036"},
            {"2D"},
            {"AD"},
            {"10D"},
            {"AA"},
            {"C8"},
            {"D0"},
            {"A9"},
            {"B5"}
    };
    printf("%i\n", countLeadingZeros(matrix, 10));
}

// from input 0000ab12c