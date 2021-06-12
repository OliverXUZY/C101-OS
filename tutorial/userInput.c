# include <stdio.h>

int main(){
    int age;
    char name[20];
    double gpa;


    int size = 0;
    printf("Enter your name capture whole line: \n");
    fgets(name, 20, stdin);
    printf("Your name is %s", name);
    while (name[size] != '\0') {
        size++;
    }
    printf("%d\n", size);

/*
    printf("Enter you age:");
    scanf("%d", &age);
    printf("You are %d years old.", age);

    printf("\nEnter you name:");
    scanf("%s", name);
    printf("Your name is %s \n", name);

    printf("Enter you GPA:");
    scanf("%lf", &gpa);
    printf("Your GPA is %f \n", gpa);
    printf("%lu\n", sizeof(gpa));
*/

    


    





    
}