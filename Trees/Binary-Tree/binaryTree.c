#include "binaryTree.h"
#include <stdio.h>
#include <stdlib.h>

struct tree {

    TreeNode * root;
};

struct treeNode {

    char info;

    TreeNode * left;
    TreeNode * right;
};

Tree * tree_create (TreeNode * root) {

    Tree * tree = (Tree *) malloc(sizeof(Tree));

    tree->root = root;

    return tree;
}

TreeNode * tree_create_node (char info, TreeNode * left, TreeNode * right) {

    TreeNode * node = (TreeNode *) malloc(sizeof(TreeNode));

    node->info = info;
    node->left = left;
    node->right = right;

    return node;
}

/*************** FREE FUNCTIONS ***************/

static void deletes (TreeNode * node) {

    if (node != NULL) {

        deletes(node->left);
        deletes(node->right);
        free(node);
    }
}

void tree_free (Tree * tree) {

    deletes(tree->root);
    free(tree);
}

/*************** FREE FUNCTIONS ***************/

/*************** PRINT FUNCTIONS ***************/

static void print (TreeNode * node) {

    if (node != NULL) {

        printf("%c ", node->info);

        print(node->left);
        print(node->right);

    }
}

void tree_print (Tree * tree) {

    print(tree->root);
    printf("\n");

}

/*************** PRINT FUNCTIONS ***************/

/*************** BELONG FUNCTIONS ***************/

static int belong (TreeNode * node, char info) {

    if (node == NULL) return 0;
    else if (node->info == info || belong(node->left, info) || belong(node->right, info)) return 1;
}

int tree_belong (Tree * tree, char info) {

    return belong(tree->root, info);
}

/*************** BELONG FUNCTIONS ***************/

/*************** DEPTH FUNCTIONS ***************/

static int depth (TreeNode * node) {

    if (node == NULL) return -1;
    else return 1 + ((depth(node->left) > depth(node->right)) ? depth(node->left) : depth(node->right));
}

int tree_depth (Tree * tree) {
    
    return depth(tree->root);
}

/*************** DEPTH FUNCTIONS ***************/

// TreeNode * tree_search (Tree * tree, char info) {

// }