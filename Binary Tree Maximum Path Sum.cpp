//https://leetcode.com/problems/binary-tree-maximum-path-sum/?envType=study-plan-v2&envId=top-interview-150

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
    int diameters(TreeNode *root,int &result,int sum){
        if(root==nullptr){//leaf
            return sum;
        }
        int left=0;
        left=diameters(root->left,result,left);
        int right=0;
        right=diameters(root->right,result,right);
        sum=max(left+root->val,right+root->val);
        sum=max(sum,root->val);
        result=max(result,left+root->val+right);
        result=max(result,sum);
        return sum;
    }
    int maxPathSum(TreeNode* root) {
        if(root==nullptr) return 0;
        int result=INT_MIN;
        int x=diameters(root,result,INT_MIN);
        return result;
    }
};
