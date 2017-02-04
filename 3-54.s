; if i compile with optimization -O1, my function disappears entirely, and output is 0,0
; if i compile without optimization, the code is quite similar, with some additional movls and some operations changed in order, and output is -2,-16 as expected

	.file	"3-54.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "Should be -2:   %d\12\0"
LC1:
	.ascii "Should be -16: %d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$16, %esp
	call	___main
	movl	$4, 8(%esp)
	movl	$2, 4(%esp)
	movl	$1, (%esp)
	call	_decode2
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	$-12, 8(%esp)
	movl	$-8, 4(%esp)
	movl	$-4, (%esp)
	call	_decode2
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	ret
	.globl	_decode2
	.def	_decode2;	.scl	2;	.type	32;	.endef
_decode2:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	12(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	16(%ebp), %eax
	subl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	%eax, -8(%ebp)
	sall	$31, -8(%ebp)
	sarl	$31, -8(%ebp)
	movl	-4(%ebp), %eax
	imull	8(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	xorl	%eax, -8(%ebp)
	nop
	leave
	ret
	.ident	"GCC: (GNU) 5.4.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
