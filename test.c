#include <stdio.h>
#include "iter.h"

#define NEWLINE printf("\n")

int main()
{
    Iter ss = h_iter(char *, ((char *[]){"Smashing", "The", "Stack"}));
    char **elements = (char **)ss.xs;

    size_t i = 0;
    while (i < ss.count) {
        printf("%s ", elements[i++]);
    }

    NEWLINE;

    free_iter(&ss);

    Iter ints = h_iter(int, ((int []){1, 2, 3, 4}));
    int *int_elements = (int *)ints.xs;

    for (size_t j = 0; j < ints.count; j++) {
        printf("%d ", int_elements[j]);
    }

    NEWLINE;

    free_iter(&ints);
    return 0;
}
