#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lex.h"

struct Lexer lexer_new(char* source) {
    struct Lexer l;
    l.input = (char*)malloc(strlen(source));
    strcpy(l.input, source);
    l.cursor = 0;
    l.column = 0;
    l.line = 1;
    l.t_len = 0;
    l.tokens = (struct Token*)calloc(100, sizeof(struct Token));
    return l;
}

void lexer_append_token(struct Lexer* l, struct Token t) {
    int arr_sz = l->t_len;

    if (arr_sz != 0 && (arr_sz % 100) == 0) {
        l->tokens = realloc(l->tokens, arr_sz + 100);
        l->tokens[arr_sz] = t;
    } else {
        l->tokens[arr_sz] = t;
    }
    l->t_len++;
}

void lexer_eat_token(struct Lexer* l, struct Token t) {
    lexer_append_token(l, t);
    l->cursor += 1;
    l->column += 1;
}

char lexer_get_char(struct Lexer l, int pos) {
    if (pos <= strlen(l.input)) {
        return l.input[pos];
    } else {
        return '\0';
    }
}

struct Token lexer_gen_token(int ln, int cl, enum TokType kd) {
    struct Token t;
    t.line = ln;
    t.col = cl;
    t.kind = kd;
    return t;
}

struct Lexer parse_config(char* config_str) {
    struct Lexer l = lexer_new(config_str);

    char current_char = lexer_get_char(l, l.cursor);
    while (current_char != '\0') {
        switch (current_char) {
            case '\n':
                lexer_eat_token(&l, GEN_TOK(Newline));
                l.line += 1;
                l.column = 0;
                break;
            default:
                lexer_eat_token(&l, GEN_TOK(Undefined));
                break;
        }
        current_char = lexer_get_char(l, l.cursor);
    }

    return l;
}

void lexer_print_tokens(struct Lexer l) {
    for (int i = 0; i < l.t_len; i++) {
        struct Token* tok = &l.tokens[i];
        switch (tok->kind) {
            case Newline:
                PRINT_TOK("NEWLINE");
                break;
            case Undefined:
                PRINT_TOK("UNDEFINED");
                break;
            default:
                break;
        }
    }
}
