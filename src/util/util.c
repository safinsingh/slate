#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../include/util/util.h"

void error(const char* msg, ...) {
    va_list args;
    fprintf(stderr, "error: ");
    va_start(args, msg);
    vfprintf(stderr, msg, args);
    va_end(args);
    fprintf(stderr, "\n");
    exit(1);
}
