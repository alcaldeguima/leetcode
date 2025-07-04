
void reverseInorder(struct TreeNode* node, int* cumulativeSum) {
    if (node == NULL) {
        return;
    }
    //direita
    reverseInorder(node->right, cumulativeSum);
    //raiz
    node->val += *cumulativeSum;
    //soma
    *cumulativeSum = node->val;
    //esquerda
    reverseInorder(node->left, cumulativeSum);
}


struct TreeNode* convertBST(struct TreeNode* root) {
    int cumulativeSum = 0;
    reverseInorder(root, &cumulativeSum);
    return root;
}