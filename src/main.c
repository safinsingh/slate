#include <stdio.h>
#include <stdlib.h>

#include "util.c"

char* read_config() {
    FILE* f = fopen("build.sl", "r");
    if (f == NULL) {
        error("Failed to open file: `build.sl`");
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
    char* file = read_config();
    printf("%s", file);
    return 0;
}
