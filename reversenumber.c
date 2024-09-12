#include<stdio.h>

int main(){
    int num;
    printf("Enter the number: \n");
    scanf("%d",&num);

    int temp = 0;
    while(num!=0){
        int k = num%10;
        temp = temp*10 + k;
        num = num/10;
    }

    printf("REVERSE : %d",temp);
    return 0;

}