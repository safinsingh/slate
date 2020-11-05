#include <stdio.h>
#include <stdlib.h>

#include "../lang/lex.h"
#include "../util/util.h"

char* read_config() {
    FILE* f = fopen("build.rock", "r");
    if (f == NULL) {
        error("Failed to open file: `build.sc`");
    }

    fseek(f, 0, SEEK_END);
    int size = ftell(f);
    fseek(f, 0, SEEK_SET);

    char* buf = (char*)calloc(size, sizeof(char));
    if (buf == NULL) {
        error("Failed to allocate config file buffer");
    }

    size_t res = fread(buf, sizeof(char), size, f);
    if (res != size) {
        error("Failed to read config file buffer");
    }

    fclose(f);
    return buf;
}

int main() {
    char* content       = read_config();
    struct Lexer parsed = parse_config(content);

    lexer_print_tokens(parsed);

    return 0;
}
