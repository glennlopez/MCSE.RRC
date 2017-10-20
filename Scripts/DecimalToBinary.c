#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DWORD 32
#define WORD 16
#define OCTET 8
#define NIBBLE 4

//SUBROUTINE PROTOTYPES 
void convertBin(int, int*);         //convert(decimal to binary, stored at an array[])
int convertDec(int*);               //convers binary from an array[] and returns decimal
void printArray(int*);              //print(contents of array[])
void calcAND(int*, int*, int*);     //Logic AND calculator func(binary, binary, store results in array[])

//GLOBAL VARIABLES
    //FIXME: use 2 dimentional arrays for storing IP numbers
int host[DWORD];                       //stores user input in binary
int subnet[DWORD] = {0,1,1,1};       //stores user subnet mask in binary using cidr notation
int network[DWORD];                    //stores result of host AND-ed subnet


//MAIN ROUTINE
int main(int argc, char* argv[]) { char usrStr[10];

    //Command-line argument 
    if(argc != 2){
        printf("Decimal to convert: ");
        scanf("%s", usrStr);
    }
    else{
        for(int i = 0; argv[1][i] != '\0'; i++){
            usrStr[i] = argv[1][i];
        }
    }
    int usrInt = atoi(usrStr);

    //DEBUG - print outs
    convertBin(usrInt, host);
    printf("A: ");
    printArray(host);

    printf("B: ");
    printArray(subnet);

    calcAND(host, subnet, network);

    printf("Z: ");
    printArray(network);

    return(0);
} 



//NETWORK ADDRESS CALCULATION SUBROUTINE
void calcAND(int* param1, int* param2, int* result){
    //FIXME: make this happen
    int BITLIMIT = OCTET;
    
    for(int i = 0; i < BITLIMIT; i++){
        result[i] = param1[i] & param2[i];
    }
}



//PRINT-OUT SUBROUTINE
void printArray(int* param){
    int outputSize = OCTET;
    for(int i = (outputSize-1); i >= 0; i--){
        printf("%i", param[i]);

        //octet spacer
        if(!(i % OCTET)){
            printf(" ");
        }

    }
    printf("\n");
}



//DECIMAL TO BINARY SUBROUTINE
void convertBin(int param, int* param2){ int count = 0;

    //Divide n by 2 and store remainder as a binary 1 until n = 1
    if(param == 1){
        param2[0] = 1;
    }

    while(param != 1){
        if(param % 2){
            param2[count] = 1;
        }
        else{
            param2[count] = 0;
        }

        param /= 2;

        if(param == 1){
            param2[count + 1] = 1;
        }

        count++;
    }
}



//BINARY TO DECIMAL SUBROUTINE
int convertDec(int* param){
    //FIXME: make this happen
    return 0;
}