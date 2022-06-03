	.text
	.file	"main"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	movabsq	$.L__unnamed_1, %rdi
	leaq	-4(%rbp), %rsi
	movb	$0, %al
	callq	scanf
	movabsq	$.L__unnamed_2, %rdi
	leaq	-8(%rbp), %rsi
	movl	%eax, -12(%rbp)         # 4-byte Spill
	movb	$0, %al
	callq	scanf
	movl	-4(%rbp), %ecx
	movl	-8(%rbp), %edx
	movl	%edx, -16(%rbp)         # 4-byte Spill
	movl	%ecx, -20(%rbp)         # 4-byte Spill
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	movl	-20(%rbp), %edx         # 4-byte Reload
	movl	-16(%rbp), %eax         # 4-byte Reload
	cmpl	$0, %eax
	movl	%edx, -24(%rbp)         # 4-byte Spill
	movl	%eax, -28(%rbp)         # 4-byte Spill
	je	.LBB0_3
# %bb.2:                                #   in Loop: Header=BB0_1 Depth=1
	movl	-24(%rbp), %eax         # 4-byte Reload
	cltd
	movl	-28(%rbp), %ecx         # 4-byte Reload
	idivl	%ecx
	movl	%edx, -16(%rbp)         # 4-byte Spill
	movl	%ecx, -20(%rbp)         # 4-byte Spill
	jmp	.LBB0_1
.LBB0_3:
	movq	%rsp, %rax
	addq	$-16, %rax
	movq	%rax, %rsp
	movl	-24(%rbp), %ecx         # 4-byte Reload
	movl	%ecx, (%rax)
	movl	(%rax), %esi
	movabsq	$.L__unnamed_3, %rdi
	movb	$0, %al
	callq	printf
	xorl	%ecx, %ecx
	movl	%eax, -32(%rbp)         # 4-byte Spill
	movl	%ecx, %eax
	movq	%rbp, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	.L__unnamed_1,@object   # @0
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_1:
	.asciz	"%d"
	.size	.L__unnamed_1, 3

	.type	.L__unnamed_2,@object   # @1
.L__unnamed_2:
	.asciz	"%d"
	.size	.L__unnamed_2, 3

	.type	.L__unnamed_3,@object   # @2
.L__unnamed_3:
	.asciz	"%d\n"
	.size	.L__unnamed_3, 4

	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym printf
	.addrsig_sym scanf
