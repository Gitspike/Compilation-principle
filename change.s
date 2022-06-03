	.text
	.file	"main"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movl	$0, 20(%rsp)
	movl	$0, 16(%rsp)
	movabsq	$.L__unnamed_1, %rdi
	leaq	20(%rsp), %rsi
	movb	$0, %al
	callq	scanf
	movabsq	$.L__unnamed_2, %rdi
	leaq	16(%rsp), %rsi
	movl	%eax, 12(%rsp)          # 4-byte Spill
	movb	$0, %al
	callq	scanf
	movl	20(%rsp), %ecx
	cmpl	16(%rsp), %ecx
	jle	.LBB0_2
# %bb.1:
	movl	20(%rsp), %eax
	movl	16(%rsp), %ecx
	movl	%ecx, 20(%rsp)
	movl	%eax, 16(%rsp)
	jmp	.LBB0_3
.LBB0_2:
	jmp	.LBB0_3
.LBB0_3:
	movl	20(%rsp), %edx
	movabsq	$.L__unnamed_3, %rdi
	movl	$97, %esi
	movb	$0, %al
	callq	printf
	movl	16(%rsp), %edx
	movabsq	$.L__unnamed_4, %rdi
	movl	$98, %esi
	movl	%eax, 8(%rsp)           # 4-byte Spill
	movb	$0, %al
	callq	printf
	xorl	%ecx, %ecx
	movl	%eax, 4(%rsp)           # 4-byte Spill
	movl	%ecx, %eax
	addq	$24, %rsp
	.cfi_def_cfa_offset 8
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
	.asciz	"%c%d\n"
	.size	.L__unnamed_3, 6

	.type	.L__unnamed_4,@object   # @3
.L__unnamed_4:
	.asciz	"%c%d\n"
	.size	.L__unnamed_4, 6

	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym printf
	.addrsig_sym scanf
