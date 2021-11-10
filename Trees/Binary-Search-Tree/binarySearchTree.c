#include "binarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>

struct tree {

    TreeNode * root;
};

struct treeNode {

    int info;

    TreeNode * left;
    TreeNode * right;
};

Tree * tree_create () {

    Tree * tree = (Tree *) malloc(sizeof(Tree));

    tree->root = NULL;

    return tree;
}

/*************** INSERT FUNCTIONS ***************/

static TreeNode * insert (TreeNode * node, int info) {

    if (node == NULL) {

        node = (TreeNode *) malloc(sizeof(TreeNode));

        node->info = info;
        node->left = NULL;
        node->right = NULL;

    } else if (info < node->info) {

        node->left = insert(node->left, info);

    } else if (info > node->info) {

        node->right = insert(node->right, info);
    }

    return node;
}

void tree_insert (Tree * tree, int info) {

    tree->root = insert(tree->root, info);
}

/*************** INSERT FUNCTIONS ***************/

/*************** REMOVE FUNCTIONS ***************/

static TreeNode * erase (TreeNode * node, int info) {

    if (node == NULL) return NULL;

    if (info < node->info) {

        node->left = erase(node->left, info);

    } else if (info > node->info) {

        node->right = erase(node->right, info);

    } else { // Element was found

        if (node->left == NULL && node->right == NULL) {

            free (node);
            node = NULL;

        } else if (node->left == NULL) {

            TreeNode * deleted = node;
            node = node->right;
            free(deleted);

        } else if (node->right == NULL) {

            TreeNode * deleted = node;
            node = node->left;
            free(deleted);

        } else {

            TreeNode * successor = node->left;

            while (successor->right != NULL) successor = successor->right;

            node->info = successor->info;
            successor->info = info;
            node->left = erase(node->left, info); 
        }
    }

    return node;
}

void tree_erase (Tree * tree, int info) {

    tree->root = erase(tree->root, info);
}

/*************** REMOVE FUNCTIONS ***************/

/*************** FREE FUNCTIONS ***************/

static void delete (TreeNode * node) {

    if (node != NULL) {

        delete(node->left);
        delete(node->right);
        free(node);
    }
}

void tree_free (Tree * tree) {

    delete(tree->root);
    free(tree);
}

/*************** FREE FUNCTIONS ***************/

/*************** PRINT FUNCTIONS ***************/

static void print (TreeNode * node) {

    if (node != NULL) {

        printf("%d ", node->info);

        print(node->left);
        print(node->right);

    }
}

void tree_print (Tree * tree) {

    print(tree->root);
    printf("\n");

}

/*************** PRINT FUNCTIONS ***************/

/*************** SEARCH FUNCTIONS ***************/

static TreeNode * search (TreeNode * node, int info) {

    if (node == NULL) return NULL;
    else if (info < node->info) return search(node->left, info);
    else if (info > node->info) return search(node->right, info);
    else return node;

}

TreeNode * tree_search (Tree * tree, int info) {

    return search(tree->root, info);
}

/*************** SEARCH FUNCTIONS ***************/

/*************** BELONG FUNCTIONS ***************/

static int belong (TreeNode * node, int info) {

    if (node == NULL) return 0;
    else if (node->info == info || belong(node->left, info) || belong(node->right, info)) return 1;
}

int tree_belong (Tree * tree, int info) {

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