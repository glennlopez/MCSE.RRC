#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//PROTOTYPES 
void convert(int);
void msg_title(void);
//GLOBAL VARIABLES

/*
    This needs to be compiled using TDM-GCC MinGW Compiler
    in windows (install that first). Then type "gcc subnetter.c -o subnetter" 
    in the command prompt to make an exe out of this source code
*/


//MAIN ROUTINE
int main () {

    //Windows CMD START HERE
    /*
    char command[50];
    strcpy( command, "dir" );
    system(command);
    system("pause");
    */

    //DEBUG OUTPUT - for testing
    convert(123);


   return(0);
} 
//TITLE MESSAGE SUBROUTINE
void msg_title(void){
    printf("TITLE GOES HERE\n");
}

//DECIMAL TO BINARY SUBROUTINE
void convert(int param){
    int uNum = param;       //user decimal input
    int uBin[32];           //binary conversion storage
    int count = 0;          //used for indexing array

    //FIXME: re-code to use recursive
    //          make subroutine have modular imputs
    //          add leading zeroes for AND/OR function

    if(uNum == 1){
        uBin[0] = 1;
    }

    while(uNum != 1){
        if(uNum % 2){
            uBin[count] = 1;
        }
        else{
            uBin[count] = 0;
        }

        uNum /= 2;

        if(uNum == 1){
            uBin[count + 1] = 1;
        }

        count++;
    }

    for(int i = count; i >= 0; i--){
        printf("%i", uBin[i]);

    }

}