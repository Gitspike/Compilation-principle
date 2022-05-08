	.text
	.file	"main"
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:
	.cfi_startproc
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movl	$0, 16(%rsp)
	movl	$0, 12(%rsp)
	leaq	.L__unnamed_1(%rip), %rdi
	leaq	16(%rsp), %rsi
	xorl	%eax, %eax
	callq	scanf@PLT
	leaq	.L__unnamed_2(%rip), %rdi
	leaq	12(%rsp), %rsi
	xorl	%eax, %eax
	callq	scanf@PLT
	movl	$0, 20(%rsp)
	movl	16(%rsp), %eax
	cmpl	12(%rsp), %eax
	jle	.LBB0_2
	movl	16(%rsp), %eax
	movl	%eax, 20(%rsp)
	movl	12(%rsp), %ecx
	movl	%ecx, 16(%rsp)
	movl	%eax, 12(%rsp)
.LBB0_2:
	movl	16(%rsp), %edx
	leaq	.L__unnamed_3(%rip), %rdi
	movl	$97, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	movl	12(%rsp), %edx
	leaq	.L__unnamed_4(%rip), %rdi
	movl	$98, %esi
	xorl	%eax, %eax
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
	.asciz	"%d"
	.size	.L__unnamed_1, 3

	.type	.L__unnamed_2,@object
.L__unnamed_2:
	.asciz	"%d"
	.size	.L__unnamed_2, 3

	.type	.L__unnamed_3,@object
.L__unnamed_3:
	.asciz	"%c%d\n"
	.size	.L__unnamed_3, 6

	.type	.L__unnamed_4,@object
.L__unnamed_4:
	.asciz	"%c%d\n"
	.size	.L__unnamed_4, 6

	.section	".note.GNU-stack","",@progbits
