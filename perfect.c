#include <stdio.h>

int main()
{
    int n;
    printf("Enter n : \n");
    scanf("%d", &n);

    int sum = 0;

    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum = sum + i;
        }
    }

    if(sum==n){
        printf("Perfect");
    }
    else{
        printf("Not Perfect");
    }
}