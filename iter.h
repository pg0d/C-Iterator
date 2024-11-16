#ifndef ITER_H
#define ITER_H

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Iter {
    void *xs;
    size_t count;
    size_t size;
} Iter;

#define h_iter(TYPE, ARRAY) ({                                              \
    static_assert(!__builtin_types_compatible_p(__typeof__(ARRAY), TYPE *), \
        "ARRAY must be an array, not a pointer");                           \
    TYPE *_array = ARRAY;                                                   \
    size_t _count = sizeof(ARRAY) / sizeof(TYPE);                           \
    Iter iter = {                                                             \
        .xs = malloc(_count * sizeof(TYPE)),                                \
        .count = _count,                                                    \
        .size = sizeof(TYPE)                                                \
    };                                                                      \
    if (iter.xs)                                                             \
        memcpy(iter.xs, _array, _count * sizeof(TYPE));                      \
    iter;                                                                    \
})

void free_iter(Iter *iter);

#endif
