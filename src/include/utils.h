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

// macro for simple allocation
#define ALLOC(T) (T*)_alloc(sizeof(T))

// interface provides functions to make object Iterable
typedef struct IIterable
{
    // must return values consistently
    void* (* _next_getter)(struct IIterable* it);
    void* cur;
} IIterable;

// foreach implementation for Iterable
#define foreach_T(T, iter, iterable) \
    for(T* iter = iterable->_next_getter(iterable); iter != NULL; iter = (T*)iterable->_next_getter(iterable))

#define foreach(iter, iterable) foreach_T(void, iter, iterable)

#endif