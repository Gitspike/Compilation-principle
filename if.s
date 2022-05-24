	.text
	.file	"main"
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:
	.cfi_startproc
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$1, 4(%rsp)
	xorl	%eax, %eax
	testb	%al, %al
	jne	.LBB0_2
	leaq	.L__unnamed_1(%rip), %rdi
	movl	$1, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	leaq	.L__unnamed_2(%rip), %rdi
	movl	$2, %esi
	xorl	%eax, %eax
	callq	printf@PLT
.LBB0_2:
	xorl	%eax, %eax
	popq	%rcx
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
