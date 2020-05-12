//
// Created by Albert Mukhametov on 08/05/2020.
//
#include<stdio.h>
#include<string.h>


void questions() {
    char continueKey[2];
    printf("\nWelcome, press any key to start\n");
    fgets(continueKey, 2, stdin);
}

int main() {
    questions();
}