#include <stdio.h>
#include <stdlib.h>

#include "../include/lang/lex.h"
#include "../include/util/util.h"

char* read_config() {
    size_t size;
    size_t res;
    char* buf;

    FILE* f = fopen("build.rock", "r");
    if (f == NULL) {
        error("Failed to open file: `build.sc`");
    }

    fseek(f, 0, SEEK_END);
    size = ftell(f);
    fseek(f, 0, SEEK_SET);

    buf = (char*)calloc(size, sizeof(char));
    if (buf == NULL) {
        error("Failed to allocate config file buffer");
    }

    res = fread(buf, sizeof(char), size, f);
    if (res != size) {
        error("Failed to read config file buffer");
    }

    fclose(f);
    return buf;
}

int main() {
    char* content        = read_config();
    struct Lexer* parsed = parse_config(content);

    lexer_print_tokens(parsed);

    return 0;
}
