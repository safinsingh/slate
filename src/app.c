#include <stdio.h>
#include <stdlib.h>

#include "../include/cli/cli.h"
#include "../include/lang/lex.h"
#include "../include/util/util.h"

char* read_config(char* config) {
    size_t size;
    size_t res;
    char* buf;
    FILE* f;

    f = fopen(config, "r");
    if (f == NULL) {
        error("failed to open file: `%s`", config);
    }

    fseek(f, 0, SEEK_END);
    size = ftell(f);
    fseek(f, 0, SEEK_SET);

    buf = (char*)calloc(size, sizeof(char));
    if (buf == NULL) {
        error("failed to allocate config file buffer");
    }

    res = fread(buf, sizeof(char), size, f);
    if (res != size) {
        error("failed to read config file buffer");
    }

    fclose(f);
    return buf;
}

int main(int argc, char** argv) {
    char* content;
    struct Lexer* parsed;
    struct Opts* opts;

    opts = parse_args(argc, argv);

    content = read_config(opts->config);
    parsed  = parse_config(content);
    lexer_print_tokens(parsed);

    return 0;
}
