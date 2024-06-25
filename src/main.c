#include "blogic/max_searcher.h"
#include "blogic/neighborhood_finder.h"
#include "blogic/repr.h"
#include "common/cmd.h"
#include "common/utils.h"


int main(const int argc, const char *argv[])
{
    CMDParseResult* parse_result = parse_cmd(argc, argv);
    // get cmd args
    IIterable* values = parse_result->arr;
    float diff = parse_result->diff;

    // search max
    float max = search_max(values);
    // search number neigbours
    IIterable* indexes = find_neighborhood(values, diff, max);  

    // print results
    print_results(max, indexes);

    REMOVE_ITERABLE(indexes);
    remove_parse_result(parse_result);
    return 0;
}