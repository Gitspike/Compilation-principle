	.text
	.file	"main"
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3
.LCPI0_0:
	.quad	4591870180174331904
	.text
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:
	.cfi_startproc
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movabsq	$4602678819172646912, %rax
	movq	%rax, 16(%rsp)
	movq	$0, 8(%rsp)
	movl	$5, (%rsp)
	movl	$150, 4(%rsp)
	leaq	.L__unnamed_1(%rip), %rdi
	movl	$150, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	cvtsi2sdl	4(%rsp), %xmm0
	mulsd	.LCPI0_0(%rip), %xmm0
	movsd	%xmm0, 8(%rsp)
	leaq	.L__unnamed_2(%rip), %rdi
	movb	$1, %al
	callq	printf@PLT
	xorps	%xmm0, %xmm0
	cvtsi2sdl	(%rsp), %xmm0
	mulsd	16(%rsp), %xmm0
	leaq	.L__unnamed_3(%rip), %rdi
	movb	$1, %al
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
	.asciz	"%lf\n"
	.size	.L__unnamed_2, 5

	.type	.L__unnamed_3,@object
.L__unnamed_3:
	.asciz	"%lf\n"
	.size	.L__unnamed_3, 5

	.section	".note.GNU-stack","",@progbits
