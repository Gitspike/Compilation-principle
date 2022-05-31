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
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$424, %rsp
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	movl	$100, -56(%rbp)
	movl	$0, -48(%rbp)
	movl	$0, -44(%rbp)
	movl	$0, -52(%rbp)
	leaq	.L__unnamed_1(%rip), %rdi
	leaq	-48(%rbp), %rsi
	xorl	%eax, %eax
	callq	scanf@PLT
	movl	$0, -44(%rbp)
	leaq	.L__unnamed_2(%rip), %r14
	leaq	-52(%rbp), %rbx
	.p2align	4, 0x90
.LBB0_1:
	movl	-44(%rbp), %eax
	cmpl	-48(%rbp), %eax
	jge	.LBB0_3
	movq	%r14, %rdi
	movq	%rbx, %rsi
	xorl	%eax, %eax
	callq	scanf@PLT
	movslq	-44(%rbp), %rax
	movl	-52(%rbp), %ecx
	movl	%ecx, -460(%rbp,%rax,4)
	incl	-44(%rbp)
	jmp	.LBB0_1
.LBB0_3:
	movq	%rsp, %r9
	leaq	-16(%r9), %r8
	movq	%r8, %rsp
	movl	$0, -16(%r9)
	movq	%rsp, %rax
	leaq	-16(%rax), %rcx
	movq	%rcx, %rsp
	movl	$0, -16(%rax)
	movq	%rsp, %r10
	leaq	-16(%r10), %rdx
	movq	%rdx, %rsp
	movl	$0, -16(%r10)
	movq	%rsp, %r11
	leaq	-16(%r11), %r13
	movq	%r13, %rsp
	movl	$0, -16(%r11)
	movq	%rsp, %r14
	leaq	-16(%r14), %rdi
	movq	%rdi, %rsp
	movl	$0, -16(%r14)
	movq	%rsp, %r15
	leaq	-16(%r15), %r12
	movq	%r12, %rsp
	movl	$0, -16(%r15)
	movq	%rsp, %rax
	addq	$-416, %rax
	movq	%rax, %rsp
	movl	$1, -16(%r9)
	movl	$0, -16(%r10)
	movl	$0, -16(%r11)
	movl	$0, -16(%r14)
	movl	$0, -16(%r15)
	jmp	.LBB0_4
	.p2align	4, 0x90
.LBB0_24:
	shll	(%r8)
.LBB0_4:
	movl	(%r8), %ebx
	cmpl	-48(%rbp), %ebx
	jge	.LBB0_20
	movl	$0, (%rdx)
	.p2align	4, 0x90
.LBB0_6:
	movl	-48(%rbp), %ebx
	subl	(%r8), %ebx
	cmpl	%ebx, (%rdx)
	jge	.LBB0_24
	movl	(%rdx), %ebx
	addl	(%r8), %ebx
	movl	%ebx, (%r13)
	movl	(%rdx), %ebx
	addl	(%r8), %ebx
	movl	%ebx, (%rdi)
	addl	(%r8), %ebx
	movl	%ebx, (%r12)
	cmpl	-48(%rbp), %ebx
	jle	.LBB0_9
	movl	-48(%rbp), %ebx
	movl	%ebx, (%r12)
.LBB0_9:
	movl	$0, (%rcx)
	jmp	.LBB0_10
	.p2align	4, 0x90
.LBB0_14:
	movslq	(%rcx), %rsi
	movslq	(%rdi), %rbx
	movl	-460(%rbp,%rbx,4), %ebx
	movl	%ebx, (%rax,%rsi,4)
	incl	(%rcx)
	incl	(%rdi)
.LBB0_10:
	movl	(%rdx), %ebx
	cmpl	(%r13), %ebx
	jge	.LBB0_15
	movl	(%r12), %ebx
	cmpl	%ebx, (%rdi)
	jge	.LBB0_15
	movslq	(%rdx), %rbx
	movl	-460(%rbp,%rbx,4), %ebx
	movslq	(%rdi), %rsi
	cmpl	-460(%rbp,%rsi,4), %ebx
	jge	.LBB0_14
	movslq	(%rcx), %rsi
	movslq	(%rdx), %rbx
	movl	-460(%rbp,%rbx,4), %ebx
	movl	%ebx, (%rax,%rsi,4)
	incl	(%rcx)
	incl	(%rdx)
	jmp	.LBB0_10
	.p2align	4, 0x90
.LBB0_16:
	movslq	(%rcx), %rsi
	movslq	(%rdx), %rbx
	movl	-460(%rbp,%rbx,4), %ebx
	movl	%ebx, (%rax,%rsi,4)
	incl	(%rcx)
	incl	(%rdx)
.LBB0_15:
	movl	(%rdx), %esi
	cmpl	(%r13), %esi
	jl	.LBB0_16
	jmp	.LBB0_17
	.p2align	4, 0x90
.LBB0_18:
	decl	(%rdi)
	movl	(%rcx), %esi
	decl	%esi
	movl	%esi, (%rcx)
	movslq	(%rdi), %rbx
	movslq	%esi, %rsi
	movl	(%rax,%rsi,4), %esi
	movl	%esi, -460(%rbp,%rbx,4)
.LBB0_17:
	cmpl	$0, (%rcx)
	jg	.LBB0_18
	movl	(%r12), %esi
	movl	%esi, (%rdx)
	jmp	.LBB0_6
.LBB0_20:
	movl	$0, -44(%rbp)
	leaq	.L__unnamed_3(%rip), %rbx
	.p2align	4, 0x90
.LBB0_21:
	movl	-44(%rbp), %eax
	cmpl	-48(%rbp), %eax
	jge	.LBB0_23
	movslq	-44(%rbp), %rax
	movl	-460(%rbp,%rax,4), %esi
	movq	%rbx, %rdi
	xorl	%eax, %eax
	callq	printf@PLT
	incl	-44(%rbp)
	jmp	.LBB0_21
.LBB0_23:
	xorl	%eax, %eax
	leaq	-40(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
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
	.asciz	"%d"
	.size	.L__unnamed_2, 3

	.type	.L__unnamed_3,@object
.L__unnamed_3:
	.asciz	"%d\n"
	.size	.L__unnamed_3, 4

	.section	".note.GNU-stack","",@progbits
