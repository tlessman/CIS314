#include <stdio.h>


void pAND (int a, int m){
	printf("0x%x\n", a);
	printf("0x%x\n", m);
	printf("& ________\n");
	printf("0x%x\n\n", a&m);
}


void pOR (int a, int m){
	printf("0x%x\n", a);
	printf("0x%x\n", m);
	printf("| ________\n");
	printf("0x%x\n\n", a|m);
}

void pXOR (int a, int m){
	printf("0x%x\n", a);
	printf("0x%x\n", m);
	printf("^ ________\n");
	printf("0x%x\n\n", a^m);
}

void pNOT (int a){
	printf("0x%x\n", a);
	printf("~ ________\n");
	printf("0x%x\n\n", ~a);
}

unsigned int replace_byte(unsigned x, int i, unsigned char b){
	int n = 0x000000FF;

	printf("N is 0x%.8x\n", n);
	
	printf("B is 0x%.8x\n", b);

	n = n << 8*i;
	printf("N to 0x%.8x\n", n);
	
	b = (unsigned int)b << 8*i;
        printf("B is 0x%.8x\n", b);

	x &= ~n;
	printf("X is 0x%.8x\n", x);
	 	
	return x^b;
	
}









int main(){
	unsigned int a = 0x12345678;
        unsigned char b = 0xAB;
	
/*
	pAND(a,m<<8);
	pOR(a,m<<8);
	pXOR(a,m<<8);
	pNOT(a);
	pAND(a,n<<8);
	pOR(a,n<<8);
	pXOR(a,n<<8);
	pNOT(n);
*/
	printf("rtrn 0x%x\n\n", replace_byte(a, 2, b));
	printf("rtrn 0x%x\n\n", replace_byte(a, 0, b));

	return 0;
}
