#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lex.h"

struct Lexer* lexer_new(char* source) {
    struct Lexer* l = (struct Lexer*)malloc(sizeof(struct Lexer));

    l->input  = (char*)malloc(strlen(source));
    l->cursor = 0;
    l->column = 0;
    l->line   = 1;
    l->t_len  = 0;
    l->tokens = (struct Token*)calloc(100, sizeof(struct Token));

    strcpy(l->input, source);
    return l;
}

void lexer_append_token(struct Lexer* l, struct Token t) {
    int arr_sz = l->t_len;

    if (arr_sz != 0 && (arr_sz % 100) == 0) {
        l->tokens         = realloc(l->tokens, arr_sz + 100);
        l->tokens[arr_sz] = t;
    } else {
        l->tokens[arr_sz] = t;
    }
    l->t_len++;
}

void lexer_translate(struct Lexer* l) {
    l->cursor += 1;
    l->column += 1;
}

char lexer_get_char(struct Lexer* l, int pos) {
    if (pos <= strlen(l->input)) {
        return l->input[pos];
    }
    return '\0';
}

void lexer_eat_token(struct Lexer* l, struct Token t) {
    lexer_append_token(l, t);
    lexer_translate(l);
}

struct Token lexer_gen_token(struct Lexer* l, enum TokType kind) {
    struct Token t;
    t.line = l->line;
    t.col  = l->column;
    t.kind = kind;
    return t;
}

void lexer_eat_newline(struct Lexer* l) {
    lexer_eat_token(l, lexer_gen_token(l, Newline));
    l->line += 1;
    l->column = 0;
}

void lexer_eat_comment(struct Lexer* l) {
    lexer_append_token(l, lexer_gen_token(l, Comment));
    char current_char = lexer_get_char(l, l->cursor);

    while (current_char != '\0') {
        if (current_char == '\n') {
            lexer_eat_newline(l);
            break;
        } else {
            lexer_translate(l);
        }
        current_char = lexer_get_char(l, l->cursor);
    }
}

struct Lexer* parse_config(char* config_str) {
    struct Lexer* l = lexer_new(config_str);

    char current_char = lexer_get_char(l, l->cursor);
    while (current_char != '\0') {
        switch (current_char) {
            case '\n':
                lexer_eat_newline(l);
                break;
            case '#':
                lexer_eat_comment(l);
                break;
            default:
                lexer_eat_token(l, lexer_gen_token(l, Undefined));
                break;
        }
        current_char = lexer_get_char(l, l->cursor);
    }

    return l;
}

void lexer_print_tokens(struct Lexer* l) {
    for (int i = 0; i < l->t_len; i++) {
        struct Token* tok = &l->tokens[i];
        switch (tok->kind) {
            case Newline:
                PRINT_TOK("NEWLINE");
                break;
            case Undefined:
                PRINT_TOK("UNDEFINED");
                break;
            case Comment:
                PRINT_TOK("COMMENT");
                break;
            default:
                break;
        }
    }
}
