.f	PUSH	FP
	LD	FP,SP
	PUSH	G3
	PUSH	G4
	PUSH	G5
	PUSH	G6
	PUSH	G7
	PUSH	G8
	PUSH	G9
	PUSH	G10
	CALL	__stkChk
	LD	G7,G8
	LD	G9,G10
	POP	G10
	POP	G9
	POP	G8
	POP	G7
	POP	G6
	POP	G5
	POP	G4
	POP	G3
	POP	FP
	RET