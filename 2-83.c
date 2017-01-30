#include <stdio.h>

unsigned f2u(float f);

int float_le(float x, float y);




int main(){
	float a= 1.0f;
	float b= 2.0f;
	float c= -0.0f;
	float d= -1.0f;
	printf("is first arg less than second?: %d\n", float_le(a, b)); //sb 1
	printf("is first arg less than second?: %d\n", float_le(b, a)); //sb 0
	printf("is first arg less than second?: %d\n", float_le(c, c)); //sb 1
	printf("is first arg less than second?: %d\n", float_le(d, a)); //sb 1


	return 0;
}






unsigned f2u(float f) {
	return *((unsigned*)&f);
}


int float_le(float x, float y) {
	unsigned ux = f2u(x);
	unsigned uy = f2u(y);
/* Get the sign bits */
	unsigned sx = ux >> 31;
	unsigned sy = uy >> 31;
/* Give an expression using only ux, uy, sx, and sy */
	return (ux<<1 <= uy<<1) & (sy <= sx); 
	// see if it is less than bitwise (dropping off sign bit), then check for sign.
} 

/*
 * x = -1.0
 * y =  1.0
 * x 1 1111111 000...000 
 * y 0 1111111 000...000
 *   
 *
 *
 *
 *
 *
 * */
