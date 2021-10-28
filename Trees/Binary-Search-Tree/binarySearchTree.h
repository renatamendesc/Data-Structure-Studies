#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct tree Tree;
typedef struct treeNode TreeNode;

Tree * tree_create ();

void tree_insert (Tree * tree, int info);
void tree_erase (Tree * tree, int info);

void tree_free (Tree * tree);
void tree_print (Tree * tree);
int tree_depth (Tree * tree);
// int tree_belong (Tree * tree, int info);

TreeNode * tree_search (Tree * tree, int info);

#endif