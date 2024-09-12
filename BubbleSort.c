#include<stdio.h>

int main(){
	int arr[] = { 1, 2, 4, 2, 6, 1, 7};
	int i, j;
	int len = sizeof(arr)/sizeof(arr[0]);
	printf("The Given Array is = \n [ ");
	for( i = 0 ; i < len ; i++ ){
		printf("%d, ",arr[i]);
	}
	printf("]\n\n");
	for ( i = 0 ; i < len ; i++ ){
		for ( j = 0 ; j < len ; j++ ){
			if ( arr[i] <= arr[j] ){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("The Bubble Sort Array is = \n [ ");
	for( i = 0 ; i < len ; i++ ){
		printf("%d, ",arr[i]);
	}
	printf("]\n\n");
	return 0;
}
