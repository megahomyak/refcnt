#include "refcnt/refcnt.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define assert(expression) \
    if (!(expression)) { \
        fprintf(stderr, "Assertion failure on line %d", __LINE__); \
        exit(1); \
    } \

int main(void) {
    char* str = malloc_counted(16);

    assert(str != NULL);

    strcpy(str, "hello!");

    char* str2 = copy_counted(str);
    char* str3 = copy_counted(str);

    assert(3 == *(size_t*)(((void*) str) - sizeof(size_t)));

    assert(0 == strcmp(str3, "hello!"));

    free_counted(str3);
    assert(2 == *(size_t*)(((void*) str) - sizeof(size_t)));

    free_counted(str2);
    assert(1 == *(size_t*)(((void*) str) - sizeof(size_t)));

    free_counted(str);

    return 0;
}
