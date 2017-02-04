/*** sort.c ****
 *  Theodore Lessman
 *  CIS314
 *  Assignment 3
 *  2017.02.03
 *  
 *  
 *
***/

#include <stdio.h>
#include <stdlib.h>

void swap(int* xp, int* yp);

void printArray(int* arr, int s);

void selSortArray(int* arr, int s);

int main(){
	int a_size;
	printf("Enter size of array: ");
	scanf("%d", &a_size);
	
	int* array = malloc(a_size * sizeof(int));
	
	int i;
	for (i = 0; i < a_size; i++){
		printf("Enter value for array[%d]: ", i);
		scanf("%d", (array+i));
	}
	
	printf("Your array before swapping: \n");
	printArray(array, a_size);
	selSortArray(array, a_size);
	printf("Your array after swapping: \n");
	printArray(array, a_size);
	
	free(array);	
	
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
		printf("%d:[%d]\n", i, *(arr+i));  //*(arr+i) == arr[i]
	}
}

/* selSortArray(int*, int)
 *  Selection sort
 *  
 */
void selSortArray(int* arr, int s){                 //fairly familiar with C++, i had wanted to get practice working in *ptr+i form as opposed to array[i] form
	int i, j;
	int small;
	for (i = 0; i < s-1; i++){
		small = *(arr+i);                   //smallest = array[i]
		for (j = i; j < s; j++){ 
			if(*(arr+j) < *(arr+small)) //if arr[j] is smaller than small (which is equal to arr[i] for first iteration, j if subsequent)   
							//- i see *(arr+small) works here, but it feels like it shouldnt. *(arr+small) == arr[small]? 
							//small = the value in arr[i] initially, but later the index of j.
				small = j;          //then set small = j
		}
		swap(arr+small, arr+i);             //perform pointer-based swap
	}
	
}
