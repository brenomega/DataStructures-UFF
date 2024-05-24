#include "TAVL.h"

TAVL *TAVL_start(){
    return NULL;
}

TAVL *create(int info) {
    TAVL *tree = (TAVL*) malloc(sizeof(TAVL));

    if(!tree){
      fprintf (stderr, "Lack of memory!!! (insert)\n");
      exit(1);
    }

    tree->left = NULL;
    tree->right = NULL;
    tree->height = 0;
    tree->info = info;

    return tree;
}

int heightCalculate(TAVL *tree) {
    if(!tree) return -1;
    return tree->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

TAVL *rightR(TAVL *p) {
    TAVL *u = p->left;
    p->left = u->right;
    u->right = p;
    p->height = max(heightCalculate(p->left), heightCalculate(p->right)) + 1;
    u->height = max(heightCalculate(u->left), p->height) + 1;
    return u;
}

TAVL *leftR(TAVL *p) {
    TAVL *u = p->right;
    p->right = u->left;
    u->left = p;
    p->height = max(heightCalculate(p->left), heightCalculate(p->right)) + 1;
    u->height = max(p->height, heightCalculate(u->right)) + 1;
    return u;
}

TAVL *doubleRightR(TAVL *p) {
    p->left = leftR(p->left);
    return rightR(p);
}

TAVL *doubleLeftR(TAVL *p) {
    p->right = rightR(p->right);
    return leftR(p);
}

int BF(TAVL *tree) {
    return heightCalculate(tree->left) - heightCalculate(tree->right);
}

TAVL *TAVL_insert(TAVL *tree, int info) {
    if (!tree) {
        return create(info);
    }

    if (info < tree->info) {
        tree->left = TAVL_insert(tree->left, info);

        if (BF(tree) == 2) {
            if (info < tree->left->info) {
                tree = rightR(tree);
            } else if (info > tree->left->info) {
                tree = doubleRightR(tree);
            }
        }
    } else if (info > tree->info) {
        tree->right = TAVL_insert(tree->right, info);

        if (BF(tree) == -2) {
            if (info > tree->right->info) {
                tree = leftR(tree);
            } else if (info < tree->right->info) {
                tree = doubleLeftR(tree);
            }
        }
    }

    tree->height = max(heightCalculate(tree->left), heightCalculate(tree->right)) + 1;
    return tree;
}

TAVL *TAVL_remove(TAVL *tree, int info) {
    if (!tree) return NULL;

    if (info < tree->info) {
        tree->left = TAVL_remove(tree->left, info);
        if (BF(tree) == -2) {
            if (BF(tree->right) <= 0) {
                tree = leftR(tree);
            } else {
                tree = doubleLeftR(tree);
            }
        }
    } else if (info > tree->info) {
        tree->right = TAVL_remove(tree->right, info);
        if (BF(tree) == 2) {
            if (BF(tree->left) >= 0) {
                tree = rightR(tree);
            } else {
                tree = doubleRightR(tree);
            }
        }
    } else {
        if (tree->left) {
            TAVL *aux = tree->left;
            while(aux->right) aux = aux->right;
            tree->info = aux->info;
            tree->left = TAVL_remove(tree->left, aux->info);
            if (BF(tree) == -2) {
                if (BF(tree->right) <= 0) {
                    tree = leftR(tree);
                } else {
                    tree = doubleLeftR(tree);
                }
            }
        } else {
            TAVL *aux = tree;
            tree = tree->right;
            free(aux);
            return tree;
        }
    }

    tree->height = max(heightCalculate(tree->left), heightCalculate(tree->right)) + 1;
    return tree;
}

void TAVL_free(TAVL *tree) {
    if (tree) {
        TAVL_free(tree->left);
        TAVL_free(tree->right);
        free(tree);
    }
}

TAVL *TAVL_search(TAVL *tree, int info) {
    if (!tree) return NULL;
    if (info < tree->info) {
        return TAVL_search(tree->left, info);
    } else if (info > tree-> info) {
        return TAVL_search(tree->right, info);
    } else if (info == tree->info) {
        return tree;
    }
}

void printAux(TAVL *tree, int level){
    int j;
    if(tree){
        printAux(tree->right, level + 1);
        for (j = 0; j <= level; j++) printf("\t");
        printf("%d\n", tree->info);
        printAux(tree->left, level + 1);
    } else {
        for (j = 0; j <= level; j++) printf("\t");
        printf("N\n");
    }
}

void TAVL_print(TAVL *tree){
    printAux(tree, 0);
}
