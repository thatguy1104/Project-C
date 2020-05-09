//
// Created by Albert Mukhametov on 08/05/2020.
//

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXCHAR 20
#define ITERATIONS 100

void questions();

void printString(char* str);

bool check(char *hex);

char *capitalise(char *hex);

bool allZeros(char *str);

void asknumHex(char numHex[MAXCHAR]);

char *removeZeros(char *str);

int conversionHex2Dec(char numHex[MAXCHAR]);

int happyNumber(char nozerosHex[MAXCHAR],char matrix[ITERATIONS][5]);

int conversionDec2Hex(int sol, int count, char matrix2[5]);

void fmatrix(char matrix[ITERATIONS][5], int count);

void count_frequency(int*data,int size);

void numreps(int count,char matfinal[ITERATIONS][5]);

void repetitions(int count);

void showBigaSmallnumH(int count);

int End_program();

