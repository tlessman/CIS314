#include <stdio.h>

/* 2-57
 * * Theodore Lessman
 * * CIS314 CRN21709
 * * Assignment 1
 * * github.com/tlessman/CIS314
 * *
 * * 
	void showBytes(p, l) takes an address to a byte's location, and the size of the variable type and prints the 
	hex representation
*/

typedef unsigned char* byte_ptr; //define pointer to byte

void show_bytes(byte_ptr p, int l){
	int i; //init index
	for (i=0; i<l; i++){ //for length of variable type
		printf(" %.2x", p[i]); //print as 2-bit hex chunks
	}
	printf("\n"); //new line
}

void show_short(short x){ // show bytes of short
	show_bytes((byte_ptr)&x, sizeof(short));
}

void show_long(long x){  // show bytes of long
	show_bytes((byte_ptr) &x, sizeof(long));
}

void show_double(double x){  // show bytes of double
	show_bytes((byte_ptr) &x, sizeof(double));
}

int main (){
	short s = -1;
	long l = 128;
	double d = 3.14;
	double t = 15;
	show_short(s);
	show_long(l);
	show_double(d);
	show_short(t);
	show_long(t);
	show_double(t);
	return 0;
}
