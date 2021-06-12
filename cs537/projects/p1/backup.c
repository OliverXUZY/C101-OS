/*
    char s[1000], reversed[1000];
    
    printf("Input a string\n");
    fgets(s, 1000, stdin);

    int size = 0; // size of input String, include NULL end '\0'
    while (s[size] != '\0') {
        size++;
    }

    int lastIndex = size - 1;
    for (int id = 0; id < size; id++) {
        reversed[id] = s[lastIndex];
        lastIndex--;
    }
    reversed[size] = '\0';
    printf("%s\n", reversed);

    */

   void reverse(char* inputString, char* reversed) {
    int size = 0; // size of input String, include NULL end '\0'
    // since fgets capture '\n', user enter, detect it to measure size of string
    // and replace '\n' with '\0'
    while (inputString[size] != '\n') {
        size++;
    }
    // inputString[size] =  '\0';
    int lastIndex = size - 1;
    for (int id = 0; id < size; id++) {
        reversed[id] = inputString[lastIndex];
        lastIndex--;
    }
    reversed[size] = '\0';
}

///------------------------------------------------------------ my-look.c
// Copyright [year] <Copyright Owner>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define MAXLEN 255

int main(int argc, char* argv[]) {
    int opt;   // option to make choice
    char* inputFile;
    // If an option requires a value (such as -f in our example) and no
    // value is given, getopt normally returns ?.
    // By placing a colon as the first character of the options string,
    // getopt returns: instead of ? when no value is given.
    while ((opt = getopt(argc, argv, "::Vhf:")) != -1) {
        switch (opt) {
        case 'V':
            printf("my-look from CS537 Summer 2021\n");
            exit(0);
        case 'h':
            printf("Display lines beginning with given string\n");
            exit(0);
        case '?':
            printf("my-look: invalid command line\n");
            exit(0);
        case ':':
            printf("this option needs a value, no argument is given.\n");
            exit(0);
        case 'f':
            // printf("filename: %s\n", optarg);
            inputFile = optarg;
            char* strCmp = argv[optind];
            if (strCmp == NULL) {
                printf("Error, no string to be compared!");
                exit(1);
            }
            int strLen = strlen(strCmp);

            char buffer[MAXLEN];
            int totalLines = 0;  // total line count
            int getLines = 0;    // lines begin with strCmp count
            FILE* fpointer = fopen(inputFile, "r");
            if (fpointer == NULL) {
                printf("my-look: cannot open file\n");
                exit(1);
            }

            while (fgets(buffer, MAXLEN, fpointer)) {
                totalLines++;
                // printf("%s", buffer);
                if (strncasecmp(buffer, strCmp, strLen) == 0) {
                    // strncasecmp compares string ignoring cases!
                    fprintf(stdout, "%s", buffer);
                    // printf("%s", buffer);
                    getLines++;
                }
            }
            exit(0);
        }
    }
    /*
    if (argc > 6) {
        printf("my-look: invalid command line\n");
        exit(1);
    }
    */
    char buf[MAXLEN];  // oneline input to be compared
    char* strCmp = argv[1];  // target string to be compared
    if (strCmp == NULL) {
        printf("my-look: invalid command line\n");
        exit(1);
    }
    int strLen = strlen(strCmp);
    while (fgets(buf, MAXLEN, stdin)) {
        if (strncasecmp(buf, strCmp, strLen) == 0) {
                    // strncasecmp compares string ignoring cases!
                    fprintf(stdout, "%s", buf);
                    // printf("%s", buffer);
                }
    }
    
    optind++;
    for (; optind < argc; optind++) {
        printf("extra arguments: %s\n", argv[optind]);
        // printf("my-look: invalid command line.\n");
    }
    
    return 0;
}
