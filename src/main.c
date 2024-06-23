#include <stdio.h>

#include "cmd.h"
#include "utils.h"


int main(const int argc, const char *argv[])
{
  CMDParseResult* parse_result = parse_cmd(argc, argv);
  IIterable* values = parse_result->arr;

  foreach_T(float, iter, values)
  {
    printf("%f\n", *(iter));
    free(iter);
  }
  
  remove_parse_result(parse_result);
  return 0;
}