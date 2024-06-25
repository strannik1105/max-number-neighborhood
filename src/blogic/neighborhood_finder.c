#include <stdbool.h>
#include <math.h>
#include <memory.h>

#include "common/list.h"
#include "common/utils.h"


static bool is_neighbour(const float value1, const float value2, const float diff)
{
  if(fabs(value1 - value2) <= value1*(((float)diff)/100.0F))
  {
    return true;
  }
  return false;
}

IIterable* find_neighborhood(IIterable* values, float diff, float max)
{
    List* indexes = make_list();
    int index = 0;

    foreach_T(float, iter, values)
    {
        if(is_neighbour(*iter, max, diff) == true)
        {
            int* ap_list = ALLOC(int);
            memcpy(ap_list, &index, sizeof(int));
            list_append(indexes, ap_list);
        }
        index++; 
    }

    return (IIterable*)indexes;
}