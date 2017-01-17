#include <stdio.h>


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

unsigned int replace_byte(unsigned x, int i, unsigned char b){
	int n = 0x000000FF;
	int w = 8;
	unsigned int m = b;
                                    // (i, 2, b)
	printf("N is 0x%.8x\n", n); // N is 0x000000FF
	
	printf("M is 0x%.8x\n", m); // m is 0x000000AB

	printf("X is 0x%.8x\n", x); // X is 0x12345678

	n = n << w*i;               // n = 0x000000FF << 16
	printf("N to 0x%.8x\n", n); // N is 0x00FF0000
	
	m = m << w*i;               // m = 0x000000AB << 16
        printf("M is 0x%.8x\n", m); // m = 0x00AB0000 (getting 0x00000000)

	x &= ~n;                    // x = 0x12345678 & 0xFF00FFFF
	printf("X is 0x%.8x\n", x); // X is 0x12005678
	 	
	return x^m; //rtrn 0x12AB5678 (getting 0x12005678)
	
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
	printf("rtrn 0x%x\n\n", replace_byte(a, 1, b));
	printf("rtrn 0x%x\n\n", replace_byte(a, 3, b));

	unsigned char f = 0xAB;
	unsigned short g = 0x000000AB;
	//printf("char 0xAB == short 0x000000AB ? %i", f==g); 

	unsigned int r = 2;
	unsigned int s = 0x000000AB;
	pLS(s, r);

	return 0;
}
