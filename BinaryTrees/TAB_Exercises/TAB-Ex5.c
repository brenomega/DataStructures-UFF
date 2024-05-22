#include <stdio.h>
#include "TAB/TAB.c"

/*
Function, "isMirror", to identify whether a tree is a mirror of another.
*/

Logic TAB_isMirror(TAB *tree1, TAB *tree2) {
    if (!tree1 && !tree2) return TRUE;
    if (tree1 && tree2) {
        return tree1->info == tree2->info && TAB_isMirror(tree1->left, tree2->right) && TAB_isMirror(tree1->right, tree2->left);
    }
    return FALSE;
}

int main() {
  TAB *tree1, tree2;

  tree1 = TAB_create(2,TAB_create(1,NULL,NULL),TAB_create(3,NULL,NULL));
  tree2 = TAB_create(2,TAB_create(3,NULL,NULL),TAB_create(1,NULL,NULL));

  print(TAB_isMirror(tree1, tree2);

  return 0;
}
