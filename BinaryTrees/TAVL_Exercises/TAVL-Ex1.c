void TAVL_split(TAVL *root, int key, TAVL **leftTree, TAVL **rightTree) {
    if (!root) {
        *leftTree = NULL;
        *rightTree = NULL;
        return;
    }

    if (key <= root->info) {
        *rightTree = root;
        TAVL_split(root->left, key, leftTree, &(*rightTree)->left);
	TAVL_split(root->right, key, leftTree, &(*rightTree)->right);
        if (BF(*rightTree) == 2) {
            if (BF((*rightTree)->left) >= 0) {
                *rightTree = rightR(*rightTree);
            } else {
                *rightTree = doubleRightR(*rightTree);
            }
        }
    } else {
        *leftTree = root;
        TAVL_split(root->right, key, &(*leftTree)->right, rightTree);
	TAVL_split(root->left, key, &(*leftTree)->left, rightTree);
        if (BF(*leftTree) == -2) {
            if (BF((*leftTree)->right) <= 0) {
                *leftTree = leftR(*leftTree);
            } else {
                *leftTree = doubleLeftR(*leftTree);
            }
        }
    }

    if (*leftTree) {
        (*leftTree)->height = max(heightCalculate((*leftTree)->left), heightCalculate((*leftTree)->right)) + 1;
    }
    if (*rightTree) {
        (*rightTree)->height = max(heightCalculate((*rightTree)->left), heightCalculate((*rightTree)->right)) + 1;
    }
}