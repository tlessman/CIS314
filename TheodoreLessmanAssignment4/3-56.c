/** x@%ebp+8 (passed int), n@%ebp+12 (loop index)
 * movl 8(%ebp), %esi    // esi = x
 * movl 12(%ebp), %ebx   // ebx = n
 * movl $-1, %edi        // edi = -1 (0xFFFFFFFF)
 * movl $1, %edx         // edx = 1 (0x00000001)
 * .L2:                  // begin for
 * movl %edx, %eax       // eax = 1
 * andl %esi, %eax       // x&1 into eax
 * xorl %eax, %edi       // eax^-1 into edi
 * movl %ebx, %ecx       //ecx = n //loop index
 * sall %cl, %edx        //shift left by cl //low(ecx)
 * testl %edx, %edx      //check if zero'd out
 * jne .L2               //if != 0, goto L2 else:
 * movl %edi, %eax       //return result
**/

/**
 * A. x in esi, n in ebx, result in eax, mask in edi
 * B. result = 1, mask = -1
 * C. mask != 0 
 * D. as an index
 * E. within the loop
 *
**/

int loop(int x, int n){
	int result = 1;
	int mask;
	for (mask = -1; mask != 0; mask = mask + 1){
		result ^= mask;
	}
	return result;
}


