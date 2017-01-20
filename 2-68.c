#include <stdio.h>

//mask least significant bits

int lower_one_mask(int x){
	unsigned w = 32;
	unsigned int m = (0xFFFFFFFF<<(w-1));
        return (x^m)>>(w-1);

}

int main(){ 
	unsigned int i = 7;
//	for (i = 0; i<32; i++){
		printf("%i: %i\n", i+1,lower_one_mask(i+1));
//	}



	return 0;
}
