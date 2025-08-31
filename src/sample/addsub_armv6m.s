	.syntax unified
	.thumb
	.thumb_func
	.text

	.global addsub
	.type   addsub, %function
	.balign 4

addsub:
	// upperval (add)
	lsrs	r2, r0, #16		// r2 = Rn >> 16
	lsrs	r3, r1, #16		// r3 = Rm >> 16
	adds	r2, r2, r3		// r2 = high(Rn) + high(Rm)
	lsls	r2, r2, #16		// writeback

	// lowerval (sub)
	uxth	r3, r0			// r3 = low(Rn)
	uxth	r0, r1			// r0 = low(Rm)
	subs	r3, r3, r0		// r3 = low(Rn) - low(Rm)

	// final
	uxth	r3, r3			// Mask
	orrs	r0, r2, r3		// r0 = upperval | lowerval
	bx		lr
