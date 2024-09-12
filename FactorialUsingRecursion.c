#include<stdio.h>

int factorial(int n){
    if(n==1){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);

    printf("%d",factorial(n));
}
