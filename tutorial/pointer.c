# include <stdio.h>

int main(){
    int age = 30;
    int* pAge = &age; // pAge is a pointer

    printf("%p\n", pAge);

    printf("%d\n", *pAge); // de-referencing a pointer pAge(pAge contain address &age)

    printf("%d\n", *&age); // de-referencing the address &age

    printf("%p\n", &*&age); // get the address of *&age(*&age is 30)

    // now we change value of age by changing the value assigning at address of age
    *pAge = 25;
    printf("%d, %d", age, *pAge);


}