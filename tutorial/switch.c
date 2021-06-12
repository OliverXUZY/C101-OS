# include <stdio.h>

int main(){

    char grade = 'E';

    switch(grade){
        case 'A':
            printf("You did great!");
            break;
        case 'B':
            printf("Alright");
            break;
        case 'C':
            printf("poorly");
            break;
        case 'D':
            printf("Very bad");
            break;
        case 'F':
            printf("Fail");
            break;
        
        default :
        printf("invalid grade");
    }

}