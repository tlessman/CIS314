#include <stdio.h>
#include <stdlib.h>

void swap(int* xp, int* yp);

void printArray(int* arr, int s);

int* selSortArray(int* arr, int s);

int main(){
	int a_size;
	printf("Enter size of array: ");
	scanf("%d", &a_size);
	
	int* array = malloc(a_size * sizeof(int));
	
	int i;
	for (i = 0; i < a_size; i++){
		printf("Enter value for array[%d]: ", i);
		scanf("%d", array+i);
	}
	
	printf("Your array before swapping: \n");
	printArray(array, a_size);
	selSortArray(array, a_size);
	printf("Your array after swapping: \n");
	printArray(array, a_size);
	
	
	return 0;
}

void swap(int* xp, int* yp){
	int x = *xp;
	int y = *yp;
	*yp = x;
	*xp = y;
}

void printArray(int* arr, int s){
	int i;
	for (i = 0; i < s; i++){
		printf("%d:[%d]\n", i, *arr+i);
	}
}

void selSortArray(int* arr, int s){
	int i, j;
	int small;
	for (i = 0; i < s-1; i++){
		small = arr+i;
		for (j = i+1; j < s; j++){
			if(*arr+j < arr[small])
				small = j;
		}
		swap(&arr[small], arr+i);
	}
	
}
