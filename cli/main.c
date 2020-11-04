#include <stdio.h>
#include <stdlib.h>

#include "../lang/lex.h"
#include "util.h"

char* read_config() {
    FILE* f = fopen("build.sc", "r");
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
    char* content = read_config();
    enum Token* parsed = parse_config(content);

    for (int i = 0; i < 10000000; i++) {
        printf("%d", parsed[i]);
    }

    return 0;
}
