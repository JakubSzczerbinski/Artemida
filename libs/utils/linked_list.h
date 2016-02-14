//
// Created by jaszc on 03.01.2016.
//

#ifndef ARTEMIDA_LINKED_LIST_H
#define ARTEMIDA_LINKED_LIST_H

typedef struct linked_list{
    int size;
    struct node *first, *last;
    int (*equals)(void* a, void* b);
}linked_list;

typedef struct node{
    struct node *next, *previous;
    void *element;
}node;

extern linked_list* linked_list_init(int (*comparator)(void*, void*));
extern void linked_list_add(linked_list *ll, void *element);
extern int linked_list_delete(linked_list *ll, void *element);
extern int linked_list_contains(linked_list *ll, void *element);
extern void linked_list_dispose(linked_list* ll);
extern int default_comparator(void* a, void* b);

#endif //ARTEMIDA_LINKED_LIST_H
