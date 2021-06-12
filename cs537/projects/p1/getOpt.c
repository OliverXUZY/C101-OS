#include <stdio.h> 
#include<stdlib.h>
#include <unistd.h> 

// example from https://www.geeksforgeeks.org/getopt-function-in-c-to-parse-command-line-arguments/

int main(int argc, char *argv[]) 
{
    int opt;
      
    // put ':' in the starting of the
    // string so that program can 
    //distinguish between '?' and ':' 
    while((opt = getopt(argc, argv, ":if:lrx")) != -1) 
    { 
        switch(opt) 
        { 
            case 'i': 
            case 'l': 
            case 'r': 
                printf("option: %c\n", opt); 
                break; 
            case 'f': 
                printf("filename: %s\n", optarg); 
                //printf("filename: %s and %s\n", optarg,argv[optind]); 
                break; 
            case ':': 
                printf("option needs a value\n"); 
                break; 
            /*
            case '?': 
                printf("unknown option: %c\n", optopt);
                exit(1);
                //break; 
            */
            default:  // same as  ?
                printf("no option.");
                break;
            case 'x':
                printf("x\n");
                break;
        } 
    } 
    
      
    // optind is for the extra arguments
    // which are not parsed
    // optind++;
    for(; optind < argc; optind++){     
        printf("extra arguments: %s\n", argv[optind]); 
    }
      
    return 0;
}