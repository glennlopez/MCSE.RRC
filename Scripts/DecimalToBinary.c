#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//PROTOTYPES 
void convert(int, int*);

//GLOBAL VARIABLES
int host[32];

/*
    This needs to be compiled using TDM-GCC MinGW Compiler
    in windows (install that first). Then type "gcc subnetter.c -o subnetter" 
    in the command prompt to make an exe out of this source code
*/


//MAIN ROUTINE
int main () {

    //User prompt for ip
    char usrStr[10];
    printf("Decimal to convert: ");
    scanf("%s", usrStr);
    int usrInt = atoi(usrStr);

    convert(usrInt, host);

    //print output to screen
    for(int i = 32; i >= 0; i--){
        printf("%i", host[i]);
    }
    printf("\n");

    return(0);
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