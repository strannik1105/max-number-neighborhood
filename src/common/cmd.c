#include <stdio.h>
#include <stdlib.h>

#include "common/utils.h"
#include "common/cmd.h"
#include "common/list.h"


static CMDParseResult* make_cmd_parse_result(enum ParseStatus status, int diff, int count, List* arr)
{
    CMDParseResult* parse_result = ALLOC(CMDParseResult);

    parse_result->status = status;
    parse_result->diff = diff;
    parse_result->count = count;
    parse_result->arr = (IIterable*)arr;

    return parse_result;
}

CMDParseResult* parse_cmd(const int argc, const char *argv[])
{
    enum ParseStatus status = CMD_SUCCESS;
    List* arr = make_list();
    int k;
    int n;

    if(argc < 5)
    {
        status = CMD_TOO_FEW_ARGS;
    }
    else
    {
        k = strtol(argv[1], NULL, 10);
        n = strtol(argv[2], NULL, 10);

        if(argc < 3 + n)
        {
            status = CMD_TOO_FEW_ARGS;
        }
        else if(argc > 3 + n)
        {
            status = CMD_TOO_MANY_ARGS;
        }
        else
        {
            for(int i = 3; i < 3 + n; i++)
            {
                float* item = ALLOC(float);
                *item = strtod(argv[i], NULL);
                list_append(arr, item);
            }
        }
    }
    
    return make_cmd_parse_result(status, k, n, arr);
}

void print_err_msg(CMDParseResult* result)
{
    switch (result->status)
    {
    case CMD_INCORRECT_ARGS:
        printf("Incorrect args provided\n");
    case CMD_TOO_FEW_ARGS:
        printf("Too few args provided\n");
    case CMD_TOO_MANY_ARGS:
        printf("Too many args provided\n");
    }
}

void remove_parse_result(CMDParseResult* ptr)
{
    REMOVE_ITERABLE(ptr->arr);
    free(ptr);
}
