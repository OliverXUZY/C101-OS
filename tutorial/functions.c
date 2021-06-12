# include <stdio.h>

void sayHi(char name[], int age){
    printf("Hello User %s, you are %d\n", name, age);
}

// prototype, allow double() function create below main()
double cube(double num);

int main(){
    sayHi("Joey", 24);

    printf("The answer is %f\n", cube(3));
}

double cube(double num){
    double result = num * num * num;
    return result;
}