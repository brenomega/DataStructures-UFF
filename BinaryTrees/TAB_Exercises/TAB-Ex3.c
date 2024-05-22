#include <stdio.h>
#include "TAB/TAB.c"

/*
function, "removeEven", to remove all nodes with even information.
*/

TAB *TAB_removeEven(TAB *tree) {
    if (!tree)
        return NULL;

    tree->left = TAB_removeEven(tree->left);
    tree->right = TAB_removeEven(tree->right);

    if (tree->info % 2 == 0) {
        // Case 1: No Children
        if (!tree->left && !tree->right) {
            free(tree);
            tree = TAB_start();
        // Case 2: 1 Child
        } else if (!tree->left || !tree->right) {
            TAB *aux = tree;
            if(tree->left) tree = tree->left;
            if(tree->right) tree = tree->right;
            free(aux);
        // Case 3: 2 Children
        } else if (tree->left && tree->right) {
            TAB *aux = tree->left;
            while(aux->right) {
                aux = aux->right;
            }
            int temp = tree->info;
            tree->info = aux->info;
            aux->info = temp;
            tree = TAB_removeEven(tree);
        }
    }
    return tree;
}

int main() {
  TAB *tree;

  tree = TAB_create(2,TAB_create(1,NULL,NULL),TAB_create(3,NULL,NULL));

  tree = TAB_removeEven(tree);

  TAB_symPrint(tree);

  TAB_free(tree);

  return 0;
}
