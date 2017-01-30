#include <stdio.h>

unsigned f2u(float f);

int float_le(float x, float y);




int main(){
	float a= 1.0f;
	float b= 2.0f;
	printf("is first arg less than second?: %d", float_le(a, b));
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
	return *(int*)sx < *(int*)sy;
} 
