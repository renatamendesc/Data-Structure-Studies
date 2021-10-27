#include "binaryTree.h"
#include <stdio.h>
#include <stdlib.h>

int main (void) {

    Tree * tree = tree_create(tree_create_node('a', tree_create_node('b', NULL, tree_create_node('d', NULL, NULL)), tree_create_node('c', tree_create_node('e', NULL, NULL), tree_create_node('f', NULL, NULL))));

    printf("\nDoes 'd' exist? %d\n", tree_belong(tree, 'd'));
    printf("Does 's' exist? %d\n\n", tree_belong(tree, 's'));

    printf("Tree nodes: ");
    tree_print(tree);

    tree_free(tree);

    return 0;
} 