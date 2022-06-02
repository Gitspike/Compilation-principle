	.text
	.file	"main"
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:
	.cfi_startproc
	pushq	%rax
	.cfi_def_cfa_offset 16
	leaq	.L__unnamed_1(%rip), %rdi
	xorl	%esi, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	callq	p1@PLT
	callq	p2@PLT
	xorl	%eax, %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc

	.globl	p1
	.p2align	4, 0x90
	.type	p1,@function
p1:
	.cfi_startproc
	pushq	%rax
	.cfi_def_cfa_offset 16
	leaq	.L__unnamed_2(%rip), %rdi
	movl	$1, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	xorl	%eax, %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end1:
	.size	p1, .Lfunc_end1-p1
	.cfi_endproc

	.globl	p2
	.p2align	4, 0x90
	.type	p2,@function
p2:
	.cfi_startproc
	pushq	%rax
	.cfi_def_cfa_offset 16
	leaq	.L__unnamed_3(%rip), %rdi
	movl	$2, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	callq	p3@PLT
	xorl	%eax, %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end2:
	.size	p2, .Lfunc_end2-p2
	.cfi_endproc

	.globl	p3
	.p2align	4, 0x90
	.type	p3,@function
p3:
	.cfi_startproc
	pushq	%rax
	.cfi_def_cfa_offset 16
	leaq	.L__unnamed_4(%rip), %rdi
	movl	$3, %esi
	xorl	%eax, %eax
	callq	printf@PLT
	xorl	%eax, %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end3:
	.size	p3, .Lfunc_end3-p3
	.cfi_endproc

	.type	.L__unnamed_2,@object
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_2:
	.asciz	"%d\n"
	.size	.L__unnamed_2, 4

	.type	.L__unnamed_4,@object
.L__unnamed_4:
	.asciz	"%d\n"
	.size	.L__unnamed_4, 4

	.type	.L__unnamed_3,@object
.L__unnamed_3:
	.asciz	"%d\n"
	.size	.L__unnamed_3, 4

	.type	.L__unnamed_1,@object
.L__unnamed_1:
	.asciz	"%d\n"
	.size	.L__unnamed_1, 4

	.section	".note.GNU-stack","",@progbits
