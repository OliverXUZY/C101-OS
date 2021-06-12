#include<stdio.h>
#include<stdlib.h>

int main(){

    // w: write
    // r: read
    // a: append
    char line[255];
    FILE * fpointer = fopen("files/employee.txt", "r");
    fgets(line, 255, fpointer);

    printf("%s", line);
    //puts(line);
    fclose(fpointer);
}