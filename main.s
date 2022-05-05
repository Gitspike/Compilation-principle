	.text
	.file	"main"
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:
	.cfi_startproc
	subq	$104, %rsp
	.cfi_def_cfa_offset 112
	movl	$0, 16(%rsp)
	movl	$0, 52(%rsp)
	movl	$0, 8(%rsp)
	movl	$0, 48(%rsp)
	movl	$0, 44(%rsp)
	movl	$0, 40(%rsp)
	movb	$0, 7(%rsp)
	movl	$1, 12(%rsp)
	leaq	.L__unnamed_1(%rip), %rdi
	xorl	%esi, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movl	12(%rsp), %esi
	incl	%esi
	movl	%esi, 76(%rsp)
	leaq	.L__unnamed_2(%rip), %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	movl	$2, 16(%rsp)
	leaq	.L__unnamed_3(%rip), %rdi
	movl	$2, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movl	56(%rsp), %eax
	movl	%eax, 36(%rsp)
	movl	$2, 28(%rsp)
	movl	$0, 24(%rsp)
	movl	$7, 32(%rsp)
	leaq	.L__unnamed_4(%rip), %rdi
	movl	$7, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movl	$7, 20(%rsp)
	movl	$7, 8(%rsp)
	xorl	%eax, %eax
	addq	$104, %rsp
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

	.type	.L__unnamed_3,@object
.L__unnamed_3:
	.asciz	"%d\n"
	.size	.L__unnamed_3, 4

	.type	.L__unnamed_4,@object
.L__unnamed_4:
	.asciz	"%d\n"
	.size	.L__unnamed_4, 4

	.section	".note.GNU-stack","",@progbits
