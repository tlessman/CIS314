/* 2-64.c
 * return 1 when any odd bit of x equals 1; 0 otherwise. assume w=32
 * follow bit-level integer coding
 * 0x00000000
 * s 12345678
 *
 * %xn                                 0x00000002
 *        0    2     0    0     0    0     0    0
 * BIN 0000 0010  0000 0000  0000 0000  0000 0000
 *        A    A     A    A     A    A     A    A
 * ODD 1010 1010  1010 1010  1010 1010  1010 1010
 *        5    5     5    5     5    5     5    5
 * EVN 0101 0101  0101 0101  0101 0101  0101 0101
 * %xO 0xAAAAAAAA
 * %xE 0x55555555
 * 2sC 0x000F8AA0 or  1018528
 *     A0 8A 0F 00
 *     1010 0000  1000 1010  0000 1111  0000 0000  
 *    ~__________________________________________
 *     5F 75 F0 FF
 *     0101 1111  0111 0101  1111 0000  1111 1111  
 *    +0000 0001__________________________________
 *      75 F0 FF                                         
 *     0101 0000  0111 1010  1111 0000  1111 1111  
 *     0xFFF07560 or -1018528
 *
 *     0x55555555 look with all 32 bits 01010101 01010101 01010101 01010101
 *   & 0xAAAAAAAA                     & 10101010 10101010 10101010 10101010
 *     0x00000000 look for 1s           00000000 00000000 00000000 00000000
 *
 *     look at all 32bits
 *     & with 0xAAAAAAAA
 *     if other than 0x0, it has odd one
 *
 *

. Assumptions 
Integers are represented in two’s-complement form. 
Right shifts of signed data are performed arithmetically. 
Datatype int is w bitslong.
For some of the problems, you will be given a speciﬁc value for w, but otherwise your code should work as long as w is a multiple of 8. 
You can use the expression sizeof(int)<<3 to compute w. 

. Forbidden Conditionals(
if or ? :), loops, switch statements, function calls, and macro invocations. 
Division, modulus, and multiplication. 
Relative comparison operators (<, >, <=, and >=). Casting, either explicit or implicit. 

. Allowed operations 
All bit-level and logic operations. Left and right shifts, but only with shift amounts between 0 and w−1. 
Addition and subtraction. 
Equality (==) and inequality (!=) tests.(Some of the problems do not allow these.) 
Integer constants INT_MIN and INT_MAX. 

*/

int any_odd_one(unsigned x){
		
	//0x2
	//0x00000010
	//

	
	

}



int main(){
	unsigned a = 0;
	unsigned b = 255;
	printf("%i %i ", a, b);

	a^=b;
        printf("%i %i ", a, b);

	b^=a;
	printf("%i %i ", a, b);

	a^=b;
	printf("%i %i\n", a, b);


	long l = 0xFFFFFFFF;
        printf("%l size of %i\n", l, size_of(l));



	return 0;
}
