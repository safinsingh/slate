#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/cli/cli.h"

void parse_args(int argc, char** argv) {
    if (argc == 2) {
        if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
            printf("slate v%s\n", SLATE_VERSION);
            exit(0);
        }
    }
}