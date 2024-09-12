#include<stdio.h>

int fact(int x){
    if(x<=1){
        return 1;
    }
    else{
        return (x*fact(x-1));
    }
}
int main(){
    int n;
    printf("enter n: \n");
    scanf("%d",&n);

    int i,j,k,f;
    for(i=0;i<n;i++){
        for(j =  n; j>=i;j-- ){
            printf(" ");
        }
        for(k=0;k<=i;k++){
            f = ( fact(i)/ (fact(k) * fact( i-k)));
            printf("%d ",f);
        }
        printf("\n");
    }
    
}