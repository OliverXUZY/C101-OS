# include <stdio.h>

int main(){
    int age = 30;
    //int * pAge = &age; // pAge is a pointer
    double gpa = 3.4;
    //double * pGpa = &gpa;
    char grade = 'A';
    char * pGrade = &grade;

    //%p is pointer
    printf("the address of age is %p\n", &age);
    printf("gpa: %p\n", &gpa);
    printf("grade: %p\n", &grade);

    



}