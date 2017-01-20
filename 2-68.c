#include <stdio.h>

int lower_one_mask(int x){
	
	int y = 1;    //    y 0b|0000 0000  0000 0000  0000 0000  0000 0001|  1
		      // y<<x 0b|_______________________________________<<5|
	y = y<<x;     //    y 0b|0000 0000  0000 0000  0000 0000  0010 0000| 32
        return y-1;   //  y-1 0b|                                    1 1111| 31	

}

int main(){ 

	int i;
	for (i = 1; i<=32 ; i++){
		printf("\n%u: 0x%.8x or %u\n", i, lower_one_mask(i), lower_one_mask(i));
	}	

	return 0;
}
