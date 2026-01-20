//https://leetcode.com/problems/convert-bst-to-greater-tree/description/?envType=problem-list-v2&envId=binary-search-tree


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
    void inorderR(TreeNode* root,int &summ){
        if(root){
            inorderR(root->right,summ);
            int temp=root->val;
            root->val=summ+temp;
            summ+=temp;
            inorderR(root->left,summ);
            
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        int summ=0;
        inorderR(root,summ);
        return root;
    }
};
