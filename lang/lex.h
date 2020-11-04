enum Token {
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
    END
};

enum Token* parse_config();
