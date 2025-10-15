//https://leetcode.com/problems/evaluate-boolean-binary-tree/description/


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
    bool postorder(TreeNode* parent){
        if(parent->left==nullptr && parent->right==nullptr){
            return parent->val;
        }
        else{
            int left=postorder(parent->left);
            int right=postorder(parent->right);
            if(parent->val==2){
                return left|right;
            }
            else{
                return left&right;
            }
        }
    }
    bool evaluateTree(TreeNode* root) {
        return postorder(root);
    }
};
