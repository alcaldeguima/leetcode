#include <stdlib.h>
#include <math.h>

// retorna altura se balanceada, -1 se não
int alturaBalanceada(struct TreeNode* node) {
    if (node == NULL) return 0;
    int leftHeight = alturaBalanceada(node->left);
    if (leftHeight == -1) return -1;
    int rightHeight = alturaBalanceada(node->right);
    if (rightHeight == -1) return -1;
    if (abs(leftHeight - rightHeight) > 1) return -1;
    return 1 + fmax(leftHeight, rightHeight);
}

// Verifica se a árvore é balanceada
bool arvoreBalanceada(struct TreeNode* root) {
    return alturaBalanceada(root) != -1;
}