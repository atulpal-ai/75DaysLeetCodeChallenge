/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 * };
 */

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root == NULL) return false;
        
        // Leaf node
        if(root->left == NULL && root->right == NULL){
            return targetSum == root->val;
        }
        
        int remaining = targetSum - root->val;
        
        return hasPathSum(root->left, remaining) ||
               hasPathSum(root->right, remaining);
    }
};