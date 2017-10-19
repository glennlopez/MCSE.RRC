#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DWORD 32
#define WORD 16
#define OCTET 8
#define NIBBLE 4

//SUBROUTINE PROTOTYPES 
void convert(int, int*);    //convert(decimal to binary, stored at an array[])
void printArray(int*);      //print(contents of array[])
void calcNetwork(int*);     //calculateNetworkAddress(store the result at an array[])

//GLOBAL VARIABLES
    //FIXME: use 2 dimentional arrays for storing IP numbers
int host[DWORD];                       //stores user input in binary
int subnet[DWORD] = {1,1,1,0,1};       //stores user subnet mask in binary
int network[DWORD];                    //stores result of host AND-ed subnet


//MAIN ROUTINE
int main() {

    //FIXME: Make use of command line arguments to get the number to convert

    //FIXME: Make user prompt a subroutine
    //User prompt for ip
    char usrStr[10];
    printf("Decimal to convert: ");
    scanf("%s", usrStr);
    int usrInt = atoi(usrStr);

    convert(usrInt, host);
    printArray(host);
    printArray(subnet);
    printArray(network);

/*  COMPILING IN WINDOWS:
        This needs to be compiled using TDM-GCC MinGW Compiler
        in windows (install that first). Then type "gcc subnetter.c -o subnetter" 
        in the command prompt to make an exe out of this source code
*/

/*  COMPILING IN WINDOWS:
        char command[50];
        system(command);
        system("pause");
*/
    return(0);
} 



//NETWORK ADDRESS CALCULATION SUBROUTINE
void calcNetwork(int* param){
    //FIXME: make this happen
}


//PRINT OUT SUBROUTINE
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
void convert(int param, int* param2){ int count = 0;

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