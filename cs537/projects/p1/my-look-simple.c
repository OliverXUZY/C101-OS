#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define MAXLEN 255

// this my-look-simple must take 2 argument, one is file, one is string to compare  (ex: ./my-look-simple dictionary gn)

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("Error! Must have 2 input: file and string to compare.\n");
        exit(1);
    } 
    
    char* inputFile = argv[1];  // file to be scanned
    char* strCmp = argv[2];    //string to be compared
    char buffer[MAXLEN];

    int totalLines = 0;  // total line count
    int getLines = 0;    // lines begin with strCmp count
    int strLen = strlen(strCmp);

    FILE* fpointer = fopen(inputFile, "r");
    if(fpointer == NULL){
        printf("Error! Cannot open file, file does not exist");
        exit(1);
    }

    while(fgets(buffer, MAXLEN, fpointer)){
        totalLines++;
        if(strncasecmp(buffer, strCmp, strLen) == 0){ // strncasecmp ignore cases!
            printf("%s", buffer);
            getLines++;
        }
    }


  
}