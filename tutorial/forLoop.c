# include <stdio.h>

int main(){

    int luckyNumbers[] = {4,8,7,1,9,0};
    for(int i = 0; i <=5; i++){
        printf("%d\n", luckyNumbers[i]);
    }

    int nums[3][2] = {{1,2}, {3,4}, {5,6}};
    //printf("%lu\n", sizeof(nums)/sizeof(nums[0]));
    for(int i = 0; i < 3  ; i++){
        for(int j = 0; j <2; j++){
            printf("%d", nums[i][j]);
        }
        printf("\n");
    }
}