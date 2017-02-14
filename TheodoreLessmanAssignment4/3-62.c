/**
 * A. M = 13 //bytes in row / bytes in int = 52 / 4
 * j in esi, i in ecx
**/

/**
 * .L3:
 * 	movl (%ebx), %eax            //eax = A  (mArr)
 * 	movl (%esi, %ecx, 4), %edx   //load *((ecx * 4) + esi) into edx     temp = A[i][j]
 * 	movl %eax, (%esi, %ecx, 4)   //load edx into *))ecx * 4) + esi)     
 * 	addl $1, %ecx                //ecx++              j++
 * 	movl %edx, (%ebx)            //(ebx) = edx        *a = j + 4i
 * 	addl $52, (%ebx)             //(ebx) += 52        
 * 	cmpl %edi, %ecx              //ecx<edi            if j < i
 * 	jl .L3                       //goto .L3           loop
*/

/**
A[i][j]
*(A + i)[j] || *(A[i] + j)
*((*(A + i)) + j)
**/

#include <stdio.h>

#define M 13
typedef int Marray_t[M][M]; 

void pop_array(Marray_t A){
	
	int i, j;	
	for (j = 0; j < M; j++){
		for (i = 0; i < M; i++){
			A[i][j] = j;
		}	
	}
}

void print_array(Marray_t A){
	int i, j;
	for (j = 0; j < M; j++){
		for (i = 0; i < M; i++){
			printf("[%4d]", A[i][j]);
		}
		printf("\n");
	}

	printf("\n");	
}


void opt_transpose(Marray_t A){
	int i, j;
	int* t1;
	int* t2;	
	for (j = 0; j < i; j++){
		//*((*A+i)+j);
		t1 = (*(A+i) + j);
		*(*(A+i) + j) = *(*(A+j) + i);
		*(*(A+j) + i) = *t1;
		j + (4*M);
	}
}

int main(){

	Marray_t A;
	pop_array(A);
	print_array(A);
	opt_transpose(A);	
	print_array(A);
	return 0;
}
