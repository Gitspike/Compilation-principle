	.text
	.file	"main"
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:
	.cfi_startproc
	subq	$72, %rsp
	.cfi_def_cfa_offset 80
	movl	$0, 12(%rsp)
	movl	$0, 28(%rsp)
	movl	$0, 32(%rsp)
	movq	$0, 16(%rsp)
	leaq	.L__unnamed_1(%rip), %rdi
	leaq	16(%rsp), %rsi
	xorl	%eax, %eax
	callq	scanf@PLT
	movsd	16(%rsp), %xmm0
	leaq	.L__unnamed_2(%rip), %rdi
	movb	$1, %al
	callq	printf@PLT
	movl	$3, 36(%rsp)
	movl	$3, 12(%rsp)
	leaq	.L__unnamed_3(%rip), %rdi
	movl	$3, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movl	$1, 12(%rsp)
	movsd	16(%rsp), %xmm0
	leaq	.L__unnamed_4(%rip), %rdi
	movb	$1, %al
	callq	printf@PLT
	movl	28(%rsp), %esi
	leaq	.L__unnamed_5(%rip), %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	xorl	%eax, %eax
	addq	$72, %rsp
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc

	.type	.L__unnamed_1,@object
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_1:
	.asciz	"%lf"
	.size	.L__unnamed_1, 4

	.type	.L__unnamed_2,@object
.L__unnamed_2:
	.asciz	"%f\n"
	.size	.L__unnamed_2, 4

	.type	.L__unnamed_3,@object
.L__unnamed_3:
	.asciz	"%d\n"
	.size	.L__unnamed_3, 4

	.type	.L__unnamed_4,@object
.L__unnamed_4:
	.asciz	"%f\n"
	.size	.L__unnamed_4, 4

	.type	.L__unnamed_5,@object
.L__unnamed_5:
	.asciz	"%d\n"
	.size	.L__unnamed_5, 4

	.section	".note.GNU-stack","",@progbits
