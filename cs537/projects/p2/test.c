#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

char* trim(char* input) {
    // trim head space
    while(input[0] == ' ') {
        //printf("found\n");
        input++;
    }

    // detect "/bin/ls >" case
    if(*input == 0) { 
        return NULL;
    }

    // trim tail space
    // find index of last char
    char *end = input + strlen(input) - 1;
    while(end > input && end[0] == ' ') {
        end--;
    }
    end[1] = '\0';
    
    return input;
}

int main() {
    //char* inputString = "ls > a.txt";
    char* inputString = "/bin/ls > file1.txtfile2.txt";
    int size = strcspn(inputString, "\0");
    int index = strcspn(inputString, ">");
    //printf("index is %d\n", index);
    
    char* fileString = malloc(size-index);
    memcpy(fileString, &inputString[index+1], size - index);
    fileString = trim(fileString);

    
    int sizeOfFileStirng = strcspn(fileString, "\0");
    int len = strcspn(fileString,"> ");
    printf("len is %d\n", len);
    printf("len is %d\n", sizeOfFileStirng);
    //printf("%s\n", fileString);


    char* cmdString = malloc(index);
    strncpy(cmdString, inputString, index);
    cmdString = trim(cmdString);
    printf("%s\n", cmdString);

    //int len = strcspn("ia>m","\0");
    //printf("Length of initial segment matching : %d\n", len );

    
}