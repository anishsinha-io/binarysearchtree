#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Vector {
    unsigned int length;
    unsigned int capacity;
    void **items;

} Vector;

unsigned int length(Vector *v) {
    return v->length;
}

static void resize(struct Vector *v, unsigned int new_capacity) {
    void **data = realloc(v->items, sizeof(void *) * new_capacity);
    if (data) {
        v->items = data;
        v->capacity = new_capacity;
    }
}

void append(struct Vector *v, void *item) {
    if (v->length == v->capacity) {
        resize(v, (unsigned int) (ceil((float) v->capacity * 1.25)));
    }
    v->items[v->length++] = item;
}

void set(struct Vector *v, unsigned int index, void *item) {
    if (v->length >= index) v->items[index] = item;
}

void *get(struct Vector *v, unsigned int index) {
    if (v->length >= index) {
        return v->items[index];
    }
    return NULL;
}

void delete(struct Vector *v, unsigned int index) {
    if (index > v->length) return;
    v->items[index] = NULL;
    for (unsigned int i = index; i < v->length - 1; i++) {
        v->items[i] = v->items[i + 1];
    }
    v->length--;
    if (v->length < v->capacity / 4) resize(v, v->capacity / 2);
}

void v_clear(struct Vector *v) {
    free(v->items);
}


Vector *new_vector() {
    Vector *new_vector = malloc(sizeof(Vector));
    new_vector->capacity = 50;
    new_vector->length = 0;
    new_vector->items = malloc(sizeof(void *) * new_vector->capacity);
    return new_vector;
}