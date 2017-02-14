/** x@%ebp+8 (passed int), n@%ebp+12 (loop index)
 * movl 8(%ebp), %esi    // esi = x
 * movl 12(%ebp), %ebx   // ebx = n
 * movl $-1, %edi        // edi = -1 
 * movl $1, %edx         // edx = 1
 * .L2:                  // begin for
 * movl %edx, %eax       // eax = edx
 * andl %esi, %eax       // x&1 into eax
 * xorl %eax, %edi       // eax^-1 into edi
 * movl %ebx, %ecx       //ecx = n //loop index
 * sall %cl, %edx        //shift left by cl //low(ecx)
 * testl %edx, %edx      //check if zero'd out
 * jne .L2               //if != 0, goto L2 else:
 * movl %edi, %eax       //return result
**/

/**
 * A. x in esi, n in ebx, result in edi, mask in edx
 * B. result = -1, mask = 1      //for a long time I had these flipped and struggled
 * C. mask != 0 
 * D. as an index as a leftshift
 * E. within the loop as an xor
 *
**/
#include <stdio.h>

int loop(int x, int n){
	int result = -1;
	int mask;
	for (mask = 1; mask!=0; mask = mask << (n&0xFF)){
		result ^= (mask & x);
	}
	return result;
}

int main(){
	printf("%d", loop(16, 3));
	printf("%d", loop(16, 2));
	printf("%d", loop(1, 1));
	printf("%d", loop(1, 3));
}



