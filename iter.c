#include "iter.h"

void free_iter(Iter *iter) {
    if (iter->xs) {
        free(iter->xs);
        iter->xs = NULL;
    }
    iter->count = 0;
    iter->size = 0;
}