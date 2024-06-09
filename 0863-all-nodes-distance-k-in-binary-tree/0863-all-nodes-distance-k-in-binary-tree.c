/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void addBelowTarget(struct TreeNode *root, int k, int depth, int *res, int *ridx);
int addAboveTarget(struct TreeNode *root, int k, int target, int depth,  int *res, int *ridx);

int* distanceK(struct TreeNode* root, struct TreeNode* target, int k, int* returnSize) {
        int *res = (int *)calloc(k * 3 + 50, sizeof(int));
    int ridx = 0;
    int depth = 0; 
    addBelowTarget(target, k, depth, res, &ridx); 
    if(k != 0)
        addAboveTarget(root, k, target->val, depth, res, &ridx); 
    *returnSize = ridx; 
    return res; 
}

void addBelowTarget(struct TreeNode *root, int k, int depth, int *res, int *ridx){
    if(root == NULL || depth > k){
        return;
    }
    if(depth == k){
        res[(*ridx)++] = root->val; 
        return;
    }
    addBelowTarget(root->left, k, depth + 1, res, ridx);
    addBelowTarget(root->right, k, depth + 1, res, ridx);
    
}   

int addAboveTarget(struct TreeNode *root, int k, int target, int depth,  int *res, int *ridx){
    if(root == NULL || depth > k)
        return 0;
    if(root->val == target)
        return 1;
    int left = addAboveTarget(root->left, k, target, depth, res, ridx);
    int right = addAboveTarget(root->right, k, target, depth, res, ridx);
    if(left == k || right == k)
        res[(*ridx)++] = root->val; 
    if(left >= 1)
        addBelowTarget(root->right, k, left + 1, res, ridx);
    if(right >= 1)
        addBelowTarget(root->left, k, right + 1, res, ridx);
    return right + left > 0 ? left + right + 1 : 0; 
    
}