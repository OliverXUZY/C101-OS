# include <stdio.h>
# include <stdlib.h>

int foo(int* numbers) {
    return numbers[0];
}

char bar(char letters[]) { // same as char bar(char* letters)
    return letters[0];
}

int main(int argc, char* argv[]){
    
    // dynamic accolation
    int numNumbers = 3;
    int numLetters = 4;

    int* numbers = (int*)calloc(numNumbers, sizeof(int));
    char* letters = (char*)calloc(numLetters, sizeof(char)); //allocate a string dynamically just like any array

    //printf("%lu\n", sizeof(letters));
    numbers[0] = 99;
    letters[0] = 'x';

    printf("%d\n", numbers[0]); 
    printf("%c\n", letters[0]);
    
    // use function foo and bar
    int numbers2[] = { 1, 2, 3 };
    char* letters2 = (char*)calloc(5, sizeof(char)); 
    letters[0] = 'x'; // ...
    printf("%d, and %c\n", foo(numbers2), bar(letters2));

    



}