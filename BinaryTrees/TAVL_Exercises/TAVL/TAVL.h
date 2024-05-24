#ifndef TAVL_H_INCLUDED
#define TAVL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct AVLBinaryTree {
    int info;
    struct AVLBinaryTree *left, *right;
    int height;
} TAVL;

TAVL *TAVL_start();
TAVL *TAVL_insert(TAVL *tree, int info);
TAVL *TAVL_remove(TAVL *tree, int info);
void TAVL_free(TAVL *tree);
TAVL *TAVL_search(TAVL *tree, int info);
void TAVL_print(TAVL *tree);

#endif // TAVL_H_INCLUDED
