#include "common/utils.h"


float search_max(IIterable* values)
{
    float max;

    foreach_T(float, iter, values)
    {
        if(*iter > max)
        {
            max = *iter;
        }
    }

    return max;
}