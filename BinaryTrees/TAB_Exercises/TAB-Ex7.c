#include <stdio.h>
#include "TAB/TAB.c"

/*
Function, "maxWidth", to identify the extent of the tree's width.
*/

void getWidths(TAB *tree, int level, int *widths) {

    if (tree) {
        widths[level]++;
        getWidths(tree->left, level + 1, widths);
        getWidths(tree->right, level + 1, widths);
    }
}

int TAB_maxWidth(TAB *tree) {
    int height = TAB_height(tree);
    int *widths = (int *) calloc(height, sizeof(int))

    getWidths(tree, 0, widths);

    int maxWidth = 0;
    for (int i = 0; i < height; i++) {
        if (widths[i] > maxWidth)
            maxWidth = widths[i];
    }

    free(widths);
    return maxWidth;
}

int main() {
  TAB *tree;

  tree = TAB_create(2,TAB_create(1,NULL,NULL),TAB_create(3,NULL,NULL));

  int maxWidth = TAB_maxWidth(tree);  

  print(maxWidth);

  return 0;
}