	.text
	.file	"main"
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3
.LCPI0_0:
	.quad	4623226492472524800
.LCPI0_1:
	.quad	4617315517961601024
.LCPI0_2:
	.quad	4608083138940239872
.LCPI0_3:
	.quad	4613937818241073152
.LCPI0_4:
	.quad	-4613937818241073152
	.text
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%rbx
	subq	$264, %rsp
	.cfi_offset %rbx, -24
	movl	$0, -12(%rbp)
	movl	$0, -28(%rbp)
	movabsq	$4294967298, %rax
	movq	%rax, -268(%rbp)
	movl	$5, -16(%rbp)
	movabsq	$4623226492472524800, %rax
	movq	%rax, -24(%rbp)
	leaq	.L__unnamed_1(%rip), %rdi
	movsd	.LCPI0_0(%rip), %xmm0
	movb	$1, %al
	callq	printf@PLT
	movsd	-24(%rbp), %xmm0
	ucomisd	.LCPI0_1(%rip), %xmm0
	jbe	.LBB0_2
	movq	%rsp, %rbx
	leaq	-16(%rbx), %rsp
	movl	-16(%rbp), %eax
	movl	%eax, -16(%rbx)
	movq	%rsp, %rax
	leaq	-16(%rax), %rsp
	movl	-12(%rbp), %ecx
	movl	%ecx, -16(%rax)
	movq	%rsp, %rax
	leaq	-16(%rax), %rsp
	movl	$0, -16(%rax)
	movl	-16(%rbx), %esi
	leaq	.L__unnamed_2(%rip), %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	decl	-16(%rbx)
	movq	%rsp, %rax
	leaq	-16(%rax), %rsp
	movl	$8, -16(%rax)
	jmp	.LBB0_3
.LBB0_2:
	movl	-12(%rbp), %esi
	leaq	.L__unnamed_3(%rip), %rdi
	xorl	%eax, %eax
	callq	printf@PLT
.LBB0_3:
	xorps	%xmm0, %xmm0
	cvtsi2sdl	-16(%rbp), %xmm0
	mulsd	.LCPI0_2(%rip), %xmm0
	addsd	.LCPI0_3(%rip), %xmm0
	addsd	.LCPI0_4(%rip), %xmm0
	movsd	%xmm0, -24(%rbp)
	leaq	.L__unnamed_4(%rip), %rdi
	movb	$1, %al
	callq	printf@PLT
	xorl	%eax, %eax
	leaq	-8(%rbp), %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa %rsp, 8
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
	.asciz	"%d\n"
	.size	.L__unnamed_2, 4

	.type	.L__unnamed_3,@object
.L__unnamed_3:
	.asciz	"%d\n"
	.size	.L__unnamed_3, 4

	.type	.L__unnamed_4,@object
.L__unnamed_4:
	.asciz	"%lf\n"
	.size	.L__unnamed_4, 5

	.section	".note.GNU-stack","",@progbits
