#include <stdio.h>
#include "TAB/TAB.c"

/*
Function, "maxSumHelper", to identify the value of the largest sum of paths in a tree.
*/

int maxPathSumHelper(TAB *tree, int sum) {
    if (!tree)
        return 0;

    sum += tree->info;

    if (!tree->left && !tree->right)
        return sum;

    int leftSum = maxPathSumHelper(tree->left, sum);
    int rightSum = maxPathSumHelper(tree->right, sum);

    if (leftSum > sum || rightSum > sum) return (leftSum > rightSum) ? leftSum : rightSum;
    return sum;
}

int maxPathSum(TAB *tree) {
    if (!tree) return 0;

    return maxPathSumHelper(tree, 0);
}

int main() {
  TAB *tree;

  tree = TAB_create(2,TAB_create(1,NULL,NULL),TAB_create(3,NULL,NULL));

  int maxPathSum = TAB_maxPathSum(tree);  

  print(maxPathSum);

  return 0;
}