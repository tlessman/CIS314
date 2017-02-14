#include <stdio.h>

/**
 * A. M = 13 //bytes in row / bytes in int = 52 / 4
 * j in esi, i in ecx
**/

#define M 13
typedef int Marray_t[M][M]; 

/**
 * .L3:
 * 	movl (%ebx), %eax            //move eax = mArr    (mArr)
 * 	movl (%esi, %ecx, 4), %edx   //edx = esi + 4ecx   eax = a[i + 4j] 
 * 	movl %eax, (%esi, %ecx, 4)   //esi + 4ecx = eax   a[i + 4j] = eax 
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
#define void print_Marray(Marray_t A){
	int i, j;
	for (i = 0; i < M; i++){
		for (j = 0; j < M; j++){
			printf("%8d   ", *((*(A + i)) + j) );



#define void opt_transpose(Marray_t A){
	int i, j;
	int *p = A;
	for (i = 0; i < M; i++){
		int* p1 = p + (i*M+j);
		int* p2 = p + (j*M+i);
			int t1 = *p1;
			*p1 = *p2;
			*p2 = t1;
		}
	}
}

int main(){
	Marray_t A = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}
	opt_transpose(mArr);	

	return 0;
}
