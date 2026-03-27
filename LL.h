#ifndef LL_H
#define LL_H

struct node {
  int data;
  struct node* next;
};

typedef struct node node_t;


typedef struct {
  node_t* head;
  node_t* tail;
  int size;
} LL_t;


// Creates and returns a new, empty list
LL_t * LLcreate();

// Adds a new element to the head of a list
void LL_add_to_head(LL_t* list, int value);

// Adds a new element to the tail of a list
void LL_add_to_tail(LL_t* list, int value);

// Removes the first element from a list
int LL_remove_from_head(LL_t* list);

// Returns the size of the list
int LL_size(LL_t* list);

// Outputs the list elements in order from head to tail
void LL_print(LL_t * list);

// releases the memore used by node
void LLnode_free(node_t* node);

// releases the memore used by list
void LL_free(LL_t* list);


#endif
