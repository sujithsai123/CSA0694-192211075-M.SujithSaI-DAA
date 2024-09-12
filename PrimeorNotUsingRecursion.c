#include<stdio.h>

int prime(int n, int i){
	int count = 0;
    if(n==i){
    	count = 0;
        return count;
    }
    else if(n%i==0){
    	count = 1;
        return count;
    }
    return prime(n,i+1);
}

int main(){
    int n;
    printf("Enter n : ");
    scanf("%d",&n);

    int  x = prime(n,2);
    if(x == 0){
        printf(" Prime");
    }
    else{
        printf("Not Prime");
    }
    return 0;
}
