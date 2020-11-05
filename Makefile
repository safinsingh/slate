DEFAULT_GOAL := dev

dev:
	gcc -std=c99 -Wall -Werror -g app/main.c util/util.c lang/lex.c -o slate.exe

debug:
	gdb slate.exe