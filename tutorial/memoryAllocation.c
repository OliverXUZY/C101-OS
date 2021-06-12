#include <stdio.h>
#include <stdlib.h>

int main(){
    int* ip = (int*)malloc(sizeof(int));
    *ip = 9999999;
    printf("%d\n", *ip);
    free(ip);
    ip = NULL;
    //printf("%d", *ip);
}