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
	subq	$496, %rsp              # imm = 0x1F0
	movl	$0, -4(%rbp)
	movl	$0, -412(%rbp)
	movabsq	$.L__unnamed_1, %rdi
	leaq	-4(%rbp), %rsi
	movb	$0, %al
	callq	scanf
	xorl	%ecx, %ecx
	movl	%ecx, -416(%rbp)        # 4-byte Spill
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	movl	-416(%rbp), %eax        # 4-byte Reload
	cmpl	-4(%rbp), %eax
	movl	%eax, -420(%rbp)        # 4-byte Spill
	jge	.LBB0_3
# %bb.2:                                #   in Loop: Header=BB0_1 Depth=1
	movabsq	$.L__unnamed_2, %rdi
	leaq	-412(%rbp), %rsi
	movb	$0, %al
	callq	scanf
	movl	-412(%rbp), %ecx
	movl	-420(%rbp), %edx        # 4-byte Reload
	movslq	%edx, %rsi
	movl	%ecx, -408(%rbp,%rsi,4)
	addl	$1, %edx
	movl	%edx, -416(%rbp)        # 4-byte Spill
	jmp	.LBB0_1
.LBB0_3:
	movq	%rsp, %rax
	movq	%rax, %rcx
	addq	$-16, %rcx
	movq	%rcx, %rsp
	movl	$0, -16(%rax)
	movq	%rsp, %rax
	movq	%rax, %rdx
	addq	$-16, %rdx
	movq	%rdx, %rsp
	movl	$0, -16(%rax)
	movq	%rsp, %rax
	movq	%rax, %rsi
	addq	$-16, %rsi
	movq	%rsi, %rsp
	movl	$0, -16(%rax)
	movq	%rsp, %rax
	movq	%rax, %rdi
	addq	$-16, %rdi
	movq	%rdi, %rsp
	movl	$0, -16(%rax)
	movq	%rsp, %rax
	movq	%rax, %r8
	addq	$-16, %r8
	movq	%r8, %rsp
	movl	$0, -16(%rax)
	movq	%rsp, %rax
	movq	%rax, %r9
	addq	$-16, %r9
	movq	%r9, %rsp
	movl	$0, -16(%rax)
	movq	%rsp, %rax
	addq	$-416, %rax             # imm = 0xFE60
	movq	%rax, %rsp
	movl	$1, (%rcx)
	movl	$0, (%rsi)
	movl	$0, (%rdi)
	movl	$0, (%r8)
	movl	$0, (%r9)
	movq	%rcx, -432(%rbp)        # 8-byte Spill
	movq	%rdx, -440(%rbp)        # 8-byte Spill
	movq	%rsi, -448(%rbp)        # 8-byte Spill
	movq	%rdi, -456(%rbp)        # 8-byte Spill
	movq	%r8, -464(%rbp)         # 8-byte Spill
	movq	%r9, -472(%rbp)         # 8-byte Spill
	movq	%rax, -480(%rbp)        # 8-byte Spill
.LBB0_4:                                # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_7 Depth 2
                                        #       Child Loop BB0_13 Depth 3
                                        #       Child Loop BB0_19 Depth 3
                                        #       Child Loop BB0_22 Depth 3
	movq	-432(%rbp), %rax        # 8-byte Reload
	movl	(%rax), %ecx
	cmpl	-4(%rbp), %ecx
	jge	.LBB0_6
# %bb.5:                                #   in Loop: Header=BB0_4 Depth=1
	movq	-448(%rbp), %rax        # 8-byte Reload
	movl	$0, (%rax)
	jmp	.LBB0_7
.LBB0_6:
	xorl	%eax, %eax
	movl	%eax, -484(%rbp)        # 4-byte Spill
	jmp	.LBB0_25
.LBB0_7:                                #   Parent Loop BB0_4 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB0_13 Depth 3
                                        #       Child Loop BB0_19 Depth 3
                                        #       Child Loop BB0_22 Depth 3
	movq	-448(%rbp), %rax        # 8-byte Reload
	movl	(%rax), %ecx
	movl	-4(%rbp), %edx
	movq	-432(%rbp), %rsi        # 8-byte Reload
	subl	(%rsi), %edx
	cmpl	%edx, %ecx
	jge	.LBB0_9
# %bb.8:                                #   in Loop: Header=BB0_7 Depth=2
	movq	-448(%rbp), %rax        # 8-byte Reload
	movl	(%rax), %ecx
	movq	-432(%rbp), %rdx        # 8-byte Reload
	addl	(%rdx), %ecx
	movq	-456(%rbp), %rsi        # 8-byte Reload
	movl	%ecx, (%rsi)
	movl	(%rax), %ecx
	addl	(%rdx), %ecx
	movq	-464(%rbp), %rdi        # 8-byte Reload
	movl	%ecx, (%rdi)
	movl	(%rdi), %ecx
	addl	(%rdx), %ecx
	movq	-472(%rbp), %r8         # 8-byte Reload
	movl	%ecx, (%r8)
	movl	(%r8), %ecx
	movl	-4(%rbp), %r9d
	cmpl	%r9d, %ecx
	jg	.LBB0_10
	jmp	.LBB0_11
.LBB0_9:                                #   in Loop: Header=BB0_4 Depth=1
	movq	-432(%rbp), %rax        # 8-byte Reload
	movl	(%rax), %ecx
	shll	$1, %ecx
	movl	%ecx, (%rax)
	jmp	.LBB0_4
.LBB0_10:                               #   in Loop: Header=BB0_7 Depth=2
	movl	-4(%rbp), %eax
	movq	-472(%rbp), %rcx        # 8-byte Reload
	movl	%eax, (%rcx)
	jmp	.LBB0_12
.LBB0_11:                               #   in Loop: Header=BB0_7 Depth=2
	jmp	.LBB0_12
.LBB0_12:                               #   in Loop: Header=BB0_7 Depth=2
	movq	-440(%rbp), %rax        # 8-byte Reload
	movl	$0, (%rax)
.LBB0_13:                               #   Parent Loop BB0_4 Depth=1
                                        #     Parent Loop BB0_7 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movq	-448(%rbp), %rax        # 8-byte Reload
	movl	(%rax), %ecx
	movq	-456(%rbp), %rdx        # 8-byte Reload
	movl	(%rdx), %esi
	cmpl	%esi, %ecx
	setl	%dil
	movq	-464(%rbp), %r8         # 8-byte Reload
	movl	(%r8), %ecx
	movq	-472(%rbp), %r9         # 8-byte Reload
	cmpl	(%r9), %ecx
	setl	%r10b
	andb	%r10b, %dil
	testb	$1, %dil
	jne	.LBB0_14
	jmp	.LBB0_15
.LBB0_14:                               #   in Loop: Header=BB0_13 Depth=3
	movq	-448(%rbp), %rax        # 8-byte Reload
	movslq	(%rax), %rcx
	movl	-408(%rbp,%rcx,4), %edx
	movq	-464(%rbp), %rcx        # 8-byte Reload
	movl	(%rcx), %esi
	movslq	%esi, %rdi
	cmpl	-408(%rbp,%rdi,4), %edx
	jl	.LBB0_16
	jmp	.LBB0_17
.LBB0_15:                               #   in Loop: Header=BB0_7 Depth=2
	jmp	.LBB0_19
.LBB0_16:                               #   in Loop: Header=BB0_13 Depth=3
	movq	-440(%rbp), %rax        # 8-byte Reload
	movl	(%rax), %ecx
	movq	-448(%rbp), %rdx        # 8-byte Reload
	movl	(%rdx), %esi
	movslq	%esi, %rdi
	movl	-408(%rbp,%rdi,4), %r8d
	movslq	%ecx, %rdi
	movslq	%esi, %r9
	movq	-480(%rbp), %r10        # 8-byte Reload
	movl	%r8d, (%r10,%rdi,4)
	movl	(%rax), %ecx
	addl	$1, %ecx
	movl	%ecx, (%rax)
	movl	(%rdx), %ecx
	addl	$1, %ecx
	movl	%ecx, (%rdx)
	jmp	.LBB0_18
.LBB0_17:                               #   in Loop: Header=BB0_13 Depth=3
	movq	-440(%rbp), %rax        # 8-byte Reload
	movl	(%rax), %ecx
	movq	-464(%rbp), %rdx        # 8-byte Reload
	movl	(%rdx), %esi
	movslq	%esi, %rdi
	movl	-408(%rbp,%rdi,4), %r8d
	movslq	%ecx, %rdi
	movslq	%esi, %r9
	movq	-480(%rbp), %r10        # 8-byte Reload
	movl	%r8d, (%r10,%rdi,4)
	movl	(%rax), %ecx
	addl	$1, %ecx
	movl	%ecx, (%rax)
	movl	(%rdx), %ecx
	addl	$1, %ecx
	movl	%ecx, (%rdx)
.LBB0_18:                               #   in Loop: Header=BB0_13 Depth=3
	jmp	.LBB0_13
.LBB0_19:                               #   Parent Loop BB0_4 Depth=1
                                        #     Parent Loop BB0_7 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movq	-448(%rbp), %rax        # 8-byte Reload
	movl	(%rax), %ecx
	movq	-456(%rbp), %rdx        # 8-byte Reload
	cmpl	(%rdx), %ecx
	jge	.LBB0_21
# %bb.20:                               #   in Loop: Header=BB0_19 Depth=3
	movq	-440(%rbp), %rax        # 8-byte Reload
	movl	(%rax), %ecx
	movq	-448(%rbp), %rdx        # 8-byte Reload
	movl	(%rdx), %esi
	movslq	%esi, %rdi
	movl	-408(%rbp,%rdi,4), %r8d
	movslq	%ecx, %rdi
	movslq	%esi, %r9
	movq	-480(%rbp), %r10        # 8-byte Reload
	movl	%r8d, (%r10,%rdi,4)
	movl	(%rax), %ecx
	addl	$1, %ecx
	movl	%ecx, (%rax)
	movl	(%rdx), %ecx
	addl	$1, %ecx
	movl	%ecx, (%rdx)
	jmp	.LBB0_19
.LBB0_21:                               #   in Loop: Header=BB0_7 Depth=2
	jmp	.LBB0_22
.LBB0_22:                               #   Parent Loop BB0_4 Depth=1
                                        #     Parent Loop BB0_7 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movq	-440(%rbp), %rax        # 8-byte Reload
	movl	(%rax), %ecx
	cmpl	$0, %ecx
	jle	.LBB0_24
# %bb.23:                               #   in Loop: Header=BB0_22 Depth=3
	movq	-464(%rbp), %rax        # 8-byte Reload
	movl	(%rax), %ecx
	subl	$1, %ecx
	movl	%ecx, (%rax)
	movq	-440(%rbp), %rdx        # 8-byte Reload
	movl	(%rdx), %ecx
	subl	$1, %ecx
	movl	%ecx, (%rdx)
	movl	(%rax), %ecx
	movl	(%rdx), %esi
	movslq	%esi, %rdi
	movq	-480(%rbp), %r8         # 8-byte Reload
	movl	(%r8,%rdi,4), %r9d
	movslq	%ecx, %rdi
	movslq	%esi, %r10
	movl	%r9d, -408(%rbp,%rdi,4)
	jmp	.LBB0_22
.LBB0_24:                               #   in Loop: Header=BB0_7 Depth=2
	movq	-472(%rbp), %rax        # 8-byte Reload
	movl	(%rax), %ecx
	movq	-448(%rbp), %rdx        # 8-byte Reload
	movl	%ecx, (%rdx)
	jmp	.LBB0_7
.LBB0_25:                               # =>This Inner Loop Header: Depth=1
	movl	-484(%rbp), %eax        # 4-byte Reload
	cmpl	-4(%rbp), %eax
	movl	%eax, -488(%rbp)        # 4-byte Spill
	jge	.LBB0_27
# %bb.26:                               #   in Loop: Header=BB0_25 Depth=1
	movl	-488(%rbp), %eax        # 4-byte Reload
	movslq	%eax, %rcx
	movl	-408(%rbp,%rcx,4), %esi
	movabsq	$.L__unnamed_3, %rdi
	movslq	%eax, %rcx
	movb	$0, %al
	movq	%rcx, -496(%rbp)        # 8-byte Spill
	callq	printf
	movl	-488(%rbp), %edx        # 4-byte Reload
	addl	$1, %edx
	movl	%edx, -484(%rbp)        # 4-byte Spill
	jmp	.LBB0_25
.LBB0_27:
	xorl	%eax, %eax
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
