

/**
 * A. M = 4
 * i in e**, j in e**
**/

#define M 4 //(sizeof(int32))
typedef int Marray_t[M][M]; 


#define void transpose(Marray_t A){
	int i, j;
	for (i=0; i<M; i++){
		for (j=0; j<i; j++){
			int t = A[i][j];
			A[i][j] = A[j][i];
			A[j][i] = t;
		}
	}
}

/**
A[i][j]
*(A + i)[j] || *(A[i] + j)
*((*(A + i)) + j)
**/

#define void opt_transpose(Marray_t A){
	int i, j;
	for (i=0; i<M; i++){
		for (j=0; j<i; j++){
			int t = *((*(A + i)) + j);
			A[i][j] = A[j][i];
			A[j][i] = t;
		}
	}
}

