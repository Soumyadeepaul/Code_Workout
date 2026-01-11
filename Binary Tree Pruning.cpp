//https://leetcode.com/problems/binary-tree-pruning/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* parent){
        if(parent){
            int left=0,right=0;
            left=helper(parent->left);
            right=helper(parent->right);
            if(left==0) parent->left=NULL;
            if(right==0) parent->right=NULL;
            return left+right+parent->val;
        }
        return 0;
    }
    TreeNode* pruneTree(TreeNode* root) {
        int dumm=helper(root);
        return (dumm==0)?NULL:root;
    }
};
