// Copyright [year] <Copyright Owner>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define MAXLEN 100

// function to reverse string


void reverse(char* inputString, char* reversed) {
    int size = 0;  // size of input String, include NULL end '\0'
    // since fgets capture '\n', user enter, detect it to measure size of string
    // and replace '\n' with '\0'
    while (inputString[size] != '\n' && inputString[size] !='\0') {
        size++;
    }
    int lastIndex = size - 1;
    for (int id = 0; id < size; id++) {
        reversed[id] = inputString[lastIndex];
        lastIndex--;
    }
    if (inputString[size] == '\0') {
        reversed[size] = '\0';
    } else {
        reversed[size] = '\n';
        reversed[size+1] = '\0';
    }
}


int main(int argc, char* argv[]) {
    int opt;
    char* inputFile;
    char buffer[100];
    // char* buffer = (char*)calloc(100, sizeof(char));
    char reversed[100];
    // char* reversed = (char*)calloc(100, sizeof(char));
    while ((opt = getopt(argc, argv, "::Vhf:")) != -1) {
        switch (opt) {
        case 'V':
            printf("my-rev from CS537 Summer 2021\n");
            exit(0);
        case 'h':
            printf("Reverse each line of a file on a"
             "character-by-character basis.\n");
            exit(0);
        case '?':
            printf("my-rev: invalid command line\n");
            exit(1);
        case ':':
            printf("this option needs a value, no argument is given.\n");
            exit(0);
        case 'f':
            // printf("filename: %s\n", optarg);
            inputFile = optarg;

            FILE* fpointer = fopen(inputFile, "r");
            if (fpointer == NULL) {
                printf("my-rev: cannot open file\n");
                exit(1);
            }
            while (fgets(buffer, MAXLEN, fpointer)) {
                reverse(buffer, reversed);
                printf("%s", reversed);
                }
            }
            exit(0);
        }

    // optind for checking too many arguments(test 10)
    optind++;
    for (; optind < argc; optind++) {
        if (argv[optind] != NULL) {
            // printf("extra arguments: %s\n", argv[optind]);
            printf("my-rev: invalid command line\n");
            exit(1);
        }
    }
    // printf("Input a string\n");
    while (fgets(buffer, 100, stdin)) {
        reverse(buffer, reversed);
        fprintf(stdout, "%s", reversed);
    }
    // free(buffer);
    // free(reversed);
}

