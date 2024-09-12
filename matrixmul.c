#include<stdio.h>

int main(){
    int a[3][3], b[3][3], mul[3][3];

    printf("enter the elements of array 1 : \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("enter the elements of array 2 : \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&b[i][j]);
            mul[i][j] = 0;
        }
    }


    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                mul[i][j] = mul[i][j] + a[i][k]*b[k][j];
            }
        }
        printf("\n");
    }

    printf("MUL elements of array: \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d",mul[i][j]);
        }
        printf("\n");
    }

}