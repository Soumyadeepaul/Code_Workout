//https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/


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
    vector<int> store;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        store.push_back(root->val);
        inorder(root->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        inorder(root);
        vector<vector<int>> result;
        for(auto i:queries){
            auto it = lower_bound(store.begin(),store.end(),i)-store.begin();
            if(it>=store.size()){
                result.push_back({store[it-1],-1});
            }
            else if(store[it]==i){
                result.push_back({i,i});
            }
            else if(it==0){
                result.push_back({-1,store[it]});
            }
            else{
                result.push_back({store[it-1],store[it]});
            }
        }
        return result;
    }
};
