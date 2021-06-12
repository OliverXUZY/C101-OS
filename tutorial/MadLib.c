# include <stdio.h>

int main(){

    char color[20];
    char pluralNoun[20];
    char celebeityF[20];
    char celebeityL[20];

    printf("Enter a color: ");
    scanf("%s", color);
    printf("Enter a pluralNoun: ");
    scanf("%s", pluralNoun);
    printf("Enter a celebrity: ");
    scanf("%s%s", celebeityF, celebeityL);



    printf("Roses are %s\n", color);

    printf("%s are blue\n", pluralNoun);

    printf("I love %s %s", celebeityF, celebeityL);


}