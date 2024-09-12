#include<stdio.h>

int gcd1(int n1, int n2){
    if(n2 == 0){
        return n1;
    }
    else{
        return gcd1(n2,n1%n2);
    }
}

int main(){
    int n1,n2;
    printf("Enter 2 numbers :");
    scanf("%d %d",&n1,&n2);
    if ( n1 < n2 ){
        printf("%d",gcd1(n2,n1));
    }
    else{
        printf("%d",gcd1(n1,n2));
    }

}
