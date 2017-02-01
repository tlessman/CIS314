#include <stdio.h>

void swap(int* xp, int* yp);

int main(){
	int a = 1, b = 2;
	int* ap = &a, bp = &b;
	printf("Before: %d,%d,%p,%p", a, b, ap, bp);
	swap(ap,bp);
	printf("After:  %d,%d,%p,%p", a, b, ap, bp);

	return 0;
}

void swap(int* xp, int* yp){
	int x = *xp, y = *yp;
	*yp = x;
	*xp = y;
}


