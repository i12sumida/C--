.a	WS	1
.b	WS	1
.c	WS	1
.d	WS	1
.e	WS	1
.f	DW	10
.g	DW	20
.h	WS	1
.L1	DW	1000
	DW	2000
	DW	3000
.i	DW	.L1
.j	WS	1
.k	WS	1
.L2	DW	4000
	DW	5000
.L3	DW	6000
	DW	7000
	DW	8000
.L4	DW	.L2
	DW	.L3
.l	DW	.L4
.L5	DW	1
	DW	2
.L6	DW	3
	DW	4
	DW	5
.L7	DW	6
.L8	DW	7
	DW	8
.L9	DW	9
.L10	DW	.L5
	DW	.L6
.L11	DW	.L7
	DW	.L8
	DW	.L9
.L12	DW	.L10
	DW	.L11
.m	DW	.L12
.L13	STRING	"aaaa"
.n	DW	.L13
.L14	STRING	"abc"
.L15	DB	97
	DB	98
	DB	0
.L16	DW	.L14
	DW	.L15
.o	DW	.L16
.L17	DW	6
.L18	DW	7
	DW	8
.L19	DW	9
.L20	WS	10
.L21	DW	.L17
	DW	.L18
	DW	.L19
.L22	DW	.L20
	DW	.L21
.p	DW	.L22
.pq	WS	1
.f1	PUSH	FP
	LD	FP,SP
	PUSH	G3
	CALL	__stkChk
	LD	G3,#1
	POP	G3
	POP	FP
	RET
.L23	STRING	"ab"
.L24	STRING	"cd"
.L25	DW	.L23
	DW	.L24
.L26	WS	3
.L27	DW	.L25
	DW	.L26
.q	DW	.L27
.L28	STRING	"ABCDE"
.f2	PUSH	FP
	LD	FP,SP
	PUSH	G3
	PUSH	G4
	PUSH	G5
	PUSH	G6
	PUSH	G7
	CALL	__stkChk
	LD	G0,#10
	PUSH	G0
	CALL	.malloc
	ADD	SP,#2
	LD	G5,G0
	LD	G6,4,FP
	LD	G7,4,FP
	LD	G6,#30
	LD	G7,#.L28
	LD	G3,#10
	LD	G0,G3
	AND	G0,#0x00ff
	ST	G0,.b
	LD	G4,.b
	LD	G0,.i
	ADDS	G0,G3
	ST	G4,0,G0
	LD	G4,#10
	LD	G3,G4
	LD	G4,#10
	LD	G0,.i
	ADDS	G0,G3
	ST	G4,0,G0
	LD	G4,#20
	LD	G0,.i
	ADDS	G0,G4
	ST	G4,0,G0
	LD	G0,.i
	ADDS	G0,G3
	ST	G4,0,G0
	LD	G0,.l
	ADDS	G0,#1
	LD	G0,0,G0
	ADDS	G0,#2
	LD	G3,0,G0
	LD	G0,.i
	ADDS	G0,#5
	LD	G1,.l
	ADDS	G1,0,G0
	LD	G0,.i
	ADDS	G0,G3
	LD	G1,0,G1
	ADDS	G1,0,G0
	LD	G3,0,G1
	LD	G0,.i
	ADDS	G0,G3
	LD	G1,#20
	ST	G1,0,G0
	LD	G0,.i
	ADDS	G0,#5
	LD	G2,.l
	ADDS	G2,0,G0
	LD	G0,.i
	ADDS	G0,G3
	LD	G2,0,G2
	ADDS	G2,0,G0
	ST	G1,0,G2
	LD	G0,G3
	POP	G7
	POP	G6
	POP	G5
	POP	G4
	POP	G3
	POP	FP
	RET
.f3	PUSH	FP
	LD	FP,SP
	PUSH	G3
	CALL	__stkChk
	LD	G3,#1
	LD	G0,G3
	POP	G3
	POP	FP
	RET
.f4	PUSH	FP
	LD	FP,SP
	SUB	SP,#26
	PUSH	G3
	PUSH	G4
	PUSH	G5
	PUSH	G6
	PUSH	G7
	PUSH	G8
	PUSH	G9
	PUSH	G10
	PUSH	G11
	CALL	__stkChk
	LD	G0,.a
	OR	G0,.b
	LD	G3,G0
	LD	G0,.a
	MUL	G0,.b
	XOR	G0,#2
	LD	G4,G0
	LD	G0,.a
	AND	G0,.b
	LD	G5,G0
	LD	G0,.a
	CMP	G0,.b
	LD	G6,#1
	JZ	.T0
	LD	G6,#0
.T0
	LD	G0,.a
	AND	G0,#0x00ff
	CMP	G0,.b
	LD	G7,#1
	JNZ	.T1
	LD	G7,#0
.T1
	LD	G0,.a
	CMP	G0,.b
	LD	G8,#1
	JLT	.T2
	LD	G8,#0
.T2
	LD	G0,.a
	CMP	G0,.b
	LD	G9,#1
	JLE	.T3
	LD	G9,#0
.T3
	LD	G0,.a
	CMP	G0,.b
	LD	G10,#1
	JGT	.T4
	LD	G10,#0
.T4
	LD	G0,.a
	CMP	G0,.b
	LD	G11,#1
	JGE	.T5
	LD	G11,#0
.T5
	LD	G0,.a
	SHLA	G0,.b
	ST	G0,-2,FP
	LD	G0,.a
	SHRA	G0,.b
	ST	G0,-4,FP
	LD	G0,.a
	ADD	G0,.b
	ST	G0,-6,FP
	LD	G0,.a
	SUB	G0,.b
	ST	G0,-8,FP
	LD	G0,.a
	MUL	G0,.b
	ST	G0,-10,FP
	LD	G0,.a
	DIV	G0,.b
	ST	G0,-12,FP
	LD	G0,.a
	MOD	G0,.b
	ST	G0,-14,FP
	LD	G0,.a
	XOR	G0,#-1
	ADD	G0,#1
	ST	G0,-16,FP
	LD	G0,.a
	ST	G0,-18,FP
	LD	G0,G6
	XOR	G0,#1
	ST	G0,-20,FP
	LD	G0,.a
	XOR	G0,#-1
	ST	G0,-22,FP
	LD	G0,.a
	MUL	G0,.b
	ADD	G0,#6
	LD	G1,.c
	MUL	G1,.d
	ADD	G0,G1
	ST	G0,-24,FP
	CMP	G6,#0
	JZ	.L30
	LD	G0,G7
	JMP	.L29
.L30
	LD	G0,#0
.L29
	ST	G0,-26,FP
	LD	G0,.pq
	ADDS	G0,#2
	LD	G1,#2
	ST	G1,0,G0
	POP	G11
	POP	G10
	POP	G9
	POP	G8
	POP	G7
	POP	G6
	POP	G5
	POP	G4
	POP	G3
	LD	SP,FP
	POP	FP
	RET