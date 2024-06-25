#include <stdio.h>

#include "common/utils.h"


void print_results(const float max, IIterable* indexes)
{
    printf("MAX: %f\n", max);
    printf("indexes: \n\t");
    foreach_T(int, iter, indexes)
    {
        printf("%i  ", *iter);
    }
    printf("\n");
}