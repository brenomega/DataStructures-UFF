#include <stdio.h>
#include "TAB/TAB.c"

/*
Function, "closestCommonAncestor", to find the closest common ancestor between two nodes in a tree.
*/

TAB *TAB_closestCommonAncestor(TAB tree, TAB *node1, TAB *node2) {
    if (!tree || tree == node1 || tree == node2) return tree;

    TAB *left = TAB_closestCommonAncestor(tree->left, node1, node2);
    TAB *right = TAB_closestCommonAncestor(tree->right, node1, node2);

    if (left && right) return tree;
    return (left != NULL) ? left : right;
}

int main() {
  TAB *tree, node1, node2, ancestor;

  node1 = TAB_create(1,NULL,NULL);
  node2 = TAB_create(3,NULL,NULL);
  tree = TAB_create(2,node1,node2);

  ancestor = TAB_closestCommonAncestor(tree, node1, node2);

  TAB_symPrint(ancestor);

  return 0;
}