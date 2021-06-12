#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>
#include<fcntl.h>

#define MAXLEN 512
#define MAXTOKENS 100

// replace last \n with \0, return the size of string
int replace(char* inputString) {
    int lastIndex = strcspn(inputString, "\n");
    inputString[lastIndex] = '\0';
    return lastIndex;
}

// detect exit
int quit(char* inputString) {
    if(strcasecmp(inputString, "exit") == 0) {
        return 1;
    }
    return 0;
}

// trim (while space of) the string
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

char* fileString;
char* cmdString;
// this function detect '>' to redirect output to a file
int redirection(char* inputString) {
    int size = strcspn(inputString, "\0");
    int index = strcspn(inputString, ">");

    // no redirection, didn't find '>' match
    if(index == size) {
        return 1;
    }

    // 1. detect "> file.txt" case
    if(index == 0) {
        return -1;
    }
    //
    fileString = malloc(size-index);
    memcpy(fileString, &inputString[index+1], size - index);
    fileString = trim(fileString);

    // 2. detect "/bin/ls >" case
    if(fileString == NULL){
        return -1;
    }

    cmdString = malloc(index);
    strncpy(cmdString, inputString, index);
    cmdString = trim(cmdString);

    // 3. detect "/bin/ls > file1.txt file2.txt" or "/bin/ls > > file.txt" case
    if(strcspn(fileString, " >") != strcspn(fileString, "\0")) {
        return -1;
    }
    return 0;
}

// this function tokenize input string to array of arguments
char** tokenize(char* inputString) {
    char* token;
    char** tokens = (char**)calloc(MAXTOKENS, sizeof(char*));;
    token = strtok(inputString, " \t");
    int index = 0;
    while (token != NULL)
    {
        tokens[index] = token;
        index++;
        token = strtok(NULL, " \t");
    }
    tokens[index] = NULL;
    return tokens;
}

// execute command
void execute(char** args) {
    pid_t pid = fork();
    if(pid < 0) {
        perror("fork failed\n");
    } else if(pid == 0) {
        int ret = execvp(args[0], args);
        perror("job: Command not found.\n");
        exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}

int main(){
    char* line;
    char* args;
    int status = 1;
    char input[MAXLEN];
    // interactive mode
     while (1)
     {
        write(1, "mysh> ", strlen("mysh> "));
        if(!fgets(input, MAXLEN, stdin)){
            continue;
        }
        int size = replace(input);
        if(quit(input)) {
            exit(0);
        }
        int redirect = redirection(input);
        //printf("This is %d", redirect);
        // no redirec case
        if(redirect == 1) {
            //printf("This is %d", redirect);
            char** tokens = tokenize(input);
            execute(tokens);
            continue;
        } else if (redirect == -1) {
            //printf("This is %d", redirect);
            printf("Redirection misformatted.\n");
            fflush(stdout);
            continue;
        } else if (redirect == 0) {
            //printf("This is %d", redirect);
            //printf("file: %s\nCmd: %s\n", fileString, cmdString);
            char** tokens = tokenize(cmdString);

            pid_t pid = fork();
            if(pid < 0) {
                perror("fork failed\n");
            } else if(pid == 0) {
                int fd = open(fileString, O_RDWR | O_CREAT | O_TRUNC, 0644);
                dup2(fd, fileno(stdout)); 
                
                int ret = execvp(tokens[0], tokens);
                close(fd);
                perror("job: Command not found.\n");
                exit(1);
            } else {
                int status;
                waitpid(pid, &status, 0);
            }
            
            //free(fileString);
            //free(cmdString);
            continue;
        }
        /*
        for (int i = 0; i < 10; i++){
            printf("%s\n", tokens[i]);
        }
        
        char *myargs[3];
        myargs[0] = strdup("ls"); // program: "wc" (word count) 
        myargs[1] = strdup("-l"); // argument: file to count 
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
        */
    
     }
     exit(0);
     
}