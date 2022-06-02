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
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	movq	%rsp, %rax
	leaq	-16(%rax), %rsp
	movl	$3, -16(%rax)
	movl	$3, %edi
	callq	f1@PLT
	movl	%eax, -4(%rbp)
	leaq	.L__unnamed_1(%rip), %rdi
	movl	%eax, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	xorl	%eax, %eax
	movq	%rbp, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc

	.globl	f1
	.p2align	4, 0x90
	.type	f1,@function
f1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r14
	pushq	%rbx
	subq	$16, %rsp
	.cfi_offset %rbx, -32
	.cfi_offset %r14, -24
	movl	$0, -20(%rbp)
	movl	%edi, %ebx
	leaq	.L__unnamed_2(%rip), %rdi
	leaq	-20(%rbp), %rsi
	xorl	%eax, %eax
	callq	scanf@PLT
	leaq	.L__unnamed_3(%rip), %r14
	cmpl	%ebx, -20(%rbp)
	jge	.LBB1_3
	.p2align	4, 0x90
.LBB1_2:
	movl	-20(%rbp), %esi
	movq	%r14, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	incl	-20(%rbp)
	cmpl	%ebx, -20(%rbp)
	jl	.LBB1_2
.LBB1_3:
	movq	%rsp, %rax
	leaq	-16(%rax), %rsp
	movl	$1, -16(%rax)
	movl	$1, %eax
	leaq	-16(%rbp), %rsp
	popq	%rbx
	popq	%r14
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end1:
	.size	f1, .Lfunc_end1-f1
	.cfi_endproc

	.type	.L__unnamed_2,@object
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_2:
	.asciz	"%d"
	.size	.L__unnamed_2, 3

	.type	.L__unnamed_3,@object
.L__unnamed_3:
	.asciz	"%d\n"
	.size	.L__unnamed_3, 4

	.type	.L__unnamed_1,@object
.L__unnamed_1:
	.asciz	"%d\n"
	.size	.L__unnamed_1, 4

	.section	".note.GNU-stack","",@progbits
