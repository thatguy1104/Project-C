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

//void repeatedStrings(char matrix[MAX][5], int numiterations) {//brings the matrix and the number of iterations
//    char rep[ITERATIONS][100]; //new matrix for repeated strings.
//    int i = 0, j = 0, t, repetitions, h, y, numrep = 0;
//    for (i = 1; i <= numiterations; i++) {
//        t = 0;
//        for (j = 1; j <= numiterations; j++) {
//            if (strcmp(matrix[i], rep[j]) == 0) {
//                t = 1;
//            }
//        }
//        if (t != 1) {
//            numrep = numrep + 1;
//            strcpy(rep[numrep], matrix[i]);
//        }
//    }
//    for (i = 1; i <= numrep; i++) {
//        t = 0;
//        for (j = 1; j <= numiterations; j++) {
//            if (strcmp(rep[i], matrix[j]) == 0) {
//                t = t + 1;
//            }
//        }
//        if (t > 1) {
//            printf("\n %s is repeated %d times", rep[i], t);
//            h = 1;
//        }
//    }
//    if (h == 1) {
//        printf("\n Unhappy number because the strings are repeated.");
//        y = 0; //this variable used ony to then show if repetitions or not
//    } else {
//        printf("\nThere are no repeated strings, so no conclusions taken");
//        y = -1; //this variable used ony to then show if repetitions or not
//    }
//    memset(rep, 0, sizeof rep);//this clears the matrix so it doesn't fuck up later on.
//}

int search(char matrix[MAX_ITERATIONS][STR_LEN], char str[STR_LEN], int reps) {
    int counter = 0;

    for (int i = 0; i < MAX_ITERATIONS; i++) {
        if (strcmp(matrix[i], str) == 0) {
            counter++;
        }
    }
    return counter;
}

void repeats(char matrix[MAX_ITERATIONS][STR_LEN], char repeats[MAX_ITERATIONS][STR_LEN], int reps) {
    for (int i = 0; i < reps; i++) {
        printf("%s is repeated %i times\n", repeats[i], search(matrix, repeats[i], reps));
    }
}

void repeatedStrings(char matrix[MAX_ITERATIONS][STR_LEN], int iterations) {
    char repetitions[MAX_ITERATIONS][STR_LEN];
    int num_of_reps[MAX_ITERATIONS];
    int reps = 0, count;
    int n = 0;

    printf("Repeating elements are\n");
    for (int i = 0; i < iterations; i++) {
        for (int j = i + 1; j < iterations; j++) {
            int flag = 0;
            if (strcmp(matrix[i], matrix[j]) == 0) {
                // check if the string was already repeated
                for (int k = 0; k < iterations; k++) {
                    if (strcmp(repetitions[k], matrix[i]) == 0) {
                        flag = 1;
                    }
                }
                if (flag != 1) {
                    strcpy(repetitions[n], matrix[i]);
//                    printf("%s is %i times\n", repetitions[n], num_of_reps[n]);
//                    printf("%s is %i times\n", repetitions[n], search(matrix, repetitions[n], iterations));
                    n++;
                }
            }
        }
    }
    repeats(matrix, repetitions, n);
}

int main() {
    char matrix[MAX_ITERATIONS][STR_LEN] = {
            {"001A"},
            {"001A"},
            {"001A"},
            {"001B"},
            {"001C"},
            {"001A"},
            {"001B"},
            {"001E"},
            {"001E"},
            {"001C"},
            {"001C"},
            {"001C"}
    };
    repeatedStrings(matrix, 12);
}