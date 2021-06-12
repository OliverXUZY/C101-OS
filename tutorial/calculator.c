# include <stdio.h>

int main(){

    double num1;
    double num2;
    char op; // operator

    printf("Enter a number: ");
    scanf("%lf", &num1);
    printf("Enter operator: ");
    scanf(" %c", &op);  // necessary to have space before %c
    printf("Enter a number: ");
    scanf("%lf", &num2);

    if(op == '+'){
        printf("%f", num1 + num2);
    } else if(op == '-'){
        printf("%f", num1 - num2);
    } else if(op == '*'){
        printf("%f", num1 * num2);
    } else if(op == '/'){
        printf("%f", num1 / num2);
    } else {
        printf("Invalid operator");
    }



}