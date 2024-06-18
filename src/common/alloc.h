#ifndef ALLOC_H
#define ALLOC_H

#include <signal.h>
#include <stdlib.h>

static void* _alloc(const size_t size)
{
    void* ptr = malloc(size);
    if(ptr == NULL)
        raise(-1);
    return ptr;
}

#define ALLOC(T) (T*)_alloc(sizeof(T))

#endif