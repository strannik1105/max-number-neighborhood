#include <stdio.h>

#include "common/cmd.h"
#include "common/list.h"
#include "common/utils.h"


int main(const int argc, const char *argv[])
{
  CMDParseResult* parse_result = parse_cmd(argc, argv);
  IIterable* values = parse_result->arr;
  float* max = NEXT(float, values);
  float diff = parse_result->diff;

  foreach_T(float, iter, values)
  {
    if(*iter > *max)
    {
      max = iter;
    }
  }
  
  printf("MAX: %f\n", *max);
  remove_parse_result(parse_result);
  return 0;
}