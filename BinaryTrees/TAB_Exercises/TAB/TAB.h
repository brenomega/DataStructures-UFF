#ifndef TAB_H_INCLUDED
#define TAB_H_INCLUDED

typedef int Logic;
#define TRUE 1
#define FALSE 0

typedef struct BinaryTree {
    int info;
    struct BinaryTree *left, *right;
} TAB;

TAB *TAB_start();
TAB *TAB_create(int info, TAB *left, TAB *right);
void TAB_free(TAB *tree);
TAB *TAB_search(TAB *tree, int info);
int TAB_height(TAB *tree);
void TAB_prePrint(TAB *tree);
void TAB_posPrint(TAB *tree);
void TAB_symPrint(TAB *tree);

#endif // TAB_H_INCLUDED