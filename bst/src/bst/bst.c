#include <stdlib.h>
#include "stack/stack.h"
#include <stdio.h>
#include "linkedlist/linkedlist.h"
#include "queue/queue.h"

typedef struct TNode {
    struct TNode *left;
    struct TNode *right;
    double val;
} TNode;

double node_val(TNode *t) {
    return t->val;
}

static TNode *new_tnode(double val) {
    TNode *new_node = malloc(sizeof(TNode));
    new_node->left = new_node->right = NULL;
    new_node->val = val;
    return new_node;
}

static TNode *sorted_list_to_bst_recursive(ListNode **head_pointer, int length) {
    if (length < 1) return NULL;
    TNode *left = sorted_list_to_bst_recursive(head_pointer, length / 2);
    TNode *root = new_tnode(val((*head_pointer)));
    root->left = left;
    *head_pointer = inc_pointer((*head_pointer), 1);
    root->right = sorted_list_to_bst_recursive(head_pointer, length - length / 2 - 1);
    return root;
}

TNode *sorted_list_to_bst(List *l) {
    List *clone = clone_deep(l);
    ListNode *head_pointer = get_head(clone);
    int length = (int) get_length(clone);
    TNode *root = sorted_list_to_bst_recursive(&head_pointer, length);
    clone = NULL;
    head_pointer = NULL;
    free(head_pointer);
    free(clone);
    return root;
}

TNode *search(TNode *r, double val) {
    if (r == NULL) return NULL; // hippity hoppity this null pointer is now your property
    if (r->val == val) return r;
    if (r->val < val) return search(r->right, val);
    if (r->val > val) return search(r->left, val);
}

static void visit(TNode *r) {
    printf("%f\t", node_val(r));
}

void *breadth_first_traversal(TNode *r) {
    GQueue *traversal_queue = new_queue();
    if (r != NULL) {
        enqueue(traversal_queue, r);
        while (!q_empty(traversal_queue)) {
            r = (TNode *) get_entity_val((GQueueEntity *) dequeue(traversal_queue));
            printf("%f\n", node_val(r));
            if (r->left != NULL) enqueue(traversal_queue, r->left);
            if (r->right != NULL) enqueue(traversal_queue, r->right);
        }
    }
}

void inorder_traversal(TNode *r) {
    if (r != NULL) {
        inorder_traversal(r->left);
        visit(r);
        inorder_traversal(r->right);
    }
}

void preorder_traversal(TNode *r) {
    if (r != NULL) {
        visit(r);
        preorder_traversal(r->left);
        preorder_traversal(r->right);
    }
}

void postorder_traversal(TNode *r) {
    if (r != NULL) {
        postorder_traversal(r->left);
        postorder_traversal(r->right);
        visit(r);
    }
}

void iterative_preorder_traversal(TNode *r) {
    TNode *it = r;
    GStack *traversal_stack = new_stack();
    if (it != NULL) {
        push(traversal_stack, it);
        while (!is_empty(traversal_stack)) {
            it = (TNode *) pop(traversal_stack);
            visit(it);
            if (it->right != NULL) push(traversal_stack, it->right);
            if (it->left != NULL) push(traversal_stack, it->left);
        }
    }
}

void iterative_postorder_traversal(TNode *r) {
    TNode *it1 = r, *it2 = r;
    GStack *traversal_stack = new_stack();
    while (it1 != NULL) {
        for (; it1->left != NULL; it1 = it1->left) push(traversal_stack, it1);
        while (it1->right == NULL || it1->right == it2) {
            visit((TNode *) it1);
            it2 = it1;
            if (is_empty(traversal_stack)) return;
            it1 = (TNode *) pop(traversal_stack);
        }
        push(traversal_stack, it1);
        it1 = it1->right;
    }
}

void iterative_inorder_traversal(TNode *r) {
    TNode *it = r;
    GStack *traversal_stack = new_stack();
    while (it != NULL) {
        while (it != NULL) {
            if (it->right) push(traversal_stack, it->right);
            push(traversal_stack, it);
            it = it->left;
        }
        it = pop(traversal_stack);
        while (!is_empty(traversal_stack) && it->right == NULL) {
            visit(it);
            it = pop(traversal_stack);
        }
        visit(it);
        if (!is_empty(traversal_stack)) it = pop(traversal_stack);
        else it = NULL;
    }
}

void insert(TNode *r, double val) {
    TNode *p = r, *prev = NULL;
    while (p != NULL) {
        prev = p;
        if (val < p->val) p = p->left;
        else p = p->right;
    }
    if (r == NULL || prev == NULL) return;
    else if (val < prev->val) prev->left = new_tnode(val);
    else prev->right = new_tnode(val);
}

static TNode *delete_helper(TNode *r, double val) {
    TNode *t = r;
    if (r == NULL) return NULL;
    if (r->val == val) return r;
    if (r->val < val) return search(r->right, val);
    if (r->val > val) return search(r->left, val);
}

static bool is_leaf(TNode *t) {
    return t->left == NULL && t->right == NULL;
}

void delete_node(TNode *r, double val) {
    TNode *t = r;
    if (r == NULL) return;
    while (r != NULL) {
        if (r->val < val) {
            t = r;
            r = r->right;
        } else if (r->val > val) {
            t = r;
            r = r->left;
        } else break;
    }
    if (is_leaf(r)) {
        if (r->val > t->val) {
            t->right = NULL;
        } else {
            t->left = NULL;
        }
        r = NULL;
        free(r);
    } else if (r->right == NULL) {
        t->left = r->left;
        r = NULL;
        free(r);
    } else if (r->left == NULL) {
        t->right = r->right;
        r = NULL;
        free(r);
    } else {
        TNode *tmp = r->left;
        while (tmp->right != NULL) tmp = tmp->right;
        tmp->right = r->right;
        if (tmp->val < t->val) {
            t->left = tmp;
        } else {
            t->right = tmp;
        }
        r = NULL;
        free(r);
    }
}
