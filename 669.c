
struct TreeNode* trimBST(struct TreeNode* root, int low, int high) {
    if (root == NULL) {
        return NULL;
    }
    //grande
    if (root->val > high) {
        return trimBST(root->left, low, high);
    }
    //pequeno
    if (root->val < low) {
        return trimBST(root->right, low, high);
    }
    //intervalo
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}