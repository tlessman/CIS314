#include <stdio.h>

void swap(int* xp, int* yp);

int main(){
	int a_size;
	printf("Enter size of array: ");
	scanf("%d", &a_size);
	int* array = malloc(a_size * sizeof(int));
	int i;
	for (i = 0; i < a_size; i++){
		printf("Enter value for array[%d]: ", i);
		scanf(%d, array+i);
	}


	return 0;
}

void swap(int* xp, int* yp){
	int x = *xp;
	int y = *yp;
	*yp = x;
	*xp = y;
}


