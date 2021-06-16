#ifndef __build_keyboard__
#define __build_keyboard__

// assumes US Keyboard :-/

// X(Set 3) 	keycap
#define KEY_GRAVE 0x29 // 	` ~
#define KEY_ONE 0x02 // 	1 !
#define KEY_TWO 0x03 // 	2 @
#define KEY_THREE 0x04 // 	3 #
#define KEY_FOUR 0x05 // 	4 $
#define KEY_FIVE 0x06 // 	5 % E
#define KEY_SIX 0x07 // 	6 ^
#define KEY_SEVEN 0x08 // 	7 &
#define KEY_EIGHT 0x09 // 	8 *
#define KEY_NINE 0x0a // 	9 (
#define KEY_ZERO 0x0b // 	0 )
#define KEY_MINUS 0x0c // 	- _
#define KEY_PLUS 0x0d // 	= +
#define KEY_BACKSPACE 0x0e // 	Backspace
#define KEY_TAB 0x0f // 	Tab
#define KEY_Q 0x10 // 	Q
#define KEY_W 0x11 // 	W
#define KEY_E 0x12 // 	E
#define KEY_R 0x13 // 	R
#define KEY_T 0x14 // 	T
#define KEY_Y 0x15 // 	Y
#define KEY_U 0x16 // 	U
#define KEY_I 0x17 // 	I
#define KEY_O 0x18 // 	O
#define KEY_P 0x19 // 	P
#define KEY_OPEN_BRACE 0x1a // 	[ {
#define KEY_CLOSE_BRACE 0x1b // 	] }
#define KEY_PIPE 0x75 // 	\ |
// #define KEY_CAPSLOCK 0x1d // 	CapsLock
#define KEY_CAPSLOCK 0x3a // 	CapsLock
#define KEY_A 0x1e // 	A
#define KEY_S 0x1f // 	S
#define KEY_D 0x20 // 	D
#define KEY_F 0x21 // 	F
#define KEY_G 0x22 // 	G
#define KEY_H 0x23 // 	H
#define KEY_J 0x24 // 	J
#define KEY_K 0x25 // 	K
#define KEY_L 0x26 // 	L
#define KEY_COLON 0x27 // 	; :
#define KEY_QUOTE 0x28 // 	' "
// #define KEY_ ff // 	non-US-1
#define KEY_ENTER 0x1c // 	Enter
#define KEY_L_SHIFT 0x2a // 	LShift
#define KEY_Z 0x2c // 	Z
#define KEY_X 0x2d // 	X
#define KEY_C 0x2e // 	C
#define KEY_V 0x2f // 	V
#define KEY_B 0x30 // 	B
#define KEY_N 0x31 // 	N
#define KEY_M 0x32 // 	M
#define KEY_COMMA 0x33 // 	, <
#define KEY_PERIOD 0x34 // 	. >
#define KEY_QUESTION 0x35 // 	/ ?
#define KEY_R_SHIFT 0x36 // 	RShift
// #define KEY_L_CTRL 0x38 // 	LCtrl
#define KEY_L_CTRL 0x1d // 	LCtrl
// #define KEY_L_ALT 0x71 // 	LAlt
#define KEY_L_ALT 0x38 // 	LAlt
#define KEY_SPACE 0x39 // 	space
// #define KEY_R_ALT 0x72 // 	RAlt
#define KEY_R_ALT 0xb8 // 	RAlt
// #define KEY_R_CTRL 0x3a // 	RCtrl
#define KEY_R_CTRL 0x9d // 	RCtrl
// #define KEY_INSERT 0x7b // 	Insert
#define KEY_INSERT 0xd2 // 	Insert
// #define KEY_DELETE 0x79 // 	Delete
#define KEY_DELETE 0xd3 // 	Delete
// #define KEY_HOME 0x7f // 	Home
#define KEY_HOME 0xc7 // 	Home
// #define KEY_END 0x7a // 	End
#define KEY_END 0xcf // 	End

// #define KEY_PG_UP 0x6f // 	PgUp
// #define KEY_PG_DOWN 0x7e // 	PgDn
#define KEY_PG_UP 0xc9 // 	PgUp
#define KEY_PG_DOWN 0xd1 // 	PgDn

// #define KEY_LEFT 0x56 // 	Left
// #define KEY_UP 0x78 // 	Up
// #define KEY_DOWN 0x55 // 	Down
// #define KEY_RIGHT 0x7d // 	Right
#define KEY_LEFT 0xcb // 	Left
#define KEY_UP 0xc8 // 	Up
#define KEY_DOWN 0xd0 // 	Down
#define KEY_RIGHT 0xcd // 	Right

// #define KEY_NUMLOCK 0x01 // 	NumLock
#define KEY_NUMLOCK 0x45 // 	NumLock
#define KEY_KP7_HOME 0x47 // 	KP-7 / Home
#define KEY_KP4_LEFT 0x4b // 	KP-4 / Left
#define KEY_KP1_END 0x4f // 	KP-1 / End
// #define KEY_KP_DIV 0x45 // 	KP-/
#define KEY_KP_DIV 0xb5 // 	KP-/
#define KEY_KP8_UP 0x48 // 	KP-8 / Up
#define KEY_KP5 0x4c // 	KP-5
#define KEY_KP2_DOWN 0x50 // 	KP-2 / Down
#define KEY_KP0_INSERT 0x52 // 	KP-0 / Ins
// #define KEY_KP_TIMES 0x46 // 	KP-*
#define KEY_KP_TIMES 0x37 // 	KP-*
#define KEY_KP9_PG_UP 0x49 // 	KP-9 / PgUp
#define KEY_KP6_RIGHT 0x4d // 	KP-6 / Right
#define KEY_KP3_PG_DOWN 0x51 // 	KP-3 / PgDn
#define KEY_KP_PERIOD_DELETE 0x53 // 	KP-. / Del
// #define KEY_KP_MINUS 0x54 // 	KP--
#define KEY_KP_MINUS 0x4a // 	KP--
// #define KEY_KP_PLUS 0x37 // 	KP-+
#define KEY_KP_PLUS 0x4e // 	KP-+
#define KEY_RETURN_KP_ENTER 0x4e // 	KP-Enter
// #define KEY_ESCAPE 0x64 // 	Esc
#define KEY_ESCAPE 0x1 // 	Esc

// #define KEY_F1 0x58 // 	F1
// #define KEY_F2 0x59 // 	F2
// #define KEY_F3 0x5a // 	F3
// #define KEY_F4 0x5b // 	F4
// #define KEY_F5 0x5c // 	F5
// #define KEY_F6 0x5d // 	F6
// #define KEY_F7 0x5e // 	F7
// #define KEY_F8 0x5f // 	F8
// #define KEY_F9 0x60 // 	F9
// #define KEY_F10 0x61 // 	F10
// #define KEY_F11 0x62 // 	F11
// #define KEY_F12 0x63 // 	F12
#define KEY_F1 0x3b // 	F1
#define KEY_F2 0x3c // 	F2
#define KEY_F3 0x3d // 	F3
#define KEY_F4 0x3e // 	F4
#define KEY_F5 0x3f // 	F5
#define KEY_F6 0x40 // 	F6
#define KEY_F7 0x41 // 	F7
#define KEY_F8 0x42 // 	F8
#define KEY_F9 0x43 // 	F9
#define KEY_F10 0x44 // 	F10
#define KEY_F11 0x57 // 	F11
#define KEY_F12 0x58 // 	F12

#define KEY_PRTSCR 0x6e // 	PrtScr
#define KEY_ALT_SYSRQ 0x6e // 	Alt+SysRq
// #define KEY_SCROLLLOCK 0x76 // 	ScrollLock
#define KEY_SCROLLLOCK 0x46 // 	ScrollLock
// #define KEY_PAUSE 0x77 // 	Pause
#define KEY_PAUSE 0x59 // 	Pause
#define KEY_CTRL_BREAK 0x77 // 	Ctrl+Break
// #define KEY_L_WIN 0x8b // 	LWin (USB: LGUI)
#define KEY_L_WIN 0xdb // 	LWin (USB: LGUI)
// #define KEY_R_WIN 0x8c // 	RWin (USB: RGUI)
#define KEY_R_WIN 0xdc // 	RWin (USB: RGUI)
#define KEY_MENU 0x8d // 	Menu
#define KEY_SLEEP 0x54 // 	Sleep
// #define KEY_POWER ff // 	Power
// #define KEY_WAKE ff // 	Wake 

#endif
