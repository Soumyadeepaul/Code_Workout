//https://leetcode.com/problems/longest-univalue-path/description/

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
    int algo(TreeNode* node,int &val,int count){
        if(node!=NULL && node->val==val){
            return max(algo(node->left,val,count+1),algo(node->right,val,count+1));
        }
        return count;
    }
    void preOrder(TreeNode* node,int &result){
        if(node!=NULL){
            int count=0;
            count=algo(node->left,node->val,count)+algo(node->right,node->val,count);
            result=max(result,count);
            preOrder(node->left,result);
            preOrder(node->right,result);
        }
    }
    int longestUnivaluePath(TreeNode* root) {
        int result=0;
        preOrder(root,result);
        return result;
    }
};
