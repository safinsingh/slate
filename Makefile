DEFAULT_GOAL := dev

dev:
	gcc -std=c99 -g cli/main.c cli/util.c lang/lex.c -o slate.exe

debug:
	gdb slate.exe