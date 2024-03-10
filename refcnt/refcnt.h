#ifndef MEGAHOMYAK_REFCNT
#define MEGAHOMYAK_REFCNT

#include <stdlib.h>

// Same as stdlib `malloc()`, except that it is reference-counted. You should only use functions from this library to modify reference-counted allocations, stdlib functions will not work
//
// First argument: the amount of bytes in the allocation
//
// Return value: the pointer to the allocation, `NULL` on failure
void* malloc_counted(size_t);

// Same as stdlib `calloc()`, except that it is reference-counted. You should only use functions from this library to modify reference-counted allocations, stdlib functions will not work
//
// First argument: the amount of items in an array you want to allocate
// Second argument: the size of one item
//
// Return value: the pointer to the allocation, `NULL` on failure
void* calloc_counted(size_t, size_t);

// Extends or shrinks the provided reference-counted allocation
//
// First argument: a non-NULL pointer retrieved from `malloc_counted()`, `calloc_counted()` or `realloc_counted()`
// Second argument: the new size of the allocation
//
// Return value: the pointer to the reallocation (may be the same as the passed pointer), `NULL` on failure
void* realloc_counted(void*, size_t);

// Increments the reference counter and returns the passed pointer. Should be used when you want to store a copy of a pointer for an indefinite amount of time
//
// First argument: a non-NULL pointer retrieved from `malloc_counted()`, `calloc_counted()` or `realloc_counted()`
//
// Return value: the same pointer as the one passed in
void* copy_counted(void*);

// Decrements the reference counter, frees the allocation if the counter reaches zero. You should call this function when you're disposing of a pointer
//
// First argument: a non-NULL pointer retrieved from `malloc_counted()`, `calloc_counted()` or `realloc_counted()`
void free_counted(void*);

#endif
