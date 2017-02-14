
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
 * trace:                     //tp in %rdi
 *	movl $0, %eax         //eax = 0 (not sure why? NULL maybe?)
 *	testq %rdi, $rdi      //if tp = 0 (if root is null)
 *	je .L3                //goto L3 (break)
 * .L5:
 *	movq (%rdi), %rax     //rax = &tp
 *	movq 16(%rdi), %rdi   //rdi = &tp. 
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

typedef struct ELE *tree_ptr;
struct ELE{
	long val;
	tree_ptr left;
	tree_ptr right;
}

long trace(tree_ptr tp){
	int v = NULL;
	while(tp.value!= 0){
		if (tp.value == v){
			break;
		}
		trace(this->tree_ptr.left);
		trace(this->tree_ptr.right);
}

int main(){

	return 0;
}
