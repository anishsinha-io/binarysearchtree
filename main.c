#include "linkedlist/linkedlist.h"
#include "bst/bst.h"
#include "queue/queue.h"
#include "stack/stack.h"

int main() {
    List *list1 = new_list();
    l_insert(list1, 3);
    l_insert(list1, 4);
    l_insert(list1, 1);
    l_insert(list1, 6);
    l_insert(list1, 5);
    l_insert(list1, 8);
    l_insert(list1, 2);
    l_insert(list1, 7);
    TNode *root = sorted_list_to_bst(list1);
    iterative_inorder_traversal(root);
    return 0;
}
