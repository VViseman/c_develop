	.file	"connect.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"argument count mismatch error.\n"
.LC1:
	.string	"invalid port number.\n"
.LC2:
	.string	"socket() failed."
.LC3:
	.string	"bind() failed."
.LC4:
	.string	"listen() failed."
.LC5:
	.string	"accept() failed."
.LC6:
	.string	"connected from %s.\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movl	%edi, -68(%rbp)
	movq	%rsi, -80(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	cmpl	$2, -68(%rbp)
	je	.L2
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$31, %edx
	movl	$1, %esi
	leaq	.LC0(%rip), %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L2:
	movq	-80(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi@PLT
	movw	%ax, -62(%rbp)
	cmpw	$0, -62(%rbp)
	jne	.L3
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$21, %edx
	movl	$1, %esi
	leaq	.LC1(%rip), %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L3:
	movl	$6, %edx
	movl	$1, %esi
	movl	$2, %edi
	call	socket@PLT
	movl	%eax, -56(%rbp)
	cmpl	$0, -56(%rbp)
	jns	.L4
	leaq	.LC2(%rip), %rdi
	call	perror@PLT
	movl	$1, %edi
	call	exit@PLT
.L4:
	leaq	-48(%rbp), %rax
	movl	$16, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
	movw	$2, -48(%rbp)
	movl	$0, %edi
	call	htonl@PLT
	movl	%eax, -44(%rbp)
	movzwl	-62(%rbp), %eax
	movl	%eax, %edi
	call	htons@PLT
	movw	%ax, -46(%rbp)
	leaq	-48(%rbp), %rcx
	movl	-56(%rbp), %eax
	movl	$16, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	bind@PLT
	testl	%eax, %eax
	jns	.L5
	leaq	.LC3(%rip), %rdi
	call	perror@PLT
	movl	$1, %edi
	call	exit@PLT
.L5:
	movl	-56(%rbp), %eax
	movl	$5, %esi
	movl	%eax, %edi
	call	listen@PLT
	testl	%eax, %eax
	jns	.L6
	leaq	.LC4(%rip), %rdi
	call	perror@PLT
	movl	$1, %edi
	call	exit@PLT
.L6:
	movl	$16, -60(%rbp)
	leaq	-60(%rbp), %rdx
	leaq	-32(%rbp), %rcx
	movl	-56(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	accept@PLT
	movl	%eax, -52(%rbp)
	cmpl	$0, -52(%rbp)
	jns	.L7
	leaq	.LC5(%rip), %rdi
	call	perror@PLT
	movl	$1, %edi
	call	exit@PLT
.L7:
	movl	-28(%rbp), %eax
	movl	%eax, %edi
	call	inet_ntoa@PLT
	movq	%rax, %rsi
	leaq	.LC6(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-52(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	jmp	.L6
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
