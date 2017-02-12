/*** 3-54.c ***
 * Theodore Lessman
 * CIS314
 * Assignment 3
 * 2017.02.03
 *
 * decode2(int, int, int)
 *
 * Translated from the following x86 instruction
 * movl 12(%ebp), %edx //copy value y from parameter pointer to register edx
 * subl 16(%ebp), %edx //subtract value z in parameter from y, and place in register edx
 * movl %edx, %eax //copy value in edx into eax 
 * sall $31, %eax //a-shift left 31 value in eax
 * sarl $31, %eax //a-shift right 31 value in eax
 * imull 8(%ebp), %edx //signed multiply value x from parameter with value at edx (stored in double word?) 
 * xorl %edx, %eax //bitwise xor operation on edx and eax, stored in eax
 *
 * My 3-54.s appears to be similar if I compile without optimiation, however -O1 causes almost all of decode2()'s instruction to disappear.
 * There are some operations that change order, and quite a few movls that copy values into and out of registers, but overall, the shape is quite similar.
 *
 *
 */

#include <stdio.h>

int decode2(int x, int y, int z);

int main(){
	printf("Should be -2:   %d\n", decode2(1, 2, 4));
	printf("Should be -16: %d\n", decode2(-4, -8, -12));

	return 0;
}

int decode2(int x, int y, int z){
	int a = y;
	a -= z;
	int b = a;
	b = b<<31;
	b = b>>31;
	a *= x;
	b = b^a;
}
