#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lex.h"

struct Lexer {
    char* input;
    int cursor;
    int pseudo_cursor;
    int line;
    enum Token* tokens;
};

struct Lexer lexer_new(char* source) {
    struct Lexer l;
    strcpy(l.input, source);
    l.cursor = 0;
    l.pseudo_cursor = 0;
    l.line = 1;
    return l;
}

void lexer_append_token(struct Lexer* l, enum Token t) {
    int arr_sz = sizeof(l->tokens) / sizeof(enum Token);
    if (arr_sz != 0 && (arr_sz % 100) == 0) {
        enum Token* new_tok = (enum Token*)malloc(arr_sz + 100);
        new_tok[arr_sz] = t;
        memcpy(new_tok, l->tokens, sizeof(new_tok));
        l->tokens = new_tok;
    } else {
        printf("rot");
        l->tokens[arr_sz] = t;
        printf("rot");
    }
}

void lexer_eat_token(struct Lexer* l, enum Token t) {
    lexer_append_token(l, t);
    l->cursor += 1;
}

char lexer_get_char(struct Lexer l, int pos) {
    if (pos <= strlen(l.input)) {
        return l.input[pos];
    } else {
        return '\0';
    }
}

enum Token* parse_config(char* config_str) {
    struct Lexer l = lexer_new(config_str);
    enum Token* tokens[100];

    char current_char = lexer_get_char(l, l.cursor);
    while (current_char != '\0') {
        char next = lexer_get_char(l, l.cursor + 1);
        switch (current_char) {
            case '\n':
                lexer_eat_token(&l, Newline);
                break;
            default:
                lexer_eat_token(&l, Undefined);
                break;
        }
        current_char = lexer_get_char(l, l.cursor);
    }

    lexer_append_token(&l, EOF);
}
