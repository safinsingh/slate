#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/cli/cli.h"

void help() {
    printf(
        "slate -- a minimal and versatile build system\n"
        "usage:\n"
        "   slate [-c|-v|-h]\n"
        "\n"
        "ARGUMENTS:\n"
        "   -c, --config:   location of build config (default: build.rock)\n"
        "\n"
        "FLAGS:\n"
        "   -v, --version:  print the current version of `slate`\n"
        "   -h, --help:     print this help message\n");
}

struct Opts* parse_args(int argc, char** argv) {
    int i;
    struct Opts* opts;

    opts         = (struct Opts*)malloc(sizeof(struct Opts));
    opts->config = (char*)malloc(sizeof(strlen(DEFAULT_CONFIG)));
    strcpy(opts->config, DEFAULT_CONFIG);

    for (i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--config") == 0) {
            if (i + 1 == argc) {
                printf("invalid argument: %s - no config location specified",
                       argv[i]);
                help();
                exit(1);
            }
            opts->config = (char*)realloc(opts->config, strlen(argv[i + 1]));
            strcpy(opts->config, argv[i + 1]);
        } else if (strcmp(argv[i], "-v") == 0 ||
                   strcmp(argv[i], "--version") == 0) {
            printf("slate v%s\n", SLATE_VERSION);
            exit(0);
        } else if (strcmp(argv[i], "-h") == 0 ||
                   strcmp(argv[i], "--help") == 0) {
            help();
            exit(0);
        }
    }

    if (opts->config[0] == '\0') {
        opts->config = "build.rock";
    }

    return opts;
}