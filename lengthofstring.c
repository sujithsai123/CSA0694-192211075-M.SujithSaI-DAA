#include<stdio.h>
#include<string.h>

int main(void)
{
    char mystrg[60];
    int leng, g;

    printf("enter input: \n");
    scanf( "%s", &mystrg );

    leng = strlen(mystrg);

    printf("Length : %d",leng);

}