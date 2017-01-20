#include <stdio.h>

//mask least significant bits
//
// 0000 0001 << 5
// 0001 0000
//
// 0x01
//
// 

int lower_one_mask(int x){
	unsigned w = 32;
	unsigned a = 1;
	unsigned m = 255;
	a=a<<(x);     // x = 5; a = 1; m = 255;
			// a = 0000 0000  0000 0000  0000 0000  0000 0001 << 4;                            
			// a = 0000 0000  0000 0000  0000 0000  0001 0000 = 16
			  
	m=m>>(w-x);   // m = 1111 1111  1111 1111  1111 1111  1111 1111 >> | w - x + 1 |  32 - 5 + 1 = 28 ;  
			// m = 0000 0000  0000 0000  0000 0000  0000 1111
			
			// a|m 0000 0000  0000 0000  0000 0000  0001 0000
			//     0000 0000  0000 0000  0000 0000  0000 1111
			//     0000 0000  0000 0000  0000 0000  0001 1111     
	a|=m;           //     = 1F
	return (a-1);

}

int main(){ 

	unsigned i;
	for (i = 1; i<=32 ; i++){
		printf("\n%u: 0x%.8x or %u\n", i, lower_one_mask(i), lower_one_mask(i));
	}	

	return 0;
}
