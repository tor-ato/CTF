	.file	"rop.c"
	.text
	.section	.rodata
.LC0:
	.string	"You can put message 4 times"
.LC1:
	.string	"Input (%d/4) >> "
.LC2:
	.string	"Output : %s\n"
.LC3:
	.string	"Bye!"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	$0, -32(%rbp)
	movq	$0, -24(%rbp)
	movq	stdout(%rip), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	setbuf@PLT
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	movl	$0, -36(%rbp)
	jmp	.L2
.L3:
	movl	-36(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-32(%rbp), %rax
	movl	$112, %edx
	movq	%rax, %rsi
	movl	$0, %edi
	call	read@PLT
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -36(%rbp)
.L2:
	cmpl	$3, -36(%rbp)
	jle	.L3
	leaq	.LC3(%rip), %rdi
	call	execve@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	subq	%fs:40, %rcx
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 10.5.0-1ubuntu1~22.04) 10.5.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
