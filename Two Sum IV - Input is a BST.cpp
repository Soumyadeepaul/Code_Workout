//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/


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
    unordered_set<int> req;
    bool preOrder(TreeNode* parent,int k){
        if(parent==NULL) return false;
        if(req.find(parent->val)!=req.end()) return true;
        req.insert(k-parent->val);
        if(preOrder(parent->left,k)) return true;
        if(preOrder(parent->right,k)) return true;
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        return preOrder(root,k);
    }
};
