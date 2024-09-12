#include<stdio.h>

void fibo(int n,int a,int b){
    if(n>0){
        n--;
        printf("%d ",a);
        int c = a + b;
        a = b;
        b = c;
        fibo(n,a,b);
    }
}
void main(){
    int n;
    printf("Enter input: ");
    scanf("%d",&n);

    fibo(n,0,1);
}
