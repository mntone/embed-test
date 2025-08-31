	.syntax unified
	.thumb
	.thumb_func
	.text

	.global addsub
	.type   addsub, %function
	.balign 4

addsub:
	sasx	r0, r0, r1
	bx		lr
