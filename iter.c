#include "iter.h"

void map(Iter *iter, void (*f)(void *)) {
    for (size_t i = 0; i < iter->count; i++) {
        f((char *)iter->xs + i * iter->size);
    }
}

void free_iter(Iter *iter)
{
    if (iter->xs) {
        free(iter->xs);
        iter->xs = NULL;
    }
    iter->count = 0;
    iter->size = 0;
}