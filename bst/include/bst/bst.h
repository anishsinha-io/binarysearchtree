#include "linkedlist/linkedlist.h"
#include "queue/queue.h"

#ifndef BINARYSEARCHTREE_BST_H
#define BINARYSEARCHTREE_BST_H

typedef struct TNode TNode;

double node_val(TNode *);
TNode *sorted_list_to_bst(List *);
TNode *search(TNode *, double);
void *breadth_first_traversal(TNode *);
void inorder_traversal(TNode *);
void preorder_traversal(TNode *);
void postorder_traversal(TNode *);
void iterative_preorder_traversal(TNode *);
void iterative_postorder_traversal(TNode *);
void iterative_inorder_traversal(TNode *);

#endif //BINARYSEARCHTREE_BST_H
