#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define HEX_LEN 20
#define MAX_ITERATIONS 100
#define STR_LEN 5

#define L 21
#define N 5


struct search{
	char number[L];
	int iterations;
	int happy;
};


void questions() {
    char continuekey;
    printf("Welcome, press any key to start\n");
    continuekey=getch();
}

void printMatrix(char matrix[MAX_ITERATIONS][STR_LEN], int inter_used) {
	int i, j;
    for (i = 0; i < inter_used; i++) {
        if (strlen(matrix[i]) != 4) {
        	//goes between rows and columns
            for (j = 0; j < 4 - strlen(matrix[i]); j++) {
                printf("0");
            }
        }
        printf("%s\n", matrix[i]);
    }
}

char *capitalise(char *hex) {
    char result[HEX_LEN];
    int i;
    for (i = 0; i < strlen(hex); i++) {
        result[i] = toupper(hex[i]);
    }
    char *str = malloc(HEX_LEN);
    for (i = 0; i < strlen(result); i++) {
        str[i] = result[i];
    }
    return str;
}

char *removeZeros(char *str) {
    char nonZ[HEX_LEN];
    int k = 0;
    int i;
    bool leading = true;
    for (i = 0; i < strlen(str); i++) {
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
    // Copy the contents of an array to the new pointer, to be used further.
    // Manually allocate memory on the heap of size HEX_LEN
    char *p = malloc(HEX_LEN);
    for (i = 0; i < strlen(nonZ); i++) {
        p[i] = nonZ[i];
    }
    return p;
}

//Boolean is used to either have the funtion return true, or false. If input = 0's, return true. Otherwise False.
bool allZeros(char *str) {
    while (*str != '\n') {
        if (*str != '0') {
            return false;
        }
        str++;
    }
    printf("You entered only zeros\n");
    return true;
}

bool isHex(char num[HEX_LEN]) {
    int i;
    for (i = 0; i < strlen(num) - 1; i++) {
    	// "isxdigit" is a system function to determine if a single character belongs to Hexadecimal spectrum.
        if (!isxdigit(num[i])) {
            return false;
        }
    }
    return true;
}

int HexToDec(char *hex) {
    int len = strlen(hex);
    int base = 1;
    int dec_val = 0;
    int i;

    for (i = len - 1; i >= 0; i--) {
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
    int j;
    int m;

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
    for (j = i - 1; j >= 0; j--) {
        final[k] = hexadecimal[j];
        k++;
    }
    // For dynamic allocation of memory, copy contents of the final array to the heap
    for (m = 0; m < strlen(final); m++) {
        str[m] = final[m];
    }
    str[i] = '\0';
    return str;
}

int HexToDecSUM(char hex) {
    int base = 1, dec_val = 0;
    if (hex >= '0' && hex <= '9') {
        dec_val += (hex - 48) * base;
        base = base * 16;
    } else if (hex >= 'A' && hex <= 'F') {
        dec_val += (hex - 55) * base;
        base = base * 16;
    }
    return dec_val;
}

int squaresum1(char *hex) {
    int sum = 0;
    int i;
    for (i = 0; i < strlen(hex); i++) {
        int digit = HexToDecSUM(hex[i]);
        int square = digit * digit;
        sum += square;
    }
    return sum;
}

bool checkForLen(char* str) {

    if (strlen(str) == HEX_LEN - 1 || strlen(str) == 2) {
        return false;
    }

    else if (strlen(str) == 0) {
        return false;
    }

    int counter = 0, i;

    for (i = 0; i < strlen(str) - 1; i++) {
        if (str[i] != '\0' || str[i] != '\n') {
            counter++;
        }
    }

    if (counter >= HEX_LEN - 1) {
        return false;
    }
    return true;
}

char *askForHexadecimal() {
    char hex[HEX_LEN];
    char *str = malloc(HEX_LEN);
    int i;

    printf("Enter a hexadecimal number:\n");
    // use fgets instead of getch because of a more controlled input (specified lenght)
    fgets(hex, HEX_LEN, stdin);

    while (allZeros(hex) || !isHex(hex) || !checkForLen(hex)) {
        printf("Enter a hexadecimal number:\n");
        fflush(stdin);
        fgets(hex, HEX_LEN, stdin);
    }

    for (i = 0; i < strlen(hex); i++) {
        // Manual allocation of memory of contents of array to a pointer
        str[i] = hex[i];
    }
    str[strlen(hex)] = '\0';

    char *f = removeZeros(str);
    char *c = capitalise(f);
    printf("String is: %s\n", c);
    return c;
}

void minMax(char matrix[MAX_ITERATIONS][STR_LEN], int iterations) {
    int arrInt[MAX_ITERATIONS];
    int i;
    int j;
    // fill the integer matrix with values of the hexadecimal matrix.
    for (i = 0; i < iterations; i++) {
        arrInt[i] = HexToDec(matrix[i]);
    }
    // Find the min and max values of the integer array.
    int min = arrInt[0], max = arrInt[0];
    for (i = 0; i < iterations; i++) {
        if (arrInt[i] < min) min = arrInt[i];
        if (arrInt[i] > max) max = arrInt[i];
    }
    // Print min and max values in their hexadecimal representation (with the leading zeros).
    char *mi = DecToHex(min);
    char *mx = DecToHex(max);
    printf("Lowest number is ");
    if (strlen(mi) != 4) {
        for (j = 0; j < 4 - strlen(mi); j++) {
            printf("0");
        }
    }
    printf("%s\n", mi);

    printf("Biggest number is ");
    if (strlen(mx) != 4) {
        for (j = 0; j < 4 - strlen(mx); j++) {
            printf("0");
        }
    }
    printf("%s\n", mx);
}

int countLeadingZeros(char matrix[MAX_ITERATIONS][STR_LEN], int iterations) {
    int zeros = 0;
    int i;
    for (i = 0; i < iterations; i++) {
        if (strlen(matrix[i]) != 4) {
            zeros += 4 - strlen(matrix[i]);
        }
    }
    return zeros;
}

void charReps(char string[STR_LEN], int leading_zeros) {
    int freq[256] = {0};
    int count = 0;
    int i;

    for (i = 0; string[i] != '\0'; i++) {
        freq[string[i]]++;
    }
    for (i = 0; i < strlen(string); i++) {
        if (string[i] == '0') count++;
    }
    printf("%d symbols 0, %i leading on the left\n", leading_zeros + count, leading_zeros);
    // counts each character, so is ASCII value.
    for (i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            if (i != '0')
                printf("%d symbols %c\n", freq[i], i);
        }
    }
}

void repeatChar(char matrix[MAX_ITERATIONS][STR_LEN], int iterations) {
    char *new_str;
    int i;
    // Dynamically allocate memory of size STR_LEN * iterations + 1
    if ((new_str = malloc((STR_LEN * iterations) + 1)) != NULL) {
        new_str[0] = '\0';
        for (i = 0; i < iterations; i++) {
            strcat(new_str, matrix[i]);
        }
    }
    int lead = countLeadingZeros(matrix, iterations);
    charReps(new_str, lead);
}

int search(char matrix[MAX_ITERATIONS][STR_LEN], char str[STR_LEN], int reps) {
    int counter = 0;
    int i;
    for (i = 0; i < MAX_ITERATIONS; i++) {
        if (strcmp(matrix[i], str) == 0) {
            counter++;
        }
    }
    return counter;
}

void repeats(char matrix[MAX_ITERATIONS][STR_LEN], char repeat[MAX_ITERATIONS][STR_LEN], int reps) {
    int i, j;

    for (i = 0; i < reps; i++) {
        if (strlen(matrix[i]) != 5) {
            for (j = 0; j < 4 - strlen(matrix[i]); j++) {
                printf("0");
            }
        }
        printf("%s is repeated %i times\n", repeat[i], search(matrix, repeat[i], reps));
    }
    printf("Number is unhappy\n");
}

int repeatedStrings(char matrix[MAX_ITERATIONS][STR_LEN], int iterations) {
    char repetitions[MAX_ITERATIONS][STR_LEN];
    int n = 0;
    int i, j, k;
    int happy;

    for (i = 0; i < iterations; i++) {
        for (j = i + 1; j < iterations; j++) {
            int flag = 0;
            if (strcmp(matrix[i], matrix[j]) == 0) {
                // check if the string was already repeated
                for (k = 0; k < iterations; k++) {
                    if (strcmp(repetitions[k], matrix[i]) == 0) {
                        flag = 1;
                    }
                }
                if (flag != 1) {
                    strcpy(repetitions[n], matrix[i]);
                    n++;
                }
            }
        }
    }
    if (n > 0) {
        printf("Repeating elements are\n");
        repeats(matrix, repetitions, n);
        happy = 0;
    } else {
        printf("No repeated elements. No conclusion can be taken");
        happy = -1;
    }
    return happy;
}

int* iterationLoop(char *hex) {
    int iteration = 0;
    int j;
    int sum_of_squares = squaresum1(hex);
    char matrix[MAX_ITERATIONS][STR_LEN];
    char continuekey;
    int happy = 10;

    int results[2];
    
    printf("\nPress any key to show iterations\n");
    
    //So it stops if space is pressed
	bool loop= true;
    while (true && loop) {
    	continuekey=getch();
    	if (continuekey == 32) {
        	loop = false;
        	printf("\nThis is an user decision\n");
        	break;
    	} 
    	
        if (iteration != MAX_ITERATIONS && sum_of_squares != 1) {
            
            sum_of_squares = squaresum1(hex);
            hex = DecToHex(sum_of_squares);
            strcpy(matrix[iteration], hex);

            printf("\nIteration %i: ", iteration + 1);
            if (strlen(hex) != 4) {
                for (j = 0; j < 4 - strlen(hex); j++) {
                    printf("0");
                }
            }
            printf("%s", hex);
            iteration++;
        } else if (sum_of_squares == 1) {
            strcpy(matrix[iteration], "0001");
            happy = 1;
            break;
        } else {
            break;
        }
    }

    printf("\n\nPress any key to show the iterations matrix:");
    printf("\n--------------------------------------------\n");
    continuekey=getch();
    printMatrix(matrix, iteration);

    printf("\nPress any key to show the repetitions:");
    printf("\n--------------------------------------\n");
    continuekey=getch();
    int number = repeatedStrings(matrix, iteration);
    if (happy == 10) {
        happy = number;
    }

    printf("\nPress any key to show which symbols are in the iterations");
    printf("\n---------------------------------------------------------\n");
    continuekey=getch();
    repeatChar(matrix, iteration);

    printf("\nPress any key to show lowest and biggest numbers");
    printf("\n------------------------------------------------\n");
    continuekey=getch();
    minMax(matrix, iteration);

    results[0] = iteration;

    int *lst;
    lst[0] = results[0];
    lst[1] = happy;

    return lst;
}

// THIS IS COPIED FROM INTERNET
char *my_strcpy(char *destination, char *source) {
    char *start = destination;
 
    while(*source != '\0'){
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0'; // add '\0' at the end
    return start;
}

void run() {
	struct search fin[N]; //define the struct
	int f, h;
	for (f = 0; f < N; f++){

		printf("\nTime %d\n", f+1);
	    questions();
	    char *hexadecimal = askForHexadecimal();
        //struct stuff
        strcpy(fin[f].number, hexadecimal);
	    int* iter = iterationLoop(hexadecimal);
	    
	    
	    
        fin[f].iterations = iter[0];//if no, inter_used
		fin[f].happy = iter[1];
	}
	
	for (h = 0; h < N; h++){ //printing the results of the struct
		printf("\nTIME %i \n", h+1);
		printf("Initial number: %s", fin[h].number);
		printf("Iterations: %i \n", fin[h].iterations);
		printf("It is: ");
		if(fin[h].happy==1){
			printf("Happy\n\n");
		}else if(fin[h].happy==0){
			printf("Unhappy\n\n");
			
		}else{
			printf("Unknown\n\n");
		}
	}
}

int main() {
    run();
}