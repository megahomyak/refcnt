#include "refcnt/refcnt.h"
#include <stdlib.h>
#include <stdio.h>

#define assert(expression) \
    if (!(expression)) { \
        fprintf(stderr, "Assertion failure on line %d", __LINE__); \
        exit(1); \
    } \

int main(void) {
    assert(123);
    return 0;
}
