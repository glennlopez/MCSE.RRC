#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DWORD 32
#define WORD 16
#define OCTET 8
#define NIBBLE 4

//SUBROUTINE PROTOTYPES 
//void getHost(char*, int*);          //char* - userstring, int* - store
void extractToGlobal(char*);

int system(const char*);            //system calls
void welcome(void);                 //reserved for welcome ascii art
int convertBin(int, int*);          //convert(decimal to binary, stored at an array[])
int convertDec(int*);               //convers binary from an array[] and returns decimal
void printArray(int*);              //print(contents of array[])
void calcAND(int*, int*, int*);     //Logic AND calculator func(binary, binary, store results in array[])

//GLOBAL VARIABLES
int host[OCTET];                    //stores user input in binary
int hostContainer[1][4];

int subnet[OCTET];                  //stores user subnet mask in binary using cidr notation
int subnetContainer[1][4] = {255,255,255,255};

int network[OCTET];                 //stores result of host AND-ed subnet
int networkContainer[1][4] = {0,0,0,0};

char command[150];                  //used for system() calls to OS layer commands


//MAIN ROUTINE
int main(int argc, char* argv[]) { char usrStr[20];

    if(argc != 2){
        welcome();              //welcome the user
        printf("Convert: ");
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



    
    extractToGlobal(usrStr);
    
    
    

    //DEBUG - print outs
    printf("hostContainer 0: %i\n", hostContainer[0][0]);
    printf("hostContainer 1: %i\n", hostContainer[0][1]);
    printf("hostContainer 2: %i\n", hostContainer[0][2]);
    printf("hostContainer 3: %i\n", hostContainer[0][3]);

    convertBin(usrInt, host);
    printf("Host: ");
    printArray(host);

    convertBin(subnetContainer[0][3], subnet);  //DEBUG
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
void extractToGlobal(char* param){

    char stringTemp[4][4];
    int intTemp[4];
    int octetIndex = 0;
    int bitIndex = 0;
    
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