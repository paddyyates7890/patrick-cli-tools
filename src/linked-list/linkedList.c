#include "linkedList.h"
#include <stdlib.h>

linkedList* create_list(){
    return calloc(1, sizeof(linkedList));
}

void LLdestroy(linkedList *list){
    LLFOREACH(list, first, next, cur){
        if (cur->prev)
        {
            free(cur->prev);
        }
        
    }

    free(list->last);
    free(list);
}

void LLpush(linkedList *list, void *value){
    listNode *node = calloc(1, sizeof(node));
    node->value = value;

    if (list->last == NULL) {
        list->first = node;
        list->last = node;
    } else {
        list->last->next = node;
        node->prev = list->last;
        list->last = node;
    }

    list->count++;
}

void *LLpop(linkedList *list){
    listNode *node = list->last;
    return (node != NULL ? LLremove(list, node) : NULL);
}

void *LLremove(linkedList *list, listNode* node){
    void *result = NULL;

    if (node == list->first && node == list->last) {
        list->first = NULL;
        list->last = NULL;
    } else if (node == list->first) {
        list->first = node->next;
        list->first->prev = NULL;
    } else if (node == list->last) {
        list->last = node->prev;
        list->last->next = NULL;
    } else {
        listNode *after = node->next;
        listNode *before = node->prev;
        after->prev = before;
        before->next = after;
    }
    
    list->count--;
    result = node->value;
    free(node);
    
    return result;
}