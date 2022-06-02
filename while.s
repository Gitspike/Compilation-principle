	.text
	.file	"main"
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	.cfi_offset %rbx, -16
	movl	$100, 12(%rsp)
	movl	$0, 4(%rsp)
	movl	$0, 8(%rsp)
	leaq	.L__unnamed_1(%rip), %rdi
	leaq	8(%rsp), %rsi
	xorl	%eax, %eax
	callq	scanf@PLT
	leaq	.L__unnamed_2(%rip), %rbx
	.p2align	4, 0x90
.LBB0_1:
	movl	8(%rsp), %eax
	cmpl	4(%rsp), %eax
	jl	.LBB0_3
	movl	4(%rsp), %esi
	movq	%rbx, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	incl	4(%rsp)
	jmp	.LBB0_1
.LBB0_3:
	xorl	%eax, %eax
	addq	$16, %rsp
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc

	.type	.L__unnamed_1,@object
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_1:
	.asciz	"%d"
	.size	.L__unnamed_1, 3

	.type	.L__unnamed_2,@object
.L__unnamed_2:
	.asciz	"%d\n"
	.size	.L__unnamed_2, 4

	.section	".note.GNU-stack","",@progbits
