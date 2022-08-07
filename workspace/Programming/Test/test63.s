	.file	"test63.c"
	.section	.rodata
.LC0:
	.string	"executing %s address:%p\n"
	.text
	.globl	fn1
	.type	fn1, @function
fn1:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	$.LC0, %eax
	movq	-8(%rbp), %rdx
	movl	$__func__.2045, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	fn1, .-fn1
	.globl	fn2
	.type	fn2, @function
fn2:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	$.LC0, %eax
	movq	-8(%rbp), %rdx
	movl	$__func__.2050, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	fn2, .-fn2
	.globl	fn3
	.type	fn3, @function
fn3:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	$.LC0, %eax
	movq	-8(%rbp), %rdx
	movl	$__func__.2055, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	fn3, .-fn3
	.globl	fns
	.data
	.align 16
	.type	fns, @object
	.size	fns, 24
fns:
	.quad	fn1
	.quad	fn2
	.quad	fn3
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$3, -4(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L5
.L6:
	movl	-8(%rbp), %eax
	cltq
	movq	fns(,%rax,8), %rdx
	movl	-8(%rbp), %eax
	cltq
	movq	fns(,%rax,8), %rax
	movq	%rax, %rdi
	call	*%rdx
	addl	$1, -8(%rbp)
.L5:
	movl	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jl	.L6
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.section	.rodata
	.type	__func__.2055, @object
	.size	__func__.2055, 4
__func__.2055:
	.string	"fn3"
	.type	__func__.2050, @object
	.size	__func__.2050, 4
__func__.2050:
	.string	"fn2"
	.type	__func__.2045, @object
	.size	__func__.2045, 4
__func__.2045:
	.string	"fn1"
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
