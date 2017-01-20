#include <stdio.h>

int lower_one_mask(int x){
	              //                                                  x=  5       32
	int y = 1;    //    y 0b|0000 0000  0000 0000  0000 0000  0000 0001|  1        1   
		      // y<<x 0b|_______________________________________<<x|            
	y = y<<x;     //    y 0b|0000 0000  0000 0000  0000 0000  0010 0000| 32 
	              //        |________________________________________-1|
	return --y;   //  --y 0b|                                    1 1111| 31	

}

int main(){ 

	int i;
	for (i = 1; i<=32 ; i++){
		printf("\n%i: 0x%.8x or %i\n", i, lower_one_mask(i), lower_one_mask(i));
	}	

	return 0;
}
