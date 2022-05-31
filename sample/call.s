	.text
	.file	"main"
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:
	.cfi_startproc
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movl	$3, 20(%rsp)
	movl	$0, 4(%rsp)
	movl	$4, 16(%rsp)
	leaq	.L__unnamed_1(%rip), %rdi
	movl	$4, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movl	$3, 12(%rsp)
	movl	$6, 8(%rsp)
	movl	$6, 4(%rsp)
	leaq	.L__unnamed_2(%rip), %rdi
	movl	$6, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	xorl	%eax, %eax
	addq	$24, %rsp
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc

	.type	.L__unnamed_1,@object
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_1:
	.asciz	"%d\n"
	.size	.L__unnamed_1, 4

	.type	.L__unnamed_2,@object
.L__unnamed_2:
	.asciz	"%d\n"
	.size	.L__unnamed_2, 4

	.section	".note.GNU-stack","",@progbits
