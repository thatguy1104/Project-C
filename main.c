#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXCHAR 20
#define ITERATIONS 100
#define L 20
#define N 5

char mat[ITERATIONS][5];
char mat2[ITERATIONS][5];
int decmat4[100],oke=1,happy=0;



struct search{
    char hexadecimal[L];
    int count;//name less confusing bc i use count instead of iterations throughout program
    int happy;
};

int main(){
    char numH1[MAXCHAR];
    char nozerosHex[MAXCHAR];
    char matrix[ITERATIONS][5];
    int numD2;
    int count2;
    int del4;
    int strucrep;
    int h;

    struct search data[N];

    for (strucrep=0;strucrep<N;strucrep++){
        oke=1;
        happy=0;
        questions();
        asknumHex(numH1);
        removezeroes(numH1, nozerosHex);
        int counter = happyNumber(nozerosHex, matrix);
        fmatrix(mat,counter);//print big 2d matrix--ok
        numreps(counter,matrix);
        repetitions(counter); //find repetitions of characters
        showBigaSmallnumH(counter); //biggest row of big matrix and smallest

        strcpy(data[strucrep].hexadecimal,numH1);
        data[strucrep].count = counter;
        data[strucrep].happy = oke;

    }

    for(strucrep=0;strucrep<N;strucrep++){ //printing the results of the struct
        printf("\n\n\nIteration of program %i \n",strucrep+1);
        printf("\n Initial number: %s",data[strucrep].hexadecimal);
        printf("\n Iterations: %i",data[strucrep].count);
        printf("\n It is: ");
        if(data[strucrep].happy==0){
            printf("Unhappy\n");//strings dont repeat (also happens in happy number)
        }else if(data[strucrep].happy==1){
            printf("Happy\n");//strings repeat
        }else{
            printf("Unknown");
        }
    }
    End_program();//finish
}

int questions (){
    char continuekey;
    printf("\nWelcome, press any key to start\n");
    continuekey=getch(); //gets any key for it to start.
}//ok

int asknumHex(char numHex[MAXCHAR]){
    char character;
    int i=0;
    printf("\nEnter String of hexadecimal values\n");
    do {
        character = getch();
        if (character>=48 && character<=57){//letters accepted
            numHex[i] = character;
            putchar(character);
            i++;
        }else if (character>='A' && character <= 'F'){//converts all to capital letters.
            numHex[i] = character;
            putchar(character);
            i++;
        }else if (character>='a' && character <= 'f'){
            numHex[i] = toupper(character);
            putchar (toupper(character));
            i++;
        }
    } while(character!=13 && i<MAXCHAR);//if value is not in hexadecimal, it will not read it.
}//ok

int removezeroes(char numHex[MAXCHAR], char nozerosHex[MAXCHAR]){
    int i;
    int numzeros=0;
    int flag=0, len, j=0;
    len=strlen(numHex);

    for(i=0;i<=len;i++){
        if(numHex[i]=='0'&&flag!=1){numzeros++;}
        else{
            flag=1;
            nozerosHex[j]=numHex[i];
            j++;
        }
    }
    printf("\nNumber of leading zeros is %i\n",numzeros);
    return numzeros;
} //ok

int conversionHex2Dec(char numHex[MAXCHAR]){
    long long decimal, place;
    int i = 0, val, lenght;
    decimal = 0;
    place = 1;
    lenght = strlen(numHex);
    lenght--;
    for(i=0; numHex[i]!='\0'; i++){
        if(numHex[i]>='0' && numHex[i]<='9'){
            val = numHex[i] - 48;
        }
        else if(numHex[i]>='a' && numHex[i]<='f'){
            val = numHex[i] - 97 + 10;
        }
        else if(numHex[i]>='A' && numHex[i]<='F'){
            val = numHex[i] - 65 + 10;
        }
        decimal += val * pow(16, lenght);
        lenght--;
    }
    return decimal; //decimal value of nozerosHex.
}//ok

int happyNumber(char nozerosHex[MAXCHAR],char matrix[ITERATIONS][5]){//will check the sum of digits and print it.
    int number,sol,p,count=0,end,y=0;
    char continuekey;
    char matrix2[4];

    while(continuekey != 32 && sol != 1 && count<ITERATIONS){
        continuekey=getch();
        strcpy(matrix[count],nozerosHex);
        strcpy(matrix2, matrix[count]);//matrix2=matrix[count]=matrix2
        end=strlen(matrix2);
        sol = squaresum1(matrix2, end);//works ok
        conversionDec2Hex(sol,count,matrix2);//HERE IS PRINTING

        decmat4[y] = sol;
        y++;
        count++;
        nozerosHex = matrix2;
        strcpy(mat[count-1],matrix2);
    }

    if (continuekey==32){
        printf("\nThis is an user decision--Iterations stop\n");
    }
    if(count>=ITERATIONS){
        printf("\nMax number of iterations reach\n");
    }
    if(sol==1){
        happy=1;
        printf("\nHappy number!\n");
    }
    return count;
}//ok

int conversionDec2Hex(int sol, int count, char matrix2[5]){//converts sum of digits in hexadecimals for printing. //funcion ---> int nombre
    int j=4,i,k=0,remainder=0,quotient=0,temp;
    quotient=sol;//gives the int quotient the value of sol.
    for(i=0;i<5;i++){
        matrix2[i]='0';//making all values=0 so there are no mistkaes.
    }

    while(quotient!=0){
        remainder = quotient % 16;
        //To convert integer into character
        if (remainder < 10) {remainder =remainder + 48;}
        else {remainder = remainder + 55;}

        matrix2[j--]= remainder;
        quotient = quotient / 16;
    }
    printf("\nIteration %d is %s",count, matrix2);//ok
}//ok

int squaresum1 (char nozerosHex[MAXCHAR],int end, int count){ // It receives int and returns the adding of the squares of its figures.
    int start=0;
    int numD;
    int i=0;
    int sum=0;
    for (i=0;i<end;i++){
        if (nozerosHex[i]>47 && nozerosHex[i]<58){//in case of characters
            sum+=pow((nozerosHex[i]-48),2);//converting it to decimal
        }
        else{
            sum+=pow((nozerosHex[i]-55),2);//converting to decimal.
        }
    }
    return sum;//returns sum of squares in decimal.//ok
}//ok

int fmatrix(char matrix[ITERATIONS][5], int count){//print matrix
    char matfinal[ITERATIONS][5];
    int i,j;
    char continuekey;
    printf ("\nPress any key to show the bidimensional array\n");
    continuekey=getch(); //print matrix
    for (i=0;i<count;i++){
        for (j=0;j<5;j++){
            putchar (mat[i][j]); //uses array(2dmatrix) from dectohex function
        }
        printf ("\n");
    }
}//ok

void count_frequency(int*data,int size){
    int i=0,j=0,count=0;
    char hex3[6];
    for(i;i<size-1;i++){
        count=0;
        for(j=0;j<size;j++){
            if(j<i && data[i]==data[j]){break;}
            else if(data[i]==data[j]){count++;}
        }
        if(count>1 && data[i] != 0){
            int u=4;
            int t;
            int remainder3=0, quotient3=0;
            quotient3=decmat4[i];//gives the int quotient the value of sol.
            for(t=0;t<5;t++){
                hex3[t]='0';//making all values=0 so there are no mistkaes.
            }
            while(quotient3!=0){
                remainder3=quotient3%16;
                if (remainder3<10&&remainder3>0){
                    hex3[u--]=remainder3+48;
                }
                else{
                    hex3[u--]=remainder3+55;
                }
                quotient3=quotient3/16;
            }
            oke=0;
            printf("\n%s repeats %d Times", hex3,count);
        }
    }
    if(oke == 1){
        if (happy!=1){
            oke=-1;//inconclusive
        }
        printf("\nNo repeats, no conclusions can be taken");
    }
}

int numreps(int count,char matfinal[ITERATIONS][5]){//see if any string repeats within big matrix ---mat[count][5]
    printf("\nPress any key to show if there are any repeated strings\n");
    char continuekey;
    continuekey=getch();

    int siz = sizeof(decmat4) / sizeof(decmat4[0]);
    count_frequency(decmat4, siz);
}

int repetitions(int count){//counts how many times a character or number is repeated in the whole matrix. (fmatrix printed)
    printf("\nPress any key to see repetitions of values in string\n");
    char continuekey;
    continuekey=getch();
    char repetitions[17]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G'};
    int num_of_reps[17] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int i;
    int j;
    int l;
    int indicator = 0;
    int leadingzeros = 0;

    for (i = 0; i <= count; i++){
        indicator=0;
        for (j = 0; j < 5; j++){
            if(mat[i][j] != '0'){
                indicator = 1;
            }
            else if(indicator==0){
                leadingzeros = leadingzeros + 1;
            }
            switch (mat[i][j]){
                case '0': num_of_reps[0] = num_of_reps[0] + 1; break;
                case '1': num_of_reps[1] = num_of_reps[1] + 1;  break;
                case '2': num_of_reps[2] = num_of_reps[2] + 1;  break;
                case '3': num_of_reps[3] = num_of_reps[3] + 1;  break;
                case '4': num_of_reps[4] = num_of_reps[4] + 1;  break;
                case '5': num_of_reps[5] = num_of_reps[5] + 1;  break;
                case '6': num_of_reps[6] = num_of_reps[6] + 1;  break;
                case '7': num_of_reps[7] = num_of_reps[7] + 1;  break;
                case '8': num_of_reps[8] = num_of_reps[8] + 1;  break;
                case '9': num_of_reps[9] = num_of_reps[9] + 1;  break;
                case 'A': num_of_reps[10] = num_of_reps[10] + 1;  break;
                case 'B': num_of_reps[11] = num_of_reps[11] + 1;  break;
                case 'C': num_of_reps[12] = num_of_reps[12] + 1;  break;
                case 'D': num_of_reps[13] = num_of_reps[13] + 1;  break;
                case 'E': num_of_reps[14] = num_of_reps[14] + 1;  break;
                case 'F': num_of_reps[15] = num_of_reps[15] + 1;  break;
                case 'G': num_of_reps[16] = num_of_reps[16] + 1;  break;
            }
        }
    }
    printf("\nNumber of leading 0's is %d",leadingzeros);
    for(l = 0; l <= 16; l++){
        printf("\nValue %c is repeated %i times", repetitions[l], num_of_reps[l]);
    }
}//ok

int showBigaSmallnumH(int count){//function to show biggest and smallest value of fmatrix--matrix printed.matrix[count][5](all of count)
    char continuekey;
    printf("\nPress any key to show highest and lowest values\n");
    continuekey=getch();
    int i,k,p;
    int max;
    int min;
    int MaPos;
    int MiPos;

    max=0;
    min= decmat4[0];

    for (i=0;i<count;i++){
        if (decmat4[i]>max){
            max=decmat4[i];
            MaPos=i;//this shows the maximum position in the array
        }
        if (decmat4[i]<min){
            min=decmat4[i];
            MiPos=i;//this shows the minimum position in the array
        }
    }

    int u=4;
    int t;
    int remainder3=0, quotient3=0;
    char hex3[5];
    quotient3=decmat4[MaPos];//gives the int quotient the value of sol.
    for(t=0;t<5;t++){
        hex3[t]='0';//making all values=0 so there are no mistkaes.
    }
    while(quotient3!=0){
        remainder3=quotient3%16;
        if (remainder3<10&&remainder3>0){
            hex3[u--]=remainder3+48;
        }
        else{
            hex3[u--]=remainder3+55;
        }
        quotient3=quotient3/16;
    }

    int z=4;
    int v;
    int remainder2=0, quotient2=0;
    char hex4[5];
    quotient2=decmat4[MiPos];//gives the int quotient the value of sol.
    for(v=0;v<5;v++){
        hex4[v]='0';//making all values=0 so there are no mistkaes.
    }
    while(quotient2!=0){
        remainder2=quotient2%16;
        if (remainder2<10&&remainder2>0){
            hex4[z--]=remainder2+48;
        }
        else{
            hex4[z--]=remainder2+55;
        }
        quotient2=quotient2/16;
    }
    printf("\nHighest value is: ");
    for(i=0;i<5;i++){
        printf("%c",hex3[i]);
    }
    printf("\nLowest value is:  ");
    for(i=0;i<5;i++){
        printf("%c",hex4[i]);
    }
}

int End_program(){
    printf("\nPress any key to end program\n");
    char continuekey;
    continuekey=getch();
    return 0;
}

