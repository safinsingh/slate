#ifndef LANG_LEX_H
#define LANG_LEX_H

#define PRINT_TOK(T) printf("%d,%d:\t%s\n", tok->line, tok->col, T)

struct Lexer {
    char* input;
    int cursor;
    int column;
    int line;
    int t_len;
    struct Token* tokens;
};

enum TokType {
    // stuff
    Assign,
    Dollar,

    // ??
    LParen,
    RParen,
    LBracket,
    RBracket,

    // punctuation
    Comma,
    Bang,

    // misc
    Ident,
    Newline,
    Undefined,
    Comment,
};

struct Token {
    int line;
    int col;
    enum TokType kind;
};

struct Lexer* parse_config();

void lexer_print_tokens(struct Lexer* l);

#endif  // LANG_LEX_H