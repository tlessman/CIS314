/* 
 * movl 12(%ebp), %edx //copy value y from parameter pointer to register edx
 * subl 16(%ebp), %edx //subtract value z in parameter from y, and place in register edx
 * movl %edx, %eax //copy value in edx into eax 
 * sall $31, %eax //a-shift left 31 value in eax
 * sarl $31, %eax //a-shift right 31 value in eax
 * imull 8(%ebp), %edx //signed multiply value x from parameter with value at edx (stored in double word?) 
 * xorl %edx, %eax //bitwise xor operation on , stored in eax
 *
 */

#include <stdio.h>

int decode2(int x, int y, int z);

int main(){
	printf("%x\n", decode2(10, 5, -3));

	return 0;
}

int decode2(int x, int y, int z){
	int a = y;
	a -= z;
	int b = a;
	b = b<<31;
	b = b>>31;
	a *= x;
	b = a&b;
}
