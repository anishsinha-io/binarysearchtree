#include <stdbool.h>

#ifndef BINARYSEARCHTREE_QUEUE_H
#define BINARYSEARCHTREE_QUEUE_H

typedef struct GQueueEntity GQueueEntity;
typedef struct GQueue GQueue;

void *get_entity_val(GQueueEntity *);
void *first(GQueue *);
void enqueue(GQueue *, void *);
void *dequeue(GQueue *);
bool q_empty(GQueue *);
bool q_full(GQueue *);
void *get_index(GQueue *, unsigned int);
GQueue *new_queue(void);
void enqueue_many(GQueue *, unsigned int, ...);
unsigned int entity_count(GQueue *);

#endif //BINARYSEARCHTREE_QUEUE_H
