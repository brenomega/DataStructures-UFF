#include <stdio.h>
#include "TAB/TAB.c"
  
/* 
function, "equals", to check whether two trees are equal.
*/

Logic TAB_equals(Tab *tree1, TAB *tree2) {
    if (!tree1 && !tree2) return TRUE;
    if (tree1 && tree2)
        return tree1->info == tree2->info && TAB_equals(tree1->left, tree2->left) && TAB_equals(tree1->right, tree2->right);
    return FALSE;
}

int main() {
  TAB *tree1, *tree2;

  tree1 = TAB_create(2,TAB_create(1,NULL,NULL),TAB_create(3,NULL,NULL));
  tree2 = TAB_create(2,TAB_create(1,NULL,NULL),TAB_create(3,NULL,NULL))

  print(TAB_equals(tree1, tree2));

  TAB_free(tree1);
  TAB_free(tree2);

  return 0;
}