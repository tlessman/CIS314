#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VECTOR_SIZE 8
//#define VECTOR_SIZE 20
//#define VECTOR_SIZE 100
typedef long long data_t;
typedef data_t *vec_ptr;

data_t * get_vec_start(vec_ptr v) {
	return v;
}

int vec_length(vec_ptr v) {
	return VECTOR_SIZE;
}

/* Accumulate in temporary */
void inner4x4a(vec_ptr u, vec_ptr v, data_t *dest) {
	long int i;
	int length = vec_length(u);
	int loop4length = length-3;
	data_t *udata = get_vec_start(u);
	data_t *vdata = get_vec_start(v);
	data_t sum1 = (data_t) 0;
	data_t sum2 = (data_t) 0;
	data_t sum3 = (data_t) 0;
	data_t sum4 = (data_t) 0;
	for (i = 0; i < length; i+=4) { 
		sum1 += udata[i] * vdata[i];
		sum2 += udata[i+1] * vdata[i+1];
		sum3 += udata[i+2] * vdata[i+2];
		sum4 += udata[i+3] * vdata[i+3];	
	}
	*dest = sum1 + sum2 + sum3+ sum4;
}

int main(){
	vec_ptr u = malloc(sizeof(data_t) * VECTOR_SIZE);
	vec_ptr v = malloc(sizeof(data_t) * VECTOR_SIZE);
	data_t* d; 
	u[0] = 16;
	v[0] = 32; 
	
	int i;
        for(i = 0; i < VECTOR_SIZE; i++){
		*(u+i) = 2*i;
		*(v+i) = 10*i;


	}
	clock_t start = clock();
        inner4x4a(u, v, d);
        clock_t end = clock();
        double elapsed = ((double) (end - start))/CLOCKS_PER_SEC;
        printf("%lf %lf %d %lf\n\n", end, start, CLOCKS_PER_SEC, elapsed); //returning 0.000 for elapsed
/*
*       int j;
*       for(j = 0; j < VECTOR_SIZE; j++){
*		printf("[%.4d] [%.4d]\n", *(u+j), *(v+j));
*	}	
*/
        int k;
        printf("%d\n", *d);
	return 0; 
}
