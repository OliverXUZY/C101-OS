#include<stdio.h>

int main(){

    // w: write
    // r: read
    // a: append
    FILE * fpointer = fopen("files/employee.txt", "w");
    // fpointer is a memory address

    fprintf(fpointer, "Jim3, Salesman\nPam, Receptionist\nOscar, Accounting\n");

    fclose(fpointer);
}