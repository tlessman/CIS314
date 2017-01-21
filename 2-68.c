#include <stdio.h>
/* 2-68
 * Theodore Lessman
 * CIS314 CRN21709
 * Assignment 1
 * github.com/tlessman/CIS314
 * 
 * lower_one_mask(n) 
 * * Mask with least signficant n bits set to 1 * Examples: n = 6 -->0x2F, n = 17 -->0x1FFFF * Assume 1 <= n <= w
 */

/*
int lower_one_mask(int x){ //still could not handle overflow
	int w = 32;
	int m = 255;	     
	int a = 1;
			     // x = 5
	a=a<<(x);            // 0x00000001 << 0x00000020
	m=m>>(w-x);          // 0xFFFFFFFF >> 0x0000001F //thought I could mask and shift to handle, different outcome, but not what was expected.
	a|=m;
	return (a-1);        // 
}
*/

int lower_one_mask(int x){ // i think this is what was intended but i couldnt figure out overflow
	              //   x=5  |                                          | x=5           32
	int y = 1;    //    y 0b|0000 0000  0000 0000  0000 0000  0000 0001| 0x1          0x1   
		      // y<<x 0b|_______________________________________<<x|            
	y = y<<x;     //    y 0b|0000 0000  0000 0000  0000 0000  0010 0000| 0x20 1|0x00000000
	              //        |________________________________________-1|
	return --y;   //  --y 0b|                                    1 1111| 0x1F   0x00000000	
                      //         going out of bounds and failing to properly subtract 1 
}

int main(){ 

	int i;
	for (i = 1; i<=32 ; i++){
		printf("\n%i: 0x%.8x or %i\n", i, lower_one_mask(i), lower_one_mask(i));
	}	

	return 0;
}
