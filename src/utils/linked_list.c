//
// Created by jaszc on 03.01.2016.
//
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include "linked_list.h"

linked_list* linked_list_init(int (*comparator)(void*, void*)){
    linked_list* ll = malloc(sizeof(ll));
    assert(ll != NULL);
    ll->first = NULL;
    ll->last = NULL;
    ll->size = 0;
    ll->equals = comparator;
    return  ll;
}

void linked_list_add(linked_list *ll, void *element){
    node *n = malloc(sizeof(*n));
    n->element = element;
    n->next = NULL;
    if(ll->size == 0){
        ll->first = n;
        ll->last = n;
        ll->size++;
    }
    else {
        ll->last->next = n;
        n->previous = ll->last;
        ll->last = n;
        ll->size++;
    }
}

int linked_list_delete(linked_list *ll, void *element){
    if(ll->size == 0)return 0;
    for(node* iterator = ll->first; iterator != ll->last; iterator = iterator->next){
        if(ll->equals(iterator->element, element)) {
            node *prev = iterator->previous;
            node *next = iterator->next;
            free(iterator);
            if (prev == NULL) {
                ll->first = next;
                next->previous = NULL;
            }
            else {
                next->previous = prev;
                prev->next = next;
            }
            ll->size--;
            return 1;
        }
    }
    if(ll->equals(ll->last->element, element)){
        node *prev = ll->last->previous;
        free(ll->last);
        if(prev == NULL){
            ll->first = NULL;
            ll->last = NULL;
        }
        else{
            ll->last = prev;
            prev->next = NULL;
        }
        ll->size--;
        return 1;
    }
    return 0;
}

int linked_list_contains(linked_list *ll, void *element){
    if(ll->size == 0)return 0;
    for(node* iterator = ll->first; iterator != ll->last; iterator = iterator->next){
        if(ll->equals(iterator->element,  element)) {
            return 1;
        }
    }
    if(ll->equals(ll->last->element, element)){
        return 1;
    }
    return 0;
}

void linked_list_delete_list(linked_list* ll){
    //free(ll);
    return;
}

void linked_list_dispose(linked_list* ll){
    if(ll->size == 0){
        linked_list_delete_list(ll);
        return;
    }
    for(node* iterator = ll->first; iterator != ll->last;){
        node* p = iterator;
        iterator = iterator->next;
        free(p);
    }
    free(ll->last);
    linked_list_delete_list(ll);
}

int default_comparator(void *a, void *b) {
    if(a == b)return 1;
    return 0;
}

