#include <stdbool.h>

#ifndef BINARYSEARCHTREE_STACK_H
#define BINARYSEARCHTREE_STACK_H

typedef struct GStackFrame GStackFrame;
typedef struct GStack GStack;

void *peek(const GStack *);
void push(GStack *, void *);
void *pop(GStack *);
void clear(GStack *);
unsigned int get_capacity(const GStack *);
unsigned int get_remaining_capacity(const GStack *);
bool is_empty(GStack *);
bool is_full(GStack *);

GStack *new_stack(void);

#endif //BINARYSEARCHTREE_STACK_H
