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
void inner4(vec_ptr u, vec_ptr v, data_t *dest) {
	long int i;
	int length = vec_length(u);
	data_t *udata = get_vec_start(u);
	data_t *vdata = get_vec_start(v);
	data_t sum = (data_t) 0;
	for (i = 0; i < length; i++) { 
		sum = sum + udata[i] * vdata[i];
	//	printf("%d ", sum);
	}
	*dest = sum;
}

int main(){
	vec_ptr u = malloc(sizeof(data_t) * VECTOR_SIZE);
	vec_ptr v = malloc(sizeof(data_t) * VECTOR_SIZE);
	data_t* d; 
	int i;
	for(i = 0; i < VECTOR_SIZE; i++){
		*(get_vec_start(u)+i) = 2*i;
		*(get_vec_start(v)+i) = 10*i;
	}
	clock_t start = clock();
	inner4(u, v, d); 
	clock_t end = clock();
	double elapsed = ((double) (end - start))/CLOCKS_PER_SEC;
	
	printf("%lf %lf %d %lf\n\n", end, start, CLOCKS_PER_SEC, elapsed); //returning 0.000 for elapsed
	/*
	int j;
        for(j = 0; j < VECTOR_SIZE; j++){
               printf("[%.4d] [%.4d]\n", *(u+j), *(v+j));
        }
	*/
	int k;		 
        printf("%d\n", *d);
       
		 
	return 0; 
}
