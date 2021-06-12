# include <stdio.h>

// use side-effect, we should work with pointerr
int test_and_dec(int* ip) { 
    if (*ip >= 0) {
        *ip -= 1;
        return 1;
    } else {
        return 0; 
    }
}

int main(){
    int i = 123;
    if (test_and_dec(&i)) {
        printf("i is now one less than before, possibly 0, %d",i);
    } else { 
        printf("i was already <= 0 ");
    }
}


