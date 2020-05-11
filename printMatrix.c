//
// Created by Albert Mukhametov on 11/05/2020.
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

void printMatrix(char matrix[MAX_ITERATIONS][STR_LEN], int inter_used) {
    printf("\n");
    for (int i = 0; i < inter_used + 1; i++) {
        if (strlen(matrix[i]) != 4) {
            for (int j = 0; j < 4 - strlen(matrix[i]); j++) {
                printf("0");
            }
        }
        printf("%s\n", matrix[i]);
    }
}

int main() {
    char matrix[MAX_ITERATIONS][STR_LEN] = {
            {"1A"},
            {"01A"},
            {"A"},
            {"1B"},
            {"C"},
            {"001A"},
            {"1B"},
            {"01E"},
            {"01E"},
            {"001C"},
            {"01C"},
            {"00C"}
    };
    printMatrix(matrix, 12);
}