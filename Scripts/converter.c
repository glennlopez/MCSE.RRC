#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DWORD 32
#define WORD 16
#define OCTET 8
#define NIBBLE 4

//SUBROUTINE PROTOTYPES 
void welcome(void);
int convertBin(int, int*);          //convert(decimal to binary, stored at an array[])
int convertDec(int*);               //convers binary from an array[] and returns decimal
void printArray(int*);              //print(contents of array[])
void calcAND(int*, int*, int*);     //Logic AND calculator func(binary, binary, store results in array[])

//GLOBAL VARIABLES
    //FIXME: use 2 dimentional arrays for storing IP numbers
int host[DWORD];                     //stores user input in binary
int subnet[DWORD] = {0,1,1,1};       //stores user subnet mask in binary using cidr notation
int network[DWORD];                  //stores result of host AND-ed subnet


//MAIN ROUTINE
int main(int argc, char* argv[]) { char usrStr[10];
    if(argc != 2){
        welcome();              //welcome the user
        scanf("%s", usrStr);    //grab users input
    }
    else{
        for(int i = 0; argv[1][i] != '\0'; i++){
            usrStr[i] = argv[1][i];
        }
    }
    //convert user string to int (comes from cmd-line argument and scanf)
    int usrInt = atoi(usrStr);
    //FIXME: CIDR "/" notation will create bugs for usrInt variable - use if to filter through the string

    //IP address sanity check
    if(usrInt > 255){
        printf("Error: No such IP Address.\n");
        //FIXME: replace returning error code with assuming the user wanted to convert binary to decimal
        return 2;
    }

    //DEBUG - print outs
    convertBin(usrInt, host);
    printf("A: ");
    printArray(host);

    printf("B: ");
    printArray(subnet);

    calcAND(host, subnet, network);

    printf("Z: ");
    printArray(network);

    printf("Dec: %i\n", convertDec(host));
    printf("And: %i\n", convertDec(network));

    return(0);
} 



//AND-MASK SUBROUTINE
void calcAND(int* param1, int* param2, int* result){
    int BITLIMIT = OCTET;
    
    for(int i = 0; i < BITLIMIT; i++){
        result[i] = param1[i] & param2[i];
    }
}



//WELCOME SUBROUTINE
void welcome(void){
    //FIXME: add a system() call for clearing screen
    printf("Decimal to convert: ");
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
int convertBin(int param, int* param2){ int count = 0;

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
    return 0;
}



//BINARY TO DECIMAL SUBROUTINE
int convertDec(int* param){ int result = 0;

    int BITLIMIT = OCTET;
    int binWeight[] = {1,2,4,8,16,32,64,128};

    //uses binary weight addition to convert binary to decimal
    for(int i = 0; i < BITLIMIT; i++){
        if(param[i] == 1){
            result += binWeight[i];
        } 
    }

    return result;
}