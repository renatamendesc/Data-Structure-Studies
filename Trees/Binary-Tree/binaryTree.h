#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct tree Tree;
typedef struct treeNode TreeNode;

Tree * tree_create (TreeNode * root);
TreeNode * tree_create_node (char info, TreeNode * left, TreeNode * right);

void tree_free (Tree * tree);
void tree_print (Tree * tree);
int tree_belong (Tree * tree, char info);
int tree_depth (Tree * tree);

// TreeNode * tree_search (Tree * tree, char c);

#endif