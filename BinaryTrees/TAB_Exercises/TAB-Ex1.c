#include <stdio.h>
#include "TAB/TAB.c"

/*
Two functions, "copy" and "mirror" that generate a tree equal to the one passed as a
parameter and that generate a tree mirrored the one passed as a parameter, respectively.
*/


TAB *TAB_copy(TAB *tree) {
    if(!tree) return NULL;
    return TAB_create(tree->info, TAB_copy(tree->left), TAB_copy(tree->right));
}

TAB *TAB_mirror(TAB *tree) {
    if(!tree) return NULL;
    return TAB_create(tree->info, TAB_mirror(tree->right), TAB_mirror(tree->left));
}

int main() {
  TAB *tree, *copiedTree, *mirroredTree;

  tree = TAB_create(2,TAB_create(1,NULL,NULL),TAB_create(3,NULL,NULL));

  copiedTree = TAB_copy(tree);
  TAB_symPrint(copiedTree);

  mirroredTree = TAB_mirror(tree);
  TAB_symPrint(mirroredTree);

  TAB_free(tree);
  TAB_free(copiedTree);
  TAB_free(mirroredTree);

  return 0;
}
