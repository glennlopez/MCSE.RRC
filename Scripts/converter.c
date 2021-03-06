//FIXME: error when ip is set to 0.0.0.0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DWORD 32
#define WORD 16
#define OCTET 8
#define NIBBLE 4
typedef enum {false, true} bool;

//SUBROUTINE PROTOTYPES 
int extractToGlobal(char*);

int system(const char*);            //system calls
void welcome(void);                 //reserved for welcome ascii art
int convertBin(int, int*);          //convert(decimal to binary, stored at an array[])
int convertDec(int*);               //convers binary from an array[] and returns decimal
void printArray(int*);              //print(contents of array[])
void calcAND(int*, int*, int*);     //Logic AND calculator func(binary, binary, store results in array[])

//GLOBAL VARIABLES (dirty values)
int hostContainer[1][4];
int subnetContainer[1][4] = {255,255,255,255};
int networkContainer[1][4];

//binary storage for bitwise calculations
    //FIXME: store binary using 2d arrays (might be usefull in the future)
int host[OCTET];                    //stores user input
int subnet[OCTET];                  //stores user subnet mask
int network[OCTET];                 //stores result (network address)

char command[150];                  //used for system() calls to OS layer commands
bool halt = false;                  //global halt on error

//MAIN ROUTINE
int main(int argc, char* argv[]) { char usrStr[20];

    //FIXME: command line arguments may not work for Windows
    if(argc != 2){
        welcome();
        printf("Convert: ");
        scanf("%s", usrStr);
    }
    else{
        for(int i = 0; argv[1][i] != '\0'; i++){
            usrStr[i] = argv[1][i];
        }
    }

    extractToGlobal(usrStr);
    


    //DEBUG - print outs
    printf("hostContainer 0: %i\n", hostContainer[0][0]);
    printf("hostContainer 1: %i\n", hostContainer[0][1]);
    printf("hostContainer 2: %i\n", hostContainer[0][2]);
    printf("hostContainer 3: %i\n", hostContainer[0][3]);

    convertBin(hostContainer[0][0], host);
    printf("Host: ");
    printArray(host);

    convertBin(subnetContainer[0][3], subnet);
    printf("Subnet: ");
    printArray(subnet);

    calcAND(host, subnet, network);

    printf("Network: ");
    printArray(network);

    printf("Dec: %i\n", convertDec(host));
    printf("And: %i\n", convertDec(network));

    return(0);
} 




//STRING EXTRACTION SUBROUTINE
int extractToGlobal(char* param){

    char stringTemp[4][4];
    int intTemp[4];
    int octetIndex = 0;
    int bitIndex = 0;
    
    //extraction routine
    for(int i = 0; param[i] != '\0'; i++){

        if(param[i] == '.'){
            octetIndex++;
            bitIndex = 0;
            i++;
        }

        stringTemp[octetIndex][bitIndex] = param[i];
        bitIndex++;

        hostContainer[0][octetIndex] = atoi(stringTemp[octetIndex]);
    }

    //sanity check routine
    if((octetIndex > 3) || (octetIndex < 3)){
        halt = true;
        printf("Error: Invalid IPv4 address.\n");
        return 0;
    }
    for(int i = 0; i < 4; i++){
        if((int)(hostContainer[0][i] > 255) || ((int)hostContainer[0][i] < 0 )){
            printf("Error: IP address has an out of range octet.\n");
            halt = true;
            return 2;
        }
    }

    //FIXME: add routine for converting CIDR notation to 32bit binary
    /*
                8           16          24          32  
             1111 1111 . 1111 1111 . 1111 1111 . 1111 1111
        /16  1111 1111 . 1111 1111 . 0000 0000 . 0000 0000
        /28  1111 1111 . 1111 1111 . 1111 1111 . 1111 0000 
        /14  1111 1111 . 1111 1100 . 0000 0000 . 0000 0000


    */
    int cidr = 14;
    int subnetAdr[] ={
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    };


    return 0;
}



//AND-MASK SUBROUTINE
void calcAND(int* param1, int* param2, int* result){

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
int convertBin(int param, int* param2){ int count = 0;
    
    //bus error protection
    if(halt == true){
        return 2;
    }
    

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



//WELCOME SUBROUTINE
void welcome(void){
    system("clear");

    //Program Title
    printf("     _________    ___.  v1.0            __    __                            \n");
    printf("    /   _____/__ _\\_ |__   ____   _____/  |__/  |_  ___________            \n");
    printf("    \\_____  \\|  |  \\ __ \\ /    \\_/ __ \\   __\\   __\\/ __ \\_  __ \\  \n");
    printf("    /        \\  |  / \\_\\ \\   |  \\  ___/|  |  |  | \\  ___/|  | \\/     \n");
    printf("   /_______  /____/|___  /___|  /\\___  >__|  |__|  \\___  >__|             \n");
    printf("           \\/          \\/     \\/     \\/                \\/              \n");

    //Author
    printf("                                  by: github.com/glennlopez                  \n");

    //About the program
    printf("\n");
}