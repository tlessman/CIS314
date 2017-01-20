#include <stdio.h>

//mask least significant bits
//
// 0x00000001 << 5
// 0x00010000 
//
// 0xFFFFFFFF >> 4
// 0x0000FFFF 
//
// 0x00010000
//&0x0000FFFF
// 0x0001FFFF 
//
//

int lower_one_mask(int x){
	unsigned w = 8;
	unsigned a = 1;
	unsigned m = 0xFFFFFFFF;
	a<x;            //0x00010000
	m>(w-x);         //0x0000FFFF
	
	return (a^m);
	

}

int main(){ 
	unsigned i;
	for (i = 0; i<5 ; i++){
		printf("\n%i: %i\n0x%.8x\n", i+1, lower_one_mask(i+1), lower_one_mask(i+1));
	}



	return 0;
}
