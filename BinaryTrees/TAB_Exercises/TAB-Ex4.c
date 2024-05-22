#include <stdio.h>
#include "TAB/TAB.c"

/*
5 functions, "leafNodes", "internalNodes", "oneChildNodes", "twoChildNodes" and "allNodes", to, respectively, 
return the number of leaf nodes, internal nodes, 1-child nodes, 2-child nodes and all nodes.
*/

int TAB_leafNodes(TAB *tree) {
    if (!tree) return 0;
    if (tree->left == NULL && tree->right == NULL) return 1;
    return TAB_leafNodes(tree->left) + TAB_leafNodes(tree->right);
}

int TAB_internalNodes(TAB *tree) {
    if (!tree) return 0;
    if (tree->left == NULL && tree->right == NULL) return 0;
    return TAB_internalNodes(tree->left) + TAB_internalNodes(tree->right) + 1;
}

int TAB_oneChildNodes(TAB *tree) {
    if (!tree) return 0;
    return TAB_oneChildNodes(tree->left) + TAB_oneChildNodes(tree->right) + (tree->left != NULL) ^ (tree->right != NULL);
}

int TAB_twoChildNodes(TAB *tree) {
    if (!tree) return 0;
    return TAB_twoChildNodes(tree->left) + TAB_twoChildNodes(tree->right) + (tree->left != NULL) && (tree->right != NULL);
}

int TAB_allNodes(TAB *tree) {
    if (!tree) return 0;
    return TAB_allNodes(tree->left) + TAB_allNodes(tree->right) + 1;
}

int main() {
  TAB *tree;

  tree = TAB_create(2,TAB_create(1,NULL,NULL),TAB_create(3,NULL,NULL));

  int a, b, c, d, e;

  a = TAB_leafNodes(tree);
  b = TAB_internalNodes(tree);
  c = TAB_oneChildNodes(tree);
  d = TAB_twoChildNodes(tree);
  e = TAB_allNodes(tree);

  print(a);
  print(b);
  print(c);
  print(d);
  print(e);

  return 0;
}
