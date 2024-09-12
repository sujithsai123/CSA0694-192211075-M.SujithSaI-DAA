#include<stdio.h>

int main(){
    int n;
    printf("enter n : \n");
    scanf("%d",&n);
    int sum =0;

    while(n!=0){
        int k = n%10;
        sum = sum + k;
        n = n/10;
    }

    printf("Sum : %d",sum);
}