# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct Student // class in java/python
{
    char name[50];
    char major[50];
    int age;
    double gpa;
};

union value {
    int i;
    float f; 
};


int main(){
    struct Student student1;
    student1.age = 22;
    student1.gpa = 3.2;
    strcpy( student1.name, "Jim");
    strcpy( student1.major, "Business");

    struct Student student2;
    student2.age = 24;
    student2.gpa = 3.8;
    strcpy( student1.name, "Oliver");
    strcpy( student1.major, "Stat");

    printf("%f and %f\n", student1.gpa, student2.gpa);

    union value v;
    v.i = 123; // Set v to bits of integer 123 
    printf("%d, %f\n", v.i, v.f); // Interpret bits of 123 as float


}