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

    // Falta testar funcoes de remover e busca

    // printf("\nDoes '6' exist? %d\n", tree_belong(tree, 6));
    // printf("Does '9' exist? %d\n\n", tree_belong(tree, 9));

    printf("Tree nodes: "); // Ajeitar print
    tree_print(tree);

    printf("Depth: %d\n", tree_depth(tree));

    tree_free(tree);

    return 0;
} 