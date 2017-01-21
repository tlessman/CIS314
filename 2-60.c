#include <stdio.h>

/*  2-60
 * Theodore Lessman
 * CIS314 CRN21709
 * Assignment 1
 * github.com/tlessman/CIS314
 *      
 *
 *
 * replace_byte(x, i, b) takes a hex, int and char and overwrites a given section (shifted by int) of the hex with the values from the char.
 *
 * Examples:
 * replace_byte(0x12345678, 2, 0xAB) --> 0x12AB5678 
 * replace_byte(0x12345678, 0, 0xAB) --> 0x123456AB
*/

/* DEBUG FUNCTIONS ||| was using them to get quickly calculate and see relations of operations
void pAND (int a, int m){
	printf("0x%.8x\n", a);
	printf("0x%.8x\n", m);
	printf("& ________\n");
	printf("0x%.8x\n\n", a&m);
}

void pOR (int a, int m){
	printf("0x%.8x\n", a);
	printf("0x%.8x\n", m);
	printf("| ________\n");
	printf("0x%.8x\n\n", a|m);
}

void pXOR (int a, int m){
	printf("0x%.8x\n", a);
	printf("0x%.8x\n", m);
	printf("^ ________\n");
	printf("0x%.8x\n\n", a^m);
}

void pNOT (int a){
	printf("0x%.8x\n", a);
	printf("~ ________\n");
	printf("0x%.8x\n\n", ~a);
}

void pLS (int a, int i){
	printf("0x%.8x\n", a);
	printf("<<_______%i\n", i);
	printf("0x%.8x\n\n", a<<8*i);
}

void pRS (int a, int i){
        printf("0x%.8x\n", a);
        printf(">>_______%i\n", i);
        printf("0x%.8x\n\n", a>>8*i);
}
*/

unsigned int replace_byte(unsigned x, int i, unsigned char b){
	int n = 0x000000FF;
	int w = 8;
	unsigned int m = b;
	printf("replace_byte(0x%.8x, %i, 0x%.2x)\n", x, i, b);
 	// replace_byte(i, 2, b)
	// N is 0x000000FF
	// m is 0x000000AB
	// X is 0x12345678
	n = n << w*i;               // n = 0x000000FF << 16
	printf("0x%.8x\n", n); // N is 0x00FF0000
	m = m << w*i;               // m = 0x000000AB << 16
        printf("0x%.8x\n", m); // m is 0x00AB0000
	x &= ~n;                    // x = 0x12345678 & 0xFF00FFFF
	printf("0x%.8x\n", x); // X is 0x12005678
	 	
	return x^m;                 //rtrn 0x12AB5678
	
}

int main(){
	unsigned int a = 0x12345678;
        unsigned char b = 0xAB;

	printf("0x%x\n\n", replace_byte(a, 2, b));
	printf("0x%x\n\n", replace_byte(a, 0, b));
	printf("0x%x\n\n", replace_byte(a, 1, b));
	printf("0x%x\n\n", replace_byte(a, 3, b));

	

	return 0;
}
