#ifndef LANG_LEX_H
#define LANG_LEX_H

struct Lexer {
    char* input;
    int cursor;
    int column;
    int line;
    int t_len;
    struct Token* tokens;
};

enum TokType {
    Assign,
    Dollar,
    LParen,
    RParen,
    LBracket,
    RBracket,
    LBrace,
    RBrace,
    Comma,
    Bang,
    Ident,
    Newline,
    Undefined,
    Comment
};

struct Token {
    int line;
    int col;
    enum TokType kind;
};

struct Lexer* parse_config();

void lexer_print_tokens(struct Lexer* l);

#endif