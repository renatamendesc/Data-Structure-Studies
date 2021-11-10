#include "binarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>

int main (void) {

    Tree * tree = tree_create();

    tree_insert(tree, 6);
    tree_insert(tree, 2);
    tree_insert(tree, 8);
    tree_insert(tree, 1);
    tree_insert(tree, 4);
    tree_insert(tree, 3);

    printf("\nDoes '6' exist? %d\n", tree_belong(tree, 6));
    printf("Does '9' exist? %d\n\n", tree_belong(tree, 9));

    // Original tree
    printf("Tree nodes: ");
    tree_print(tree);

    // Removing node with one son
    tree_erase(tree, 4);
    printf("\nErasing 4...\n");

    printf("Tree nodes: ");
    tree_print(tree);

    // Removing node with two sons
    tree_erase(tree, 6);
    printf("\nErasing 6...\n");

    printf("Tree nodes: ");
    tree_print(tree);

    // Searches element
    TreeNode * node = tree_search(tree, 2);

    printf("\nDepth: %d\n", tree_depth(tree));

    tree_free(tree);

    return 0;
} 