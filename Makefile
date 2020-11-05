DEFAULT_GOAL 	:= 	dev
CC 				:= 	gcc
SOURCES			:= 	src/main.c src/util/util.c src/lang/lex.c
CFLAGS 			:= 	-std=c99 -Wall -Werror \
					-Wextra -pedantic -pedantic-errors \
					-Wshadow -Wformat=2 -Wformat-truncation \
					-Wundef

dev:
	$(CC) $(CFLAGS) $(SOURCES) -g3 -o slate

release:
	$(CC) $(CFLAGS) $(SOURCES) -o slate
