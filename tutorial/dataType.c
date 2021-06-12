# include <stdio.h>

int main(){
    int age = 24;
    double gpa = 3.8;
    char grade = 'A';
    char phrase[] = "Giraff";
    const int NUM = 24; // final in java
    printf("%c\n",grade);
    printf("%d\n", age);
    printf("The %s is %d and %f", "number", 500, 4.55);
    printf("\nThis is constant number %d", NUM);

    printf("\nThis is a double number: %lf \n", gpa);

    printf("This is the %s \n", phrase);



}