#include "DLList.h"

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

struct node_t *Node_Create() {
    struct node_t *node;

    node = malloc(sizeof(struct node_t));
    if (node != NULL) {
        node->data = node->next = node->prev = NULL;
    }

    return node;
}

void Node_Destroy(struct node_t *node) {
    free(node);
    return;
}

DLList_t *DLList_Create() {
    DLList_t *list;

    list = malloc(sizeof(DLList_t));
    if (list != NULL) {
        list->size = 0;
        list->head = NULL;
        list->tail = NULL;
    }

    return list;
}

void DLList_Destroy(DLList_t *self) {
    struct node_t *curr_node, *next_node;

    if (self != NULL) {
        curr_node = self->head;
        while (curr_node != NULL) {
            next_node = curr_node->next;
            Node_Destroy(curr_node);
            curr_node = next_node;
        }
    }

    free(self);
    return;
}

int DLList_Append(DLList_t *self, void *data) {
    struct node_t *last_node, *new_node;

    assert(self != NULL && data != NULL);

    new_node = Node_Create();
    assert(new_node != NULL);
    if (self->tail == NULL) {
        self->head = self->tail = new_node;
    } else {
        new_node->prev = self->tail;
        self->tail = self->tail->next = new_node;
    }

    new_node->data = data;    
    self->size++;
    return 0;
}

void *DLList_Access(DLList_t *self, unsigned int pos) {
    struct node_t *node;
    unsigned int idx;

    assert(self != NULL && pos < self->size);

    if (pos < self->size/2) {
        for (idx = 0, node = self->head; idx < pos; idx++, node = node->next);
    } else {
        for (idx = self->size-1, node = self->tail; idx > pos; idx--, node = node->prev);
    }

    return node->data;
}

unsigned int DLList_Size(DLList_t *self) {
    assert(self != NULL);
    return self->size;
}

void DLList_Print(DLList_t *self, void (*print_data)(void *data_to_print)) {
    struct node_t *node;
    const int ELEMS_PER_ROW = 5;
    unsigned int idx;

    assert(self != NULL && print_data != NULL);

    printf("[");
    for (idx = 0, node = self->head; node != NULL; idx++, node = node->next) {
        print_data(node->data);
        if (idx % ELEMS_PER_ROW == ELEMS_PER_ROW-1) {
           printf("\n"); 
        } else {
            printf(",");
        }
    }

    printf("]\n");
    return;
}

