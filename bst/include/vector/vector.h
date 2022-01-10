#ifndef BINARYSEARCHTREE_VECTOR_H
#define BINARYSEARCHTREE_VECTOR_H

#ifndef CHAPTER4_VECTOR_H
#define CHAPTER4_VECTOR_H

typedef struct Vector Vector;

Vector *new_vector(void);
void append(struct Vector *, void *);
void set(struct Vector *, unsigned int, void *);
void *get(struct Vector *, unsigned int);
void delete(struct Vector *, unsigned int);
void v_clear(struct Vector *);
unsigned int length(Vector *);

#endif //CHAPTER4_VECTOR_H

#endif //BINARYSEARCHTREE_VECTOR_H
