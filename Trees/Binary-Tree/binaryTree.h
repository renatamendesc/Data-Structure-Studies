#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct tree Tree;
typedef struct treeNode TreeNode;

Tree * tree_create (TreeNode * root);
TreeNode * tree_create_node (char c, TreeNode * left, TreeNode * right);

void tree_free (Tree * tree);
void tree_print (Tree * tree);

int tree_belong (Tree * tree, char c);

// TreeNode * tree_search (Tree * tree, char c);

// Adicionar funcao que calcula altura

#endif