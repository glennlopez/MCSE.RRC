#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//PROTOTYPES 
void convert(int);          //binary converter
void msg_title(void);       //welcome text

//GLOBAL VARIABLES
unsigned int host[32];      //user ip input storage
unsigned int mask[32];      //subnet ip
unsigned int network[32];   //network address

/*
    This needs to be compiled using TDM-GCC MinGW Compiler
    in windows (install that first). Then type "gcc subnetter.c -o subnetter" 
    in the command prompt to make an exe out of this source code
*/


//MAIN ROUTINE
int main () {

    char usrStr[] = "10"; //FIXME: get string 10 to convert to int 10
    int usrInt = atoi(usrStr);

    //FIXME: Create a function for configing 

    //Windows CMD START HERE
    /*
    char command[50];
    strcpy( command, "dir" );
    system(command);
    system("pause");
    */

    //DEBUG OUTPUT - for testing
    convert(usrInt);

    return(0);
} 



//TITLE MESSAGE SUBROUTINE
void msg_title(void){
    //TODO: create this function
}



//DECIMAL TO BINARY SUBROUTINE
void convert(int param){
    int uNum = param;       //user decimal input
    int uBin[32];           //binary conversion storage     //FIXME: Replace with global passbyref
    int count = 0;          //used for indexing array

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

    //DEBUT OUTPUT
    for(int i = count; i >= 0; i--){
        printf("%i", uBin[i]);

    }

}

//BINARY-AND SUBROUTINE
