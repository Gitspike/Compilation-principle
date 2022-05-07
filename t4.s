	.text
	.file	"main"
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3
.LCPI0_0:
	.quad	4608083138940239872
.LCPI0_1:
	.quad	4613937818241073152
.LCPI0_2:
	.quad	-4613937818241073152
	.text
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:
	.cfi_startproc
	subq	$264, %rsp
	.cfi_def_cfa_offset 272
	movl	$0, 20(%rsp)
	movl	$0, 16(%rsp)
	movq	$0, 8(%rsp)
	movabsq	$4294967298, %rax
	movq	%rax, 24(%rsp)
	movl	$5, 4(%rsp)
	leaq	.L__unnamed_1(%rip), %rdi
	xorps	%xmm0, %xmm0
	movb	$1, %al
	callq	printf@PLT
	xorps	%xmm0, %xmm0
	cvtsi2sdl	4(%rsp), %xmm0
	mulsd	.LCPI0_0(%rip), %xmm0
	addsd	.LCPI0_1(%rip), %xmm0
	addsd	.LCPI0_2(%rip), %xmm0
	movsd	%xmm0, 8(%rsp)
	leaq	.L__unnamed_2(%rip), %rdi
	movb	$1, %al
	callq	printf@PLT
	xorl	%eax, %eax
	addq	$264, %rsp
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc

	.type	.L__unnamed_1,@object
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_1:
	.asciz	"%lf\n"
	.size	.L__unnamed_1, 5

	.type	.L__unnamed_2,@object
.L__unnamed_2:
	.asciz	"%lf\n"
	.size	.L__unnamed_2, 5

	.section	".note.GNU-stack","",@progbits
