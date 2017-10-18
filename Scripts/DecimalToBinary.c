#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//PROTOTYPES 
void convert(int, int*);    //converts decimal to binary
void printArray(int*);      //print contents of array[]

//GLOBAL VARIABLES
int host[32];               //stores user input in binary
int subnet[32];             //stores user subnet mask in binary



//MAIN ROUTINE
int main () {

    //FIXME: Make use of command line arguments to get the number to convert

    //User prompt for ip
    char usrStr[10];
    printf("Decimal to convert: ");
    scanf("%s", usrStr);
    int usrInt = atoi(usrStr);

    convert(usrInt, host);
    printArray(host);

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



//PRINT OUT SUBROUTINE
void printArray(int* param){
    for(int i = 31; i >= 0; i--){
        printf("%i", param[i]);

        //octet spacer
        if(!(i % 8)){
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