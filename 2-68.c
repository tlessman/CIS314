#include <stdio.h>

//mask least significant bits

int lower_one_mask(int n){
	
}

int main(){
	unsigned int a = 7;

	/*DEBUG CODE*/
	unsigned int m = (0xFFFFFFFF>>a);
	printf("0x%.8x\n", a|m);






	//printf("0x.8%x \n", lower_one_mask(a));
	return 0;
}
