#ifndef LIST_H
#define LIST_H

// it's must names Stack but.....
typedef struct List {} List;

// create List object
void make_list();

// append new value into List
void list_append(List* lst, void* item);

// get value from List and remove it
void* list_pop(List* lst);

// delete List object
void delete_list(List* lst);

#endif