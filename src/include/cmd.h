#ifndef CMD_H
#define CMD_H

#include "list.h"


enum ParseStatus
{
    CMD_SUCCESS,
    CMD_TOO_FEW_ARGS,
    CMD_TOO_MANY_ARGS,
    CMD_INCORRECT_ARGS
};

typedef struct
{
    int diff;
    int count;
    List* arr;
} CMDParseResult;


//parse command line args
CMDParseResult* parse_cmd(const int argc, const char *argv[]);
// print error message and stop program if status not SUCCESS
void raise_from_result(CMDParseResult* result);

#endif