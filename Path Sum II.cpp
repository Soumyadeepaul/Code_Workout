//https://leetcode.com/problems/path-sum-ii/description/?envType=problem-list-v2&envId=backtracking



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
    void helper(TreeNode* p,int &t,vector<int> &r,vector<vector<int>> &result, int &summ){
        if(p->left==NULL && p->right==NULL){
            r.push_back(p->val);
            if(summ+p->val==t) result.push_back(r);
            r.pop_back();
            return;
        }
        r.push_back(p->val);
        summ+=p->val;
        if(p->left){
            helper(p->left,t,r,result,summ);
        }
        if(p->right){
            helper(p->right,t,r,result,summ);
        }
        r.pop_back();
        summ-=p->val;
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return {};
        vector<vector<int>> result;
        vector<int> r;
        int summ=0;
        helper(root,targetSum,r,result,summ);
        return result;
    }
};
