	.text
	.file	"main"
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
	pushq	%rax
	.cfi_offset %rbx, -24
	movl	$0, -12(%rbp)
	leaq	.L__unnamed_1(%rip), %rdi
	leaq	-12(%rbp), %rsi
	xorl	%eax, %eax
	callq	scanf@PLT
	leaq	.L__unnamed_2(%rip), %rbx
	jmp	.LBB0_1
	.p2align	4, 0x90
.LBB0_4:
	incl	-12(%rbp)
.LBB0_1:
	cmpl	$9, -12(%rbp)
	jg	.LBB0_5
	movq	%rsp, %rcx
	leaq	-16(%rcx), %rax
	movq	%rax, %rsp
	movl	-12(%rbp), %edx
	movl	%edx, -16(%rcx)
	cmpl	$5, %edx
	jge	.LBB0_4
	movl	(%rax), %esi
	movq	%rbx, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	jmp	.LBB0_4
.LBB0_5:
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
	.asciz	"%d"
	.size	.L__unnamed_1, 3

	.type	.L__unnamed_2,@object
.L__unnamed_2:
	.asciz	"%d\n"
	.size	.L__unnamed_2, 4

	.section	".note.GNU-stack","",@progbits
