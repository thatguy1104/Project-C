//
// Created by Albert Mukhametov on 08/05/2020.
//
#define MAXCHAR 20
#define ITERATIONS 100

void questions();

void printString(char* str);

void asknumHex(char numHex[MAXCHAR]);

int removezeroes(char numHex[MAXCHAR], char nozerosHex[MAXCHAR]);

int conversionHex2Dec(char numHex[MAXCHAR]);

int happyNumber(char nozerosHex[MAXCHAR],char matrix[ITERATIONS][5]);

int conversionDec2Hex(int sol, int count, char matrix2[5]);

int squaresum1 (char nozerosHex[MAXCHAR],int end, int count);

void fmatrix(char matrix[ITERATIONS][5], int count);

void count_frequency(int*data,int size);

void numreps(int count,char matfinal[ITERATIONS][5]);

void repetitions(int count);

void showBigaSmallnumH(int count);

int End_program();

