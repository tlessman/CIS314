
/**
 * typedef struct ELE *tree-ptr
 *
 * struct ELE{
 *	long val;
 *	tree_ptr left;
 *	tree_ptr right;
 * }
 *
 * long trace(tree_ptr tp);
 *
 * trace: //tp in %rdi
 *	movl $0, %eax
 *	testq %rdi, $rdi
 *	je .L3
 * .L5:
 *	movq (%rdi), %rax
 *	movq 16(%rdi), %rdi
 *	testq %rdi, %rdi
 *	jne .L5
 * .L3:
 *	rep
 *	ret
 *
**/

/**
 * B. 
**/


