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
    TreeNode* invertTree(TreeNode* root) {
        
        if(root == NULL) return NULL;
        
        // swap left and right
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        // recursive calls
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};