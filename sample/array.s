	.text
	.file	"main"
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:
	.cfi_startproc
	subq	$248, %rsp
	.cfi_def_cfa_offset 256
	movl	$2, 4(%rsp)
	movabsq	$85899345930, %rax
	movq	%rax, 8(%rsp)
	movl	$30, 16(%rsp)
	movl	$60, 96(%rsp)
	leaq	.L__unnamed_1(%rip), %rdi
	movl	$30, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movl	96(%rsp), %esi
	leaq	.L__unnamed_2(%rip), %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	xorl	%eax, %eax
	addq	$248, %rsp
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
