#include <stdio.h>
#include "TAB/TAB.c"

/*
Function, "arrayToBalancedTree", to transform a sorted array into a binary tree.
*/

TAB *arrayToBalancedTree(int *array, int length) {
    if (length <= 0) return NULL;
    int mid = length / 2;
    return TAB_create(array[mid], arrayToBalancedTree(array, mid), arrayToBalancedTree(&array[mid + 1], length - mid - 1));
}

TAB *TAB_arrayToBalancedTree(int *array) {
    int length = sizeof(array) / sizeof(array[0]);
    return arrayToTree(array, length);
}

int main() {
  int* array = {1,2,3,4,5,6,7};
  TAB *tree = TAB_arrayToBalancedTree(array);

  TAB_symPrint(tree);

  return 0;
}