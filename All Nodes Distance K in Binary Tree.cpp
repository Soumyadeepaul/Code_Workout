//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    stack<TreeNode *> parent;
    bool finder(TreeNode* prt, TreeNode* &target){
        if(prt==NULL) return false;
        if(target==prt) return true;
        parent.push(prt);
        if(finder(prt->left,target)) return true;
        if(finder(prt->right,target)) return true;
        parent.pop();
        return false;
    }
    vector<int> result;
    void below(TreeNode* prt, int k){
        if(prt==NULL) return;
        if(k==0){
            result.push_back(prt->val);
            return;
        }
        below(prt->left,k-1);
        below(prt->right,k-1);
    }

    void above(TreeNode* prt, int k){
        if(prt==NULL) return;
        if(k==0){
            result.push_back(prt->val);
            return;
        }
        above(prt->left,k-1);
        above(prt->right,k-1);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        finder(root,target);
        below(target,k);
        TreeNode* prev=target;
        while(!parent.empty()){
            TreeNode* prt=parent.top();
            if(prt->left==prev) prt->left=NULL;
            else prt->right=NULL;
            above(prt,--k);
            prev=prt;
            parent.pop();
        }
        return result;
    }
};
