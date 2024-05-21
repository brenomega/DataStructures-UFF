#include "TAB.h"

TAB *TAB_start(){
  return NULL;
}

TAB *TAB_create(int info, TAB *left, TAB *right){
  TAB *tree = (TAB *) malloc(sizeof(TAB));
  tree->info = info;
  tree->left = left;
  tree->right = right;
  return tree;
}

TAB *TAB_free(TAB *tree) {
    if(tree) {
        TAB_free(tree->left);
        TAB_free(tree->right);
        free(tree);
    }
}

TAB *TAB_search(TAB *tree, int info){
  if((!tree) || (tree->info == info)) return tree;
  TAB *temp = TAB_search(tree->left, info);
  if(temp) return temp;
  return TAB_search(tree->right, info);
}

// Aux function
int GT(int x, int y) {
    if (x >= y) return x;
    return y;
}

int TAB_height(TAB *tree) {
    if (!tree) return -1;
    return GT(TAB_height(tree->left), TAB_height(tree->right)) + 1;
}

void TAB_prePrint(TAB *tree) {
  if(tree){
    printf("%d ", tree->info);
    TAB_prePrint(tree->esq);
    TAB_prePrint(tree->dir);
  }
}

void TAB_posPrint(TAB *tree) {
  if(tree){
    TAB_posPrint(tree->esq);
    TAB_posPrint(tree->dir);
    printf("%d ", tree->info);
  }
}

void TAB_symPrint(TAB *tree) {
  if(tree){
    TAB_symPrint(tree->esq);
    printf("%d ", tree->info);
    TAB_symPrint(tree->dir);
  }
}