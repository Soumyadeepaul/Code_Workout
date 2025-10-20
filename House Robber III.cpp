//https://leetcode.com/problems/house-robber-iii/description/


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
    pair<int,int> postOrder(TreeNode* root){
        if(root->left==nullptr && root->right==nullptr){
            return {root->val,0};
        }
        int taken1=0;
        int notTaken1=0;
        int taken2=0;
        int notTaken2=0;
        if(root->left!=nullptr){
            auto [taken,notTaken]=postOrder(root->left);
            taken1=taken;
            notTaken1=notTaken;
        }
        if(root->right!=nullptr){
            auto [taken,notTaken]=postOrder(root->right);
            taken2=taken;
            notTaken2=notTaken;
        }
        return {root->val+notTaken1+notTaken2,max(taken1,notTaken1)+max(taken2,notTaken2)};//imp
    }
    int rob(TreeNode* root) {
        auto [t1,t2]=postOrder(root);
        return max(t1,t2);
    }
};
