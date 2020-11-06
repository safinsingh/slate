DEFAULT_GOAL    :=  dev
CC              :=  gcc
SOURCES         :=  src/app.c src/util/util.c src/lang/lex.c \
                    src/cli/cli.c
CFLAGS          :=  -ansi -Wall -Werror \
                    -Wextra -pedantic -pedantic-errors \
                    -Wshadow -Wformat=2 -Wformat-truncation \
                    -Wundef -DSLATE_VERSION='"0.1.0"'

dev:
	$(CC) $(CFLAGS) $(SOURCES) -g3 -o slate

run:
	$(CC) $(CFLAGS) $(SOURCES) -g3 -o slate && \
	./slate

release:
	$(CC) $(CFLAGS) $(SOURCES) -o slate
