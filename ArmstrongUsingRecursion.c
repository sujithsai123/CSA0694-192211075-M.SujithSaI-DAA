#include<stdio.h>

int armstrong(int n){
    if(n>0){
        int x = n%10;
        int val = x*x*x;
        n = n/10; // 
        return val + armstrong(n);
    }
    else{
        return 0;
    }
}

int main(){
    int num;
    printf("Enter input: ");
    scanf("%d",&num);

    int temp = num;

    if(armstrong(num)==temp){
        printf("It is Armstrong ");
    }
    else{
        printf("It is Not Armstrong ");
    }

    return 0;
}
