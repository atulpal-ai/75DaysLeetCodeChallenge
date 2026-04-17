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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        // both null
        if(p == NULL && q == NULL) return true;
        
        // one null
        if(p == NULL || q == NULL) return false;
        
        // value mismatch
        if(p->val != q->val) return false;
        
        // recursive check
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};