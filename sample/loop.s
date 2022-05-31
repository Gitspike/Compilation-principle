	.text
	.file	"main"
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:
	.cfi_startproc
	pushq	%r14
	.cfi_def_cfa_offset 16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	subq	$24, %rsp
	.cfi_def_cfa_offset 48
	.cfi_offset %rbx, -24
	.cfi_offset %r14, -16
	movl	$1, (%rsp)
	cmpl	$5, (%rsp)
	jg	.LBB0_3
	.p2align	4, 0x90
.LBB0_2:
	movl	(%rsp), %eax
	movl	$5, %ecx
	subl	%eax, %ecx
	leal	-1(%rax), %edx
	movslq	%edx, %rdx
	movl	%ecx, 4(%rsp,%rdx,4)
	incl	%eax
	movl	%eax, (%rsp)
	cmpl	$5, (%rsp)
	jle	.LBB0_2
.LBB0_3:
	movl	$1, (%rsp)
	leaq	.L__unnamed_1(%rip), %rbx
	leaq	.L__unnamed_2(%rip), %r14
	jmp	.LBB0_4
	.p2align	4, 0x90
.LBB0_8:
	movl	(%rsp), %eax
	decl	%eax
	cltq
	movl	4(%rsp,%rax,4), %esi
	movq	%r14, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	incl	(%rsp)
.LBB0_4:
	movl	(%rsp), %eax
	cmpl	$5, %eax
	jg	.LBB0_9
	testl	%eax, %eax
	jle	.LBB0_9
	.p2align	4, 0x90
	cmpl	$4, (%rsp)
	jg	.LBB0_8
.LBB0_7:
	movq	%rbx, %rdi
	movl	$9, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	incl	(%rsp)
	cmpl	$4, (%rsp)
	jle	.LBB0_7
	jmp	.LBB0_8
.LBB0_9:
	xorl	%eax, %eax
	addq	$24, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%r14
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
