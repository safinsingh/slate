DEFAULT_GOAL    :=  dev
CC              :=  gcc
SOURCES         :=  src/main.c src/util/util.c src/lang/lex.c
CFLAGS          :=  -ansi -Wall -Werror \
                    -Wextra -pedantic -pedantic-errors \
                    -Wshadow -Wformat=2 -Wformat-truncation \
                    -Wundef

dev:
	$(CC) $(CFLAGS) $(SOURCES) -g3 -o slate

run:
	$(CC) $(CFLAGS) $(SOURCES) -g3 -o slate && \
	./slate

release:
	$(CC) $(CFLAGS) $(SOURCES) -o slate
