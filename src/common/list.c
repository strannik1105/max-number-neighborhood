#include <stdlib.h>

#include "alloc.h"

struct Node
{
    struct Node* prev;
    void* data;
};


struct List
{
    struct Node* root;
};


/*
    params:
        data - ptr to data which will be stored in Node
        prev - ptr to previos Node, may be NULL
*/
static struct Node* _make_node(void* data, struct Node* prev)
{
    struct Node* node = ALLOC(struct Node);
    node->data = data;
    node->prev = prev;

    return node;
}

struct List* make_list()
{
    struct List* lst = ALLOC(struct List);
    lst->root = NULL;
    return lst;
}

void list_append(struct List* lst, void* item)
{
    if(lst->root == NULL)
    {
        lst->root = _make_node(item, NULL);
    }
    else
    {
        struct Node* last_node = lst->root;
        lst->root = _make_node(item, last_node);
    }
}

void* list_pop(struct List* lst)
{
    void* data = NULL;
    struct Node* old_root = lst->root;
    
    if(old_root == NULL)
    {
        return NULL;
    }

    data = old_root->data;
    lst->root = old_root->prev;

    free(old_root);

    return data;
}

static void _delete_list(struct Node* cur)
{
    if(cur->prev != NULL)
    {
        _delete_list(cur->prev);
    }

    free(cur->data);   
    free(cur);
}

void delete_list(struct List* lst)
{
    if(lst->root != NULL)
    {
        _delete_list(lst->root);
    }
    
    free(lst);
}