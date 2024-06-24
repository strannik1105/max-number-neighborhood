#include <stdio.h>

#include "blogic/max_searcher.h"
#include "common/cmd.h"
#include "common/utils.h"


int main(const int argc, const char *argv[])
{
  CMDParseResult* parse_result = parse_cmd(argc, argv);
  IIterable* values = parse_result->arr;
  float max = search_max(values);
  float diff = parse_result->diff;
  
  printf("MAX: %f\n", max);
  remove_parse_result(parse_result);
  return 0;
}