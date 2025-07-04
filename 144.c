
void preorder(struct TreeNode* node, int* result, int* count) {

    if (node == NULL) {
        return;
    }

    result[*count] = node->val;
    (*count)++;
    
    //esquerda
    preorder(node->left, result, count);
    
    //direita
    preorder(node->right, result, count);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
   
    int* result = (int*)malloc(100 * sizeof(int));
    *returnSize = 0; 
    
    preorder(root, result, returnSize);
    
    return result;
}