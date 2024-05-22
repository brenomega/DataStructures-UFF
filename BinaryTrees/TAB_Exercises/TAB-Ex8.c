#include <stdio.h>
#include "TAB/TAB.c"

/*
2 Functions, "max" and "min", to identify the node with the most and smallest information, respectively.
*/

TAB *TAB_max(TAB *tree) {
    if (!tree) return NULL;
    TAB *left = TAB_max(tree->left);
    TAB *right = TAB_max(tree->right);

    TAB *maxNode = tree;

    if (left && left->info > maxNode->info)
        maxNode = left;
    if (right && right->info > maxNode->info)
        maxNode = right;

    return maxNode;
}

TAB *TAB_min(TAB *tree) {
    if (!tree) return NULL;
    TAB *left = TAB_min(tree->left);
    TAB *right = TAB_min(tree->right);

    TAB *minNode = tree;

    if (left && left->info < minNode->info)
        minNode = left;
    if (right && right->info < minNode->info)
        minNode = right;

    return minNode;
}

int main() {
  TAB *tree;

  tree = TAB_create(2,TAB_create(1,NULL,NULL),TAB_create(3,NULL,NULL));

  int max = TAB_max(tree);
  int min = TAB_min(tree);  

  print(max->info);
  print(min->info);

  return 0;
}