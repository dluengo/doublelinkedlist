#ifndef __DOUBLE_LINKED_LIST_H_
#define __DOUBLE_LINKED_LIST_H_

// Nodes of the list, intended to be used just by the list (i.e. not public).
struct node_t {
    void *data;
    struct node_t *prev;
    struct node_t *next;
};

// The list itself. The name stands for Double-Linked List.
typedef struct {
    unsigned int size;
    struct node_t *head;
    struct node_t *tail;
} DLList_t;

DLList_t *DLList_Create();

void DLList_Destroy(DLList_t *self);

int DLList_Append(DLList_t *self, void *data);

void *DLList_Access(DLList_t *self, unsigned int pos);

unsigned int DLList_Size(DLList_t *self);

void DLList_Print(DLList_t *self, void (*print_data)(void *data_to_print));

#endif
