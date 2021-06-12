# include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{

  char name[] =  "John";
  printf("hello, world\n");

  if(argc != 2){
    //printf("No input, print some name: %s\n",name);
    fprintf(stderr, "usage: cpu <string>\n");
    //exit(1);

  } else {
    char* str = argv[1];
    printf("This is input name: %s", str);
  }
  printf("hello, world\n");
  fprintf(stdout, "Hello!\n");
  

}
