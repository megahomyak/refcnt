#include <stdlib.h>
#include <string.h>

void* malloc_counted(size_t bytes_amount) {
    void* allocation = malloc(bytes_amount + sizeof(size_t));
    if (allocation == NULL) {
        return NULL;
    } else {
        *((size_t*) allocation) = 1;
        return allocation + sizeof(size_t);
    }
}

void* calloc_counted(size_t elements_amount, size_t element_size) {
    void* allocation = malloc_counted(elements_amount * element_size);
    if (allocation != NULL) {
        return NULL;
    } else {
        memset(allocation, 0, elements_amount * element_size);
        return allocation;
    }
}

void* realloc_counted(void* allocation, size_t new_size) {
    void* original_allocation = allocation - sizeof(size_t);

    allocation = realloc(original_allocation, sizeof(size_t) + new_size);

    if (allocation == NULL) {
        return NULL;
    } else {
        return allocation + sizeof(size_t);
    }
}

void* copy_counted(void* allocation) {
    *((size_t*) allocation - sizeof(size_t)) += 1;
    return allocation;
}

void free_counted(void* allocation) {
    void* original_allocation = allocation - sizeof(size_t);

    *((size_t*) original_allocation) -= 1;
    if (*((size_t*) original_allocation) == 0) {
        free(original_allocation);
    }
}
