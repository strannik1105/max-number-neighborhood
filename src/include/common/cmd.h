#ifndef CMD_H
#define CMD_H

#include "common/utils.h"


enum ParseStatus
{
    CMD_SUCCESS,
    CMD_TOO_FEW_ARGS,
    CMD_TOO_MANY_ARGS,
    CMD_INCORRECT_ARGS
};

typedef struct
{
    enum ParseStatus status;
    int diff;
    int count;
    IIterable* arr;
} CMDParseResult;


//parse command line args
CMDParseResult* parse_cmd(const int argc, const char *argv[]);
// print error message
void print_err_msg(CMDParseResult* result);

void remove_parse_result(CMDParseResult* ptr);

#endif