# include <stdio.h>

int main(){

    int index = 1;
    while(index <= 5){
        printf("%d\n", index);
        index++;
    }

    do {
        printf("Do while %d\n", index);
        index--;
    } while (index>=0);
}