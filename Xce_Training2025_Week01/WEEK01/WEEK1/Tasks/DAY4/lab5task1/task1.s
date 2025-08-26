	.file	"task1.c"
	.text
	.section	.rodata
.LC0:
	.string	"Enter dividend:"
.LC1:
	.string	"%d"
.LC2:
	.string	"Enter divisor:"
.LC3:
	.string	"Quotient = %d\n"
.LC4:
	.string	"Remainder = %d\n"
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
	movl	$4, -16(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-36(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	$0, -28(%rbp)
	movl	-36(%rbp), %eax
	movl	%eax, -24(%rbp)
	movl	-32(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L2
.L5:
	movl	-28(%rbp), %eax
	leal	(%rax,%rax), %esi
	movl	-16(%rbp), %eax
	subl	$1, %eax
	movl	-24(%rbp), %edx
	movl	%eax, %ecx
	sarl	%cl, %edx
	movl	%edx, %eax
	andl	$1, %eax
	orl	%esi, %eax
	movl	%eax, -28(%rbp)
	movl	-24(%rbp), %eax
	leal	(%rax,%rax), %edx
	movl	-16(%rbp), %eax
	movl	$1, %esi
	movl	%eax, %ecx
	sall	%cl, %esi
	movl	%esi, %eax
	subl	$1, %eax
	andl	%edx, %eax
	movl	%eax, -24(%rbp)
	movl	-12(%rbp), %eax
	subl	%eax, -28(%rbp)
	cmpl	$0, -28(%rbp)
	jns	.L3
	movl	-12(%rbp), %eax
	addl	%eax, -28(%rbp)
	jmp	.L4
.L3:
	orl	$1, -24(%rbp)
.L4:
	addl	$1, -20(%rbp)
.L2:
	movl	-20(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jl	.L5
	movl	-24(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-28(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L7
	call	__stack_chk_fail@PLT
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
