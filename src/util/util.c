#include <stdio.h>

#include "../../include/util/util.h"

void error(const char* msg) {
    fprintf(stderr, "%s", msg);
}
