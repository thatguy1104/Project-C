//
// Created by Albert Mukhametov on 10/05/2020.
//

char *capitalise(char *hex) {
    char result[HEX_LEN];
    for (int i = 0; i < strlen(hex) + 1; i++) {
        result[i] = toupper(hex[i]);
    }
    char *str = result;
    return str;
}

char *removeZeros(char *str) {
    char nonZ[HEX_LEN];
    int k = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != '0') {
            nonZ[k] = str[i];
            k++;
        }
    }
    char *p = nonZ;
    return p;
}

char *askForHexadecimal() {
    char hex[HEX_LEN];
    char *str = malloc(HEX_LEN);

    printf("Enter a hexadecimal number:\n");
    fgets(hex, HEX_LEN, stdin);

    while (allZeros(hex)) {
        printf("Enter a hexadecimal number:\n");
        fgets(hex, HEX_LEN, stdin);
    }
    for (int i = 0; i < strlen(hex) - 1; i++) {
        str[i] = hex[i];
    }
    return str;
}

int main() {
    char *hexadecimal = askForHexadecimal();
}