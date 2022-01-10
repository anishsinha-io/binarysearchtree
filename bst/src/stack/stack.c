#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct GStackFrame {
    struct GStackFrame *bottom;
    void *val;
} GStackFrame;

typedef struct GStack {
    unsigned int capacity;
    unsigned int frame_count;
    const GStackFrame *top;
} GStack;

unsigned int get_capacity(const GStack *g) {
    return g->capacity;
}

unsigned int get_remaining_capacity(const GStack *g) {
    return g->capacity - g->frame_count;
}

bool is_empty(GStack *g) {
    return g->frame_count == 0;
}

bool is_full(GStack *g) {
    return g->frame_count == g->capacity;
}

void *peek(const GStack *self) {
    if (self->top != NULL) return self->top->val;
    return NULL;
}

static GStackFrame *create_frame(void *val) {
    GStackFrame *new_frame = malloc(sizeof(GStackFrame));
    new_frame->bottom = NULL;
    new_frame->val = val;
    return new_frame;
}

void push(GStack *g, void *val) {
    if (is_full(g)) return;
    GStackFrame *new_frame = create_frame(val);
    GStackFrame *t = (GStackFrame *) g->top;
    new_frame->bottom = t;
    g->top = (const GStackFrame *) new_frame;
    g->frame_count++;
}

void *pop(GStack *g) {
    if (is_empty(g)) return NULL;
    void *v = g->top->val;
    if (g->frame_count == 1) {
        free((void *) g->top);
        g->top = NULL;
    } else {
        g->top = (const GStackFrame *) (g->top->bottom);
    }
    g->frame_count--;
    return v;
}

void clear(GStack *g) {
    if (g->frame_count == 0) return;
    while (g->top != NULL) {
        GStackFrame *t = (GStackFrame *) g->top;
        g->top = g->top->bottom;
        t = NULL;
        free(t);
        g->frame_count--;
    }
}

GStack *new_stack() {
    GStack *new_stack = malloc(sizeof(GStack));
    new_stack->capacity = 50;
    new_stack->frame_count = 0;
    new_stack->top = NULL;
    return new_stack;
}
