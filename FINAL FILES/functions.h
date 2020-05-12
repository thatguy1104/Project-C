//
// Created by Albert Mukhametov on 08/05/2020.
//

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define HEX_LEN 20
#define MAX_ITERATIONS 100
#define STR_LEN 5

void questions();

void printString(char *str);

void printMatrix(char matrix[MAX_ITERATIONS][STR_LEN], int inter_used);

char *capitalise(char *hex);

char *removeZeros(char *str);

bool allZeros(char *str);

int HexToDec(char *hex);

char *DecToHex(int decimal);

int HexToDecSUM(char hex);

int squaresum1(char *hex);

char *askForHexadecimal();

void minMax(char matrix[MAX_ITERATIONS][STR_LEN], int iterations);

int countLeadingZeros(char matrix[MAX_ITERATIONS][STR_LEN], int iterations);

void charReps(char string[STR_LEN], int leading_zeros);

void repeatChar(char matrix[MAX_ITERATIONS][STR_LEN], int iterations);

int search(char matrix[MAX_ITERATIONS][STR_LEN], char str[STR_LEN], int reps);

void repeats(char matrix[MAX_ITERATIONS][STR_LEN], char repeat[MAX_ITERATIONS][STR_LEN], int reps);

void repeatedStrings(char matrix[MAX_ITERATIONS][STR_LEN], int iterations);

void iterationLoop(char *hex);

void run();